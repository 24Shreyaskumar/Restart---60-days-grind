#include <iostream>
#include <atomic>
#include <vector>
#include <thread>

std::atomic<int> shared = 0;

int main()
{
    auto lambda = []()
    {
        shared++;
    };

    std::vector<std::thread> jthreads;

    for (int i = 0; i < 1000; i++)
    {
        jthreads.push_back(std::thread(lambda));
    }

    for (int i = 0; i < 1000; i++)
    {
        jthreads[i].join();
    }

    std::cout << shared << std::endl;
    return 0;
}