#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_

#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include "employee_enums.hpp"

namespace employee {
struct Employee {
    // BAD IDEA: not everyone is identified by a first and a last name: https://github.com/kdeldycke/awesome-falsehood#human-identity
    std::string first_name;
    std::string last_name;

protected:  // !
    Employee(const Employee &) = default;
    Employee(Employee &&) = default;
    Employee &operator=(const Employee &) = default;
    Employee &operator=(Employee &&) = default;

public:
    virtual ~Employee() = default;

    friend std::ostream &operator<<(std::ostream &os, const Employee &e) {
        e.printTo(os);
        return os;
    }

    // private:  // В учебной обстановке printTo() тестируется отдельно и должен
    // быть публичным.
    virtual void printTo(std::ostream &) const = 0;  // = 0!

    static std::unique_ptr<Employee> readFrom(std::istream &is);

protected:  // !
    explicit Employee(std::string first_name_,
                      std::string last_name_)  // explicit!
        : first_name(std::move(first_name_)), last_name(std::move(last_name_)) {
    }
};

struct Developer : Employee {
    ProgrammingLanguage language;
    std::string github_handle;

    explicit Developer(std::string first_name_,
                       std::string last_name_,
                       ProgrammingLanguage language_,
                       std::string github_handle_)  // explicit!
        : Employee(std::move(first_name_), std::move(last_name_)),
          language(language_),
          github_handle(std::move(github_handle_)) {
    }

    static Developer readFrom(std::istream &is);

    // private:
    void printTo(std::ostream &os) const override;
};

struct SalesManager : Employee {
    Region region;

    explicit SalesManager(std::string first_name_,
                          std::string last_name_,
                          Region region_)  // explicit!
        : Employee(std::move(first_name_), std::move(last_name_)),
          region(region_) {
    }

    static SalesManager readFrom(std::istream &is);

    // private:
    void printTo(std::ostream &os) const override;
};
}  // namespace employee

#endif  // EMPLOYEE_H_
