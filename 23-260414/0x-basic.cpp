#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

// see https://en.cppreference.com/w/cpp/algorithm/

void incrementEach(std::vector<int>& v) {
    // TODO: increment each vector element by one using only standard library functions
}

void incrementEach_test() {
    std::vector<int> exercise1_test1_input    = {1, 2, 3, 4, 2};
    std::vector<int> exercise1_test1_expected = {2, 3, 4, 5, 3};
    incrementEach(exercise1_test1_input);
    assert(exercise1_test1_expected.size() == exercise1_test1_input.size());
    assert(std::equal(exercise1_test1_input.begin(), exercise1_test1_input.end(), exercise1_test1_expected.begin()));
    for (int e : exercise1_test1_input) {
        std::cout << e << '\n';
    }
}

void generateRandom(std::vector<int>& v) {
    // TODO: set each value in this vector to a random value
}

void generateRandom_test() {
    std::vector<int> v(10, 0);
    generateRandom(v);
    assert(v.size() == 10);
    for (int e : v) {
        assert(e != 0);
        std::cout << e << '\n';
    }
}

void pivotModuloTwo(std::vector<int>& v) {
    // TODO: shuffle vector elements in a way that even and odd elements are pivoted
}

void pivotModuloTwo_test() {
    std::vector<int> v = {10, 3, 4, 5, 61, 124532, 54539, 94, 21, 43, 6};
    std::vector<int> v_copy = v;
    pivotModuloTwo(v);
    
    assert(v.size() == v_copy.size());
    bool seen_odd = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 1) {
            seen_odd = true;
        }
        assert((!seen_odd && v[i] % 2 == 0) || (seen_odd && v[i] % 2 == 1));
    }
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << '\n';
    }
}

void leaveOnlyUnique(std::vector<int>& v) {
    // TODO: remove duplicates
}

void leaveOnlyUnique_test() {
    std::vector<int> v = {3, 3, 4, 4, 1, 1, 1, 1, 2, 1};
    leaveOnlyUnique(v);
    assert(v.size() == 4);
    assert(std::find(v.begin(), v.end(), 1) != v.end());
    assert(std::find(v.begin(), v.end(), 2) != v.end());
    assert(std::find(v.begin(), v.end(), 3) != v.end());
    assert(std::find(v.begin(), v.end(), 4) != v.end());
    for (int e : v) {
        std::cout << e << '\n';
    }
}

void stdoutOneliner(std::vector<int>& v) {
    // TODO: print vector to stdout with no for-loop or for each
    // see https://en.cppreference.com/w/cpp/iterator/ostream_iterator
}

void stdoutOneliner_test() {
    std::vector<int> v = {4, 3, 2, 5};
    stdoutOneliner(v);
}

void allPermutations(std::vector<int>& v) {
    // TODO: print all combinatoric permutations of vector elements, total of O((v.size())!) vectors outputted
}

void allPermutations_test() {
    std::vector<int> v = {2, 1, 3};
    allPermutations(v);
}

// TODO: for exercises 07 through 10 write tests by yourself

int main() {
    // TODO: uncomment tests as you go

    // incrementEach_test();
    // std::cout << '\n';

    // generateRandom_test();
    // std::cout << '\n';

    // pivotModuloTwo_test();
    // std::cout << '\n';

    // leaveOnlyUnique_test();
    // std::cout << '\n';

    // stdoutOneliner_test();
    // std::cout << '\n';

    // allPermutations_test();
    // std::cout << '\n';
}
