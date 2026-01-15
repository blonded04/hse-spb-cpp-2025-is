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

struct AbstractDeveloper : virtual Employee {
    std::string github_account;

    explicit AbstractDeveloper(std::string full_name_,
                       int base_salary_usd_per_year_,
                       std::string github_account_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , github_account(std::move(github_account_)) {}
};

struct AbstractManager : virtual Employee {
    std::string project_name;

    explicit AbstractManager(std::string full_name_,
                     int base_salary_usd_per_year_,
                     std::string project_name_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , project_name(std::move(project_name_)) {}
};

struct Developer : virtual AbstractDeveloper {  // 'virtual' is technically optional here, but preferred for all interfaces
    int level;

    explicit Developer(std::string full_name_,
                       int base_salary_usd_per_year_,
                       std::string github_account_,
                       int level_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , AbstractDeveloper("", 0, std::move(github_account_))
        , level(level_) {}

    [[nodiscard]] int salary_usd_per_year() const override {
        return base_salary_usd_per_year +
               static_cast<int>(github_account.length()) * 100;        
    }
};

struct Manager : virtual AbstractManager {  // 'virtual' is technically optional here, but preferred for all interfaces
    explicit Manager(std::string full_name_,
                     int base_salary_usd_per_year_,
                     std::string project_name_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , AbstractManager("", 0, std::move(project_name_)) {}

    [[nodiscard]] int salary_usd_per_year() const override {
        return base_salary_usd_per_year +
               static_cast<int>(project_name.length()) * 100;
    }
};

struct LeadDeveloper final : virtual AbstractDeveloper, virtual AbstractManager {  // 'virtual' is technically optional here, but preferred for all interfaces
    explicit LeadDeveloper(std::string full_name_,
                           int base_salary_usd_per_year_,
                           std::string github_account_,
                           std::string project_name_)
        : Employee(std::move(full_name_), base_salary_usd_per_year_)
        , AbstractDeveloper("", 0, std::move(github_account_))
        , AbstractManager("", 0, std::move(project_name_)) {}

    [[nodiscard]] int salary_usd_per_year() const override {
        return base_salary_usd_per_year +
               static_cast<int>(github_account.length()) * 150 +
               static_cast<int>(project_name.length()) * 80;
    }
};
}  // namespace employees

#define TEST_EMPLOYEES_BASIC
#define TEST_EMPLOYEES_MULTIPLE_INHERITANCE
#define TEST_EMPLOYEES_LEVEL
#define TEST_EMPLOYEES_ABSTRACT_BASE_CLASSES
#include "employees_test.inc.cpp"
