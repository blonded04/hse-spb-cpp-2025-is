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
    explicit Employee();  // Should never be called.
    explicit Employee(std::string full_name_, int base_salary_usd_per_year_)
        : full_name(std::move(full_name_))
        , base_salary_usd_per_year(base_salary_usd_per_year_) {}
};

struct Developer : virtual Employee {
    std::string github_account;

    explicit Developer(std::string full_name_,
                       int base_salary_usd_per_year_,
                       std::string github_account_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , github_account(std::move(github_account_)) {}

    [[nodiscard]] int salary_usd_per_year() const override {
        return base_salary_usd_per_year +
               static_cast<int>(github_account.length()) * 100;        
    }

protected:
    explicit Developer(std::string github_account_)
        : github_account(std::move(github_account_)) {}
};

struct Manager : virtual Employee {
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

protected:
    explicit Manager(std::string project_name_)
        : project_name(std::move(project_name_)) {}
};

struct LeadDeveloper final : Developer, Manager {
    explicit LeadDeveloper(std::string full_name_,
                           int base_salary_usd_per_year_,
                           std::string github_account_,
                           std::string project_name_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , Developer(std::move(github_account_))
        , Manager(std::move(project_name_)) {}

    [[nodiscard]] int salary_usd_per_year() const override {
        return base_salary_usd_per_year +
               static_cast<int>(github_account.length()) * 150 +
               static_cast<int>(project_name.length()) * 80;
    }
};
}  // namespace employees

#define TEST_EMPLOYEES_BASIC
#define TEST_EMPLOYEES_MULTIPLE_INHERITANCE
#define TEST_EMPLOYEES_NICE_CONSTRUCTORS
#include "employees_test.inc.cpp"
