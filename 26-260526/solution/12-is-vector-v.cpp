#include <type_traits>
#include <string>
#include <vector>

template<typename T>
struct is_vector : std::false_type {};

template<typename T>
struct is_vector<std::vector<T>> : std::true_type {};

template<typename T>
constexpr bool is_vector_v = is_vector<T>::value;

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
