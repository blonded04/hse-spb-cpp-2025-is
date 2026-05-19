#include <boost/asio.hpp>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <utility>

using boost::asio::ip::tcp;

int main() {
    boost::asio::io_context io_context;

    // TODO:
    // 1. Connect to your 11-tcp-multi-server-shared-state
    // 2. Send 1000 random requests: random command (add/del/count) + 10 random letters a/b.
    // 3. Read response (single line) for each request, and print it for each 100th request.
    // 4. Run this client against your server.

    return 0;
}
