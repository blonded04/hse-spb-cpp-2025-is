#include <boost/asio.hpp>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <utility>

using boost::asio::ip::tcp;

int main() {
    boost::asio::io_context io_context;

    std::vector<std::thread> ts;
    // TODO:
    // 1. Create 100 threads doing the same as `20-tcp-single-client`, running in parallel.
    // 2. Wait for them to terminate (`.join()`).
    // 3. Run these 100 clients against your `11-tcp-multi-server-shared-state`.
    // 4. Remove `mutex` from the server and try again a few times: the server should eventually crash.

    return 0;
}
