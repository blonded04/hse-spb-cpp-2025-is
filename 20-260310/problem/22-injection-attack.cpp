#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

struct invalid_region_name : std::runtime_error {
    // Vulnerable to injection attacks, e.g. https://owasp.org/www-community/attacks/Log_Injection
    invalid_region_name(const std::string &name) : std::runtime_error("Invalid region name: '" + name + "'") {}
};

enum class Region { AMER, APAC, EMEA };

std::ostream &operator<<(std::ostream &os, const Region &r) {
    static const std::unordered_map<Region, std::string> REGIONS = {
        {Region::AMER, "AMER"},
        {Region::APAC, "APAC"},
        {Region::EMEA, "EMEA"},
    };
    return os << REGIONS.at(r);
}

Region parse_region(const std::string &region) {
    static const std::unordered_map<std::string, Region> REGIONS = {
        {"AMER", Region::AMER},
        {"APAC", Region::APAC},
        {"EMEA", Region::EMEA},
    };
    auto it = REGIONS.find(region);
    if (it == REGIONS.end()) {
        throw invalid_region_name(region);
    }
    return it->second;
}

int main() {
    std::string r1_str, r2_str;
    std::getline(std::cin, r1_str);
    std::getline(std::cin, r2_str);
    assert(std::cin);
    // TODO: make the code below print what's in the `*.sol` file without changing the code.
    try {
        Region r1 = parse_region(r1_str);
        Region r2 = parse_region(r2_str);
        if (r1 != r2) {
            std::cout << "Invalid region name: '" << r1 << "' expected, got '" << r2 << "'\n";
        }
    } catch (invalid_region_name &e) {
        std::cout << e.what() << "\n";
    }
}
