#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_

#include <string>
#include <utility>
#include "employee_enums.hpp"

namespace employee {
struct Employee {
    // BAD IDEA: not everyone is identified by a first and a last name: https://github.com/kdeldycke/awesome-falsehood#human-identity
    std::string first_name;
    std::string last_name;

protected:  // !
    explicit Employee(std::string first_name_,
                      std::string last_name_)  // explicit!
        : first_name(std::move(first_name_)), last_name(std::move(last_name_)) {
    }
};

struct Developer {
    std::string first_name;
    std::string last_name;
    ProgrammingLanguage language;
    std::string github_handle;

    explicit Developer(std::string first_name_,
                       std::string last_name_,
                       ProgrammingLanguage language_,
                       std::string github_handle_)  // explicit!
        : first_name(std::move(first_name_)),
          last_name(std::move(last_name_)),
          language(language_),
          github_handle(std::move(github_handle_)) {
    }
};

struct SalesManager {
    std::string first_name;
    std::string last_name;
    Region region;

    explicit SalesManager(std::string first_name_,
                          std::string last_name_,
                          Region region_)  // explicit!
        : first_name(std::move(first_name_)),
          last_name(std::move(last_name_)),
          region(region_) {
    }
};
}  // namespace employee

#endif  // EMPLOYEE_HPP_
