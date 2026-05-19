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
    std::mutex strings_m;  // Important, crashes otherwise.

    while (true) {
        tcp::socket s = acceptor.accept();
        std::thread([s = std::move(s), &strings, &strings_m]() mutable {
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
                    bool inserted;
                    {
                        std::unique_lock l(strings_m);
                        inserted = strings.insert(str).second;
                    }
                    client << "added " << inserted << "\n";
                } else if (command == "del") {
                    std::string str;
                    if (!(client >> str)) {
                        break;
                    }
                    {
                        std::unique_lock l(strings_m);
                        strings.erase(str);
                    }
                    client << "erased\n";
                } else if (command == "count") {
                    std::string str;
                    if (!(client >> str)) {
                        break;
                    }
                    int count;
                    {
                        std::unique_lock l(strings_m);
                        count = strings.count(str);
                    }
                    client << "counted " << count << "\n";
                } else {
                    client << "unknown command\n";
                }
            }
            std::cout << "Completed\n";
        }).detach();
    }
}
