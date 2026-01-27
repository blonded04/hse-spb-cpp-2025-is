#include <cassert>
#include <iostream>
#include <memory>
#include <utility>

struct TreeNode {
    int data;
    std::unique_ptr<TreeNode> left, right;

    TreeNode(std::unique_ptr<TreeNode> left_, int data_, std::unique_ptr<TreeNode> right_)
        : data(data_)
        , left(std::move(left_))
        , right(std::move(right_)) {
    }

    std::unique_ptr<TreeNode> clone() const;
};

std::ostream &operator<<(std::ostream &os, const std::unique_ptr<TreeNode> &n) {
    if (!n) {
        return os << "nullptr";
    }
    return os << "{" << n->left << " " << n->data << " " << n->right << "}";
}

std::unique_ptr<TreeNode> make(std::unique_ptr<TreeNode> left, int data, std::unique_ptr<TreeNode> right) {
    return std::make_unique<TreeNode>(std::move(left), data, std::move(right));
}

std::unique_ptr<TreeNode> TreeNode::clone() const {
    return make(left ? left->clone() : nullptr, data, right ? right->clone() : nullptr);
}

auto make(int data) {
    return make(nullptr, data, nullptr);
}

// https://en.wikipedia.org/wiki/AVL_tree#Simple_rotation
auto rotate_left(std::unique_ptr<TreeNode> x) {
    assert(x && x->right);
    auto y = std::move(x->right);
    x->right = std::move(y->left);
    y->left = std::move(x);
    return y;
}

auto rotate_right(std::unique_ptr<TreeNode> x) {
    assert(x && x->left);
    auto y = std::move(x->left);
    x->left = std::move(y->right);
    y->right = std::move(x);
    return y;
}

int main() {
    auto tree = make(
        make(make(1), 2, make(3)),
        10,
        make(
            make(make(11), 12, make(13)),
            20,
            make(make(21), 22, make(23))
        )
    );
    auto before_rotation = tree->clone();
    auto after_rotation = make(
        make(
            make(make(1), 2, make(3)),
            10,
            make(make(11), 12, make(13))
        ),
        20,
        make(make(21), 22, make(23))
    );
    tree = rotate_left(std::move(tree));
    // Should print the same.
    std::cout << tree << "\n";
    std::cout << after_rotation << "\n";

    tree = rotate_right(std::move(tree));
    // Should print the same.
    std::cout << tree << "\n";
    std::cout << before_rotation << "\n";
}
