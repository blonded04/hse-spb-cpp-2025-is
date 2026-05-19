#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <utility>

using boost::asio::ip::tcp;

int main() {
    boost::asio::io_context io_context;

    tcp::socket s(io_context);

    // TODO: connect to port 80 of vk.com
    boost::asio::connect(s, tcp::resolver(io_context).resolve(TODO, TODO));
    tcp::iostream conn(TODO);
    std::cout << "Connected " << conn.socket().local_endpoint() << " --> "
              << conn.socket().remote_endpoint() << "\n";

    conn << "GET / HTTP/1.1\r\nHost: vk.com\r\n\r\n";  // N.B.: HTTP protocol requires exactly two bytes for newline, tcp::iostream does not translate \n to \r\n.
    conn.socket().shutdown(tcp::socket::shutdown_send);
    std::cout << "Shut down\n";

    // TODO: read all text data from 'conn' and print it.

    std::cout << "Completed\n";
    return 0;
}
