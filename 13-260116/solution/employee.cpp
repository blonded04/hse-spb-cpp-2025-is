#include <cassert>
#include <iostream>
#include "employee.hpp"

namespace employee {

std::unique_ptr<Employee> Employee::readFrom(std::istream &is) {
    std::string type;
    is >> type;
    assert(is);
    if (type == "Developer") {
        return std::make_unique<Developer>(Developer::readFrom(is));
    } else if (type == "SalesManager") {
        return std::make_unique<SalesManager>(SalesManager::readFrom(is));
    } else {
        std::abort();
    }
}

Developer Developer::readFrom(std::istream &is) {
    std::string first_name_;
    std::string last_name_;
    ProgrammingLanguage language_;
    std::string github_handle_;
    is >> first_name_ >> last_name_ >> language_ >> github_handle_;
    assert(is);
    return Developer(std::move(first_name_), std::move(last_name_),
                     language_, std::move(github_handle_));
}

void Developer::printTo(std::ostream &os) const {
    os << "Developer " << first_name << " " << last_name << " " << language
       << " " << github_handle;
}

SalesManager SalesManager::readFrom(std::istream &is) {
    std::string first_name_;
    std::string last_name_;
    Region region_;
    is >> first_name_ >> last_name_ >> region_;
    assert(is);
    return SalesManager(std::move(first_name_), std::move(last_name_),
                        region_);
}

void SalesManager::printTo(std::ostream &os) const {
    os << "SalesManager " << first_name << " " << last_name << " "
       << region;
}

}  // namespace employee
