#include <boost/asio.hpp>
#include <iostream>
#include <utility>

using boost::asio::ip::tcp;

int main() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));
    std::cout << "Listening at " << acceptor.local_endpoint() << "\n";

    while (true) {
        tcp::socket s = acceptor.accept();
        std::cout << "Accepted connection " << s.remote_endpoint() << " --> "
                  << s.local_endpoint() << "\n";
        tcp::iostream client(std::move(s));

        while (client) {
            std::string s;
            if (!(client >> s)) {
                break;
            }
            client << "got from you: " << s << "\n";
        }
        std::cout << "Completed\n";
    }
}
