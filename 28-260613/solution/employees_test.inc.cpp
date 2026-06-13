#include <string>
#include <vector>
#include <type_traits>
#include <iostream>  // https://github.com/onqtam/doctest/issues/356
#include "doctest.h"

#ifndef TEST_EMPLOYEES_BASIC
#error This file should be included by *.cpp, it is not a separate translation unit
#endif

#ifdef TEST_EMPLOYEES_SAVE
static_assert(std::is_same_v<employees::Employee::FieldStorage, std::vector<std::pair<std::string, std::string>>>);

namespace doctest {
template<> struct StringMaker<employees::Employee::FieldStorage> {
    static String convert(const employees::Employee::FieldStorage &fs) {
        String s;
        s += "{";
        bool first = true;
        for (const auto &[key, value] : fs) {
            if (!first) {
                s += ",";
            }
            first = false;
            s += toString(key);
            s += "->";
            s += toString(value);
        }
        s += "}";
        return s;
    }
};
}
#endif

TEST_CASE("Developer") {
#ifdef TEST_EMPLOYEES_SAVE
    const employees::Employee::FieldStorage saved{
        {"full_name", "Ivan Ivanov"},
        {"base_salary_usd_per_year", "100000"},
        {"salary_usd_per_year", "101000"},
        {"github_account", "ivanivanov"},
#ifdef TEST_EMPLOYEES_LEVEL
        {"level", 6},
#endif
    };
#endif

    auto check_employee = [&](const employees::Employee &e) {
        CHECK(e.full_name == "Ivan Ivanov");
        CHECK(e.base_salary_usd_per_year == 100'000);
        CHECK(e.salary_usd_per_year() == 101'000);
#ifdef TEST_EMPLOYEES_SAVE
        CHECK(e.save() == saved);
#endif
    };

#ifndef TEST_EMPLOYEES_LEVEL
    const employees::Developer d("Ivan Ivanov", 100'000, "ivanivanov");
#else
    const employees::Developer d("Ivan Ivanov", 100'000, "ivanivanov", 6);
#endif
    check_employee(d);
    CHECK(d.full_name == "Ivan Ivanov");
    CHECK(d.base_salary_usd_per_year == 100'000);
    CHECK(d.salary_usd_per_year() == 101'000);
#ifdef TEST_EMPLOYEES_SAVE
    CHECK(d.save() == saved);
#endif

    CHECK(d.github_account == "ivanivanov");
#ifdef TEST_EMPLOYEES_LEVEL
    CHECK(d.level == 6);
#endif
}

TEST_CASE("Manager") {
#ifdef TEST_EMPLOYEES_SAVE
    const employees::Employee::FieldStorage saved{
        {"full_name", "Ivan Ivanov"},
        {"base_salary_usd_per_year", "100000"},
        {"salary_usd_per_year", "100400"},
        {"project_name", "proj"},
    };
#endif

    auto check_employee = [&](const employees::Employee &e) {
        CHECK(e.full_name == "Ivan Ivanov");
        CHECK(e.base_salary_usd_per_year == 100'000);
        CHECK(e.salary_usd_per_year() == 100'400);
#ifdef TEST_EMPLOYEES_SAVE
        CHECK(e.save() == saved);
#endif
    };

    const employees::Manager m("Ivan Ivanov", 100'000, "proj");
    check_employee(m);
    CHECK(m.full_name == "Ivan Ivanov");
    CHECK(m.base_salary_usd_per_year == 100'000);
    CHECK(m.salary_usd_per_year() == 100'400);
#ifdef TEST_EMPLOYEES_SAVE
    CHECK(m.save() == saved);
#endif

    CHECK(m.project_name == "proj");
}

TEST_CASE("LeadDeveloper") {
#ifdef TEST_EMPLOYEES_SAVE
    const employees::Employee::FieldStorage saved{
        {"full_name", "Ivan Ivanov"},
        {"base_salary_usd_per_year", "100000"},
        {"salary_usd_per_year", "101820"},
        {"github_account", "ivanivanov"},
        {"project_name", "proj"},
    };
#endif

    auto check_employee = [&](const employees::Employee &e) {
        CHECK(e.full_name == "Ivan Ivanov");
        CHECK(e.base_salary_usd_per_year == 100'000);
        CHECK(e.salary_usd_per_year() == 101'820);
#ifdef TEST_EMPLOYEES_SAVE
        CHECK(e.save() == saved);
#endif
    };

#ifdef TEST_EMPLOYEES_MULTIPLE_INHERITANCE
#ifndef TEST_EMPLOYEES_ABSTRACT_BASE_CLASSES
    auto check_developer = [&](const employees::Developer &d) {
#else
    auto check_developer = [&](const employees::AbstractDeveloper &d) {
#endif
        check_employee(d);
        CHECK(d.full_name == "Ivan Ivanov");
        CHECK(d.base_salary_usd_per_year == 100'000);
        CHECK(d.salary_usd_per_year() == 101'820);
#ifdef TEST_EMPLOYEES_SAVE
        CHECK(d.save() == saved);
#endif

        CHECK(d.github_account == "ivanivanov");
    };

#ifndef TEST_EMPLOYEES_ABSTRACT_BASE_CLASSES
    auto check_manager = [&](const employees::Manager &m) {
#else
    auto check_manager = [&](const employees::AbstractManager &m) {
#endif
        check_employee(m);
        CHECK(m.full_name == "Ivan Ivanov");
        CHECK(m.base_salary_usd_per_year == 100'000);
        CHECK(m.salary_usd_per_year() == 101'820);
#ifdef TEST_EMPLOYEES_SAVE
        CHECK(m.save() == saved);
#endif

        CHECK(m.project_name == "proj");
    };
#endif

    const employees::LeadDeveloper ld("Ivan Ivanov", 100'000, "ivanivanov", "proj");
    check_employee(ld);
#ifdef TEST_EMPLOYEES_MULTIPLE_INHERITANCE
    check_developer(ld);
    check_manager(ld);
#endif
    CHECK(ld.full_name == "Ivan Ivanov");
    CHECK(ld.base_salary_usd_per_year == 100'000);
    CHECK(ld.salary_usd_per_year() == 101'820);
#ifdef TEST_EMPLOYEES_SAVE
    CHECK(ld.save() == saved);
#endif

    CHECK(ld.github_account == "ivanivanov");
    CHECK(ld.project_name == "proj");
}

TEST_CASE("Employee is abstract") {
    CHECK(std::is_abstract_v<employees::Employee>);
}

#ifdef TEST_EMPLOYEES_NICE_CONSTRUCTORS
TEST_CASE("Constructors of Developer and Manager are protected") {
    CHECK(!std::is_constructible_v<employees::Developer, std::string>);
    CHECK(!std::is_constructible_v<employees::Manager, std::string>);
}
#endif


TEST_CASE("No default constructors") {
    CHECK(!std::is_default_constructible_v<employees::Employee>);
    CHECK(!std::is_default_constructible_v<employees::Developer>);
    CHECK(!std::is_default_constructible_v<employees::Manager>);
    CHECK(!std::is_default_constructible_v<employees::LeadDeveloper>);
    CHECK(!std::is_constructible_v<employees::Employee>);
    CHECK(!std::is_constructible_v<employees::Developer>);
    CHECK(!std::is_constructible_v<employees::Manager>);
    CHECK(!std::is_constructible_v<employees::LeadDeveloper>);
}

TEST_CASE("No copies or moves") {
    CHECK(!std::is_copy_constructible_v<employees::Employee>);
    CHECK(!std::is_copy_constructible_v<employees::Manager>);
    CHECK(!std::is_copy_constructible_v<employees::Developer>);
    CHECK(!std::is_copy_constructible_v<employees::LeadDeveloper>);
    CHECK(!std::is_copy_assignable_v<employees::Employee>);
    CHECK(!std::is_copy_assignable_v<employees::Manager>);
    CHECK(!std::is_copy_assignable_v<employees::Developer>);
    CHECK(!std::is_copy_assignable_v<employees::LeadDeveloper>);

    CHECK(!std::is_move_constructible_v<employees::Employee>);
    CHECK(!std::is_move_constructible_v<employees::Manager>);
    CHECK(!std::is_move_constructible_v<employees::Developer>);
    CHECK(!std::is_move_constructible_v<employees::LeadDeveloper>);
    CHECK(!std::is_move_assignable_v<employees::Employee>);
    CHECK(!std::is_move_assignable_v<employees::Manager>);
    CHECK(!std::is_move_assignable_v<employees::Developer>);
    CHECK(!std::is_move_assignable_v<employees::LeadDeveloper>);
}

#ifdef TEST_EMPLOYEES_ABSTRACT_BASE_CLASSES
TEST_CASE("Concrete classes are not inherited from each other") {
    CHECK(!std::is_base_of_v<employees::Manager, employees::LeadDeveloper>);
    CHECK(!std::is_base_of_v<employees::Developer, employees::LeadDeveloper>);
}
#endif
