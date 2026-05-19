#include <boost/asio.hpp>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <utility>
#include <vector>

using boost::asio::buffer;
using boost::asio::ip::tcp;

void send_message(tcp::socket &s, const std::string &msg) {
    // TODO: send string `msg` as a single message to socket `s`.
    // `msg` is not necessarily null-terminated.
    // Use `write(s, ...)` function, not `s.send()`, the latter does not guarantee full send.
    write(s, buffer(msg));
}

std::string read_message(tcp::socket &s) {
    // TODO: read a single mesage from `s` and return it.
    // Use `read(s, ...)` 
    std::string msg = "?";
    // Use `read(s, ...)` function, not `s.recv`, the latter does not guarantee full read.
    read(s, buffer(msg));
    return msg;
}

int main() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 0));  // '0' means 'choose random port'
    std::cout << "Listening at " << acceptor.local_endpoint() << "\n";

    tcp::socket client_end(io_context);
    boost::asio::connect(client_end, std::vector{tcp::endpoint(
        boost::asio::ip::make_address("127.0.0.1"),
        acceptor.local_endpoint().port()
    )});
    std::cout << "Connected " << client_end.local_endpoint() << " --> "
              << client_end.remote_endpoint() << "\n";

    tcp::socket server_end = acceptor.accept();
    std::cout << "Accepted" << std::endl;

    auto check = [&](const std::string &message) {
        send_message(client_end, message);
        std::string got = read_message(server_end);
        assert(message == got);

        send_message(server_end, message);
        got = read_message(client_end);
        assert(message == got);
    };

    check("");
    std::cout << "Checked empty string" << std::endl;
    for (int i = 0; i < 256; i++) {
        check(std::string(1, i));
    }
    std::cout << "Checked 1-char strings" << std::endl;
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            check(std::string(1, i) + std::string(1, j));
        }
    }
    std::cout << "Checked 2-char strings" << std::endl;

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution len_choice(0, 10'000);
    std::uniform_int_distribution letter_choice(0, 255);

    for (int i = 0; i < 1'000; i++) {
        std::vector<std::string> messages;
        for (int j = 0; j < 10; j++) {
            int len = len_choice(gen);
            std::string msg(len, '?');
            for (char &c : msg) {
                c = letter_choice(gen);
            }
            messages.push_back(msg);
        }

        for (const auto &msg : messages) {
           send_message(client_end, msg);
        }
        for (const auto &msg : messages) {
            std::string got = read_message(server_end);
            assert(msg == got);
        }
    }
    std::cout << "OK\n";
}
