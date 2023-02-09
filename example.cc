#include <sstream>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <thread>
#include <chrono>

int main(int argc, char ** argv) {
    if (argc == 1) {
        // single thread mode when no extra args.
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    } else {
        // multi thread mode when any extra args.
        std::thread t([] {
            while (true) {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        });
        t.join();
    }

    return 0;
}
