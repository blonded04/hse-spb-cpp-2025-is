#include <cassert>
#include <cstdlib>
#include <optional>
#include <string>
#include <memory>
#include <utility>

struct player {
    std::string name;
    std::shared_ptr<std::string> field;

    explicit player(std::string name_) : name(std::move(name_)), field(std::make_shared<std::string>(10, '.')) {}
    explicit player(std::string name_, const player &host) : name(std::move(name_)), field(host.field) {}

    void make_turn() {
        for (char &c : *field) {
            if (c == '.') {
                c = name[0];
                return;
            }
        }
        std::terminate();
    }

    const std::string &get_field() {
        return *field;
    }
};

int main() {
    {
        player a1("Egor");
        assert(a1.get_field() == "..........");
        a1.make_turn();
        a1.make_turn();
        assert(a1.get_field() == "EE........");
    }
    {
        player a1("Egor");  // new field
        player a2("Notegor", a1);  // same field
        player a3("Cat", a2);  // same field
        a1.make_turn();
        a2.make_turn();
        a1.make_turn();
        a3.make_turn();
        a1.make_turn();
        assert(a1.get_field() == "ENECE.....");
        assert(a2.get_field() == "ENECE.....");
        assert(a3.get_field() == "ENECE.....");
    }
    {
        std::optional<player> a1("Egor");  // new field
        std::optional<player> a2(std::in_place, "Notegor", *a1);  // same field
        std::optional<player> b("Dog");  // new field
        std::optional<player> a3(std::in_place, "Cat", *a2);  // same field
        a1->make_turn();
        a2->make_turn();
        a1->make_turn();
        b->make_turn();
        a3->make_turn();
        a1->make_turn();
        b->make_turn();
        assert(a1->get_field() == "ENECE.....");
        assert(a2->get_field() == "ENECE.....");
        assert(a3->get_field() == "ENECE.....");
        assert(b->get_field() == "DD........");

        a1.reset();
        assert(a2->get_field() == "ENECE.....");
        assert(a3->get_field() == "ENECE.....");
        assert(b->get_field() == "DD........");

        a3.reset();
        assert(a2->get_field() == "ENECE.....");
        assert(b->get_field() == "DD........");

        a2.reset();
        assert(b->get_field() == "DD........");
    }
}
