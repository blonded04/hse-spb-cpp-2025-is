#include <string>
#include <utility>
#include <vector>

namespace employees {
struct Employee {
    std::string full_name;
    int base_salary_usd_per_year;

    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee &operator=(Employee &&) = delete;
    virtual ~Employee() = default;

    [[nodiscard]] virtual int salary_usd_per_year() const = 0;

protected:
    explicit Employee(std::string full_name_, int base_salary_usd_per_year_)
        : full_name(std::move(full_name_))
        , base_salary_usd_per_year(base_salary_usd_per_year_) {}
};

// TODO START
struct Developer final : Employee {
    std::string github_account;
    int level;

    explicit Developer(std::string full_name_,
                       int base_salary_usd_per_year_,
                       std::string github_account_,
                       int level_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , github_account(std::move(github_account_))
        , level(level_) {}

    [[nodiscard]] int salary_usd_per_year() const override {
        return base_salary_usd_per_year +
               static_cast<int>(github_account.length()) * 100;        
    }
};

struct Manager final : Employee {
    std::string project_name;

    explicit Manager(std::string full_name_,
                     int base_salary_usd_per_year_,
                     std::string project_name_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , project_name(std::move(project_name_)) {}

    [[nodiscard]] int salary_usd_per_year() const override {
        return base_salary_usd_per_year +
               static_cast<int>(project_name.length()) * 100;
    }
};

struct LeadDeveloper final : Employee {
    std::string github_account;
    std::string project_name;

    explicit LeadDeveloper(std::string full_name_,
                           int base_salary_usd_per_year_,
                           std::string github_account_,
                           std::string project_name_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , github_account(std::move(github_account_))
        , project_name(std::move(project_name_)) {}

    [[nodiscard]] int salary_usd_per_year() const override {
        return base_salary_usd_per_year +
               static_cast<int>(github_account.length()) * 150 +
               static_cast<int>(project_name.length()) * 80;
    }
};
// TODO END
}  // namespace employees

#define TEST_EMPLOYEES_BASIC
// #define TEST_EMPLOYEES_MULTIPLE_INHERITANCE  // TODO: start with your 01-employees.cpp
#define TEST_EMPLOYEES_LEVEL
// #define TEST_EMPLOYEES_ABSTRACT_BASE_CLASSES  // TODO: uncomment and make sure `Developer` is not a base of `LeadDeveloper` with abstract base classes
#include "employees_test.inc.cpp"
