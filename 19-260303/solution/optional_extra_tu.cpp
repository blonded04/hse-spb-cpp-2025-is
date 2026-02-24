#include <memory>
#include <string>
#include "optional.hpp"  // Ensure that including the header in a separate TU does not induce ODR violation.
#include "optional.hpp"  // Ensure that double inclusion does not break anything.

namespace {
[[maybe_unused]] ex_optional::optional<std::string> opt_string;
[[maybe_unused]] ex_optional::optional<int> opt_int;
[[maybe_unused]] ex_optional::optional<std::unique_ptr<int>> opt_pint;
}  // namespace