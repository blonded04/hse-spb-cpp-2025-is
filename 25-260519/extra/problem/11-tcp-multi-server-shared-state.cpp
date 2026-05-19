#include <boost/asio.hpp>
#include <iostream>
#include <set>
#include <thread>
#include <utility>

using boost::asio::ip::tcp;

int main() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));
    std::cout << "Listening at " << acceptor.local_endpoint() << "\n";

    std::set<std::string> strings;

    // TODO: make the server below handle multiple clients at the same time on the same `strings` variable.
    tcp::socket s = acceptor.accept();
    std::cout << "Accepted connection " << s.remote_endpoint()
              << " --> " << s.local_endpoint() << "\n";
    tcp::iostream client(std::move(s));

    while (client) {
        std::string command;
        if (!(client >> command)) {
            break;
        }
        if (command == "add") {
            std::string str;
            if (!(client >> str)) {
                break;
            }
            client << "added " << strings.insert(str).second << "\n";
        } else if (command == "del") {
            std::string str;
            if (!(client >> str)) {
                break;
            }
            strings.erase(str);
            client << "erased\n";
        } else if (command == "count") {
            std::string str;
            if (!(client >> str)) {
                break;
            }
            client << "counted " << strings.count(str) << "\n";
        } else {
            client << "unknown command\n";
        }
    }
    std::cout << "Completed\n";
}
