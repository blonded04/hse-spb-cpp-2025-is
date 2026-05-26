#include <type_traits>
#include <string>
#include <vector>

// TODO: implement is_vector<T> and is_vector_v<T>.
// Inherit std::integral_constant and/or std::false_type/std::true_type so all members are implemented according to C++ customs.

static_assert(!is_vector_v<int>);
static_assert(!is_vector_v<char>);
static_assert(is_vector_v<std::vector<int>>);
static_assert(is_vector_v<std::vector<char>>);
static_assert(!is_vector_v<std::string>);

static_assert(std::is_same_v<bool, is_vector<int>::value_type>);
static_assert(std::is_same_v<bool, is_vector<char>::value_type>);
static_assert(std::is_same_v<bool, is_vector<std::vector<int>>::value_type>);
static_assert(std::is_same_v<bool, is_vector<std::vector<char>>::value_type>);
static_assert(std::is_same_v<bool, is_vector<std::string>::value_type>);

static_assert(!is_vector<int>{}());
static_assert(!is_vector<char>{}());
static_assert(is_vector<std::vector<int>>{}());
static_assert(is_vector<std::vector<char>>{}());
static_assert(!is_vector<std::string>{}());

int main() {
}
