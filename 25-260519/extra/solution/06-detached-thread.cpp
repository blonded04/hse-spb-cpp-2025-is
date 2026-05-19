#include <chrono>
#include <iostream>
#include <thread>

void ticker(int id) {
    for (int i = 0; i < 10; i++) {
        std::cout << "ticker(" << id << ") ticks " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    for (int id = 0;; id++) {
        std::thread([id]() { ticker(id); }).detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
    }
}
