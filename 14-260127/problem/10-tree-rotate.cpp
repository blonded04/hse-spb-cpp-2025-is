#include <cassert>
#include <iostream>
#include <memory>

// TODO: replace raw pointers with unique_ptr and fix all bugs.
struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode(TreeNode *left_, int data_, TreeNode *right_)
        : data(data_)
        , left(left_)
        , right(right_) {
    }

    TreeNode* clone() const;

    ~TreeNode() {
        // `delete nullptr` is ok.
        delete left;
        delete right;
    }
};

std::ostream &operator<<(std::ostream &os, TreeNode *n) {
    if (!n) {
        return os << "nullptr";
    }
    return os << "{" << n->left << " " << n->data << " " << n->right << "}";
}

TreeNode *make(TreeNode *left, int data, TreeNode *right) {
    return new TreeNode(left, data, right);
}

TreeNode *TreeNode::clone() const {
    return make(left->clone(), data, right->clone());
}

auto make(int data) {
    return make(nullptr, data, nullptr);
}

// https://en.wikipedia.org/wiki/AVL_tree#Simple_rotation
auto rotate_left(TreeNode *x) {
    assert(x && x->right);
    x->right = x->right->left;
    x->right->left = x;
    return x->right;
}

auto rotate_right(TreeNode* x) {
    assert(x && x->left);
    x->left = x->left->right;
    x->left->right = x;
    return x->left;
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
