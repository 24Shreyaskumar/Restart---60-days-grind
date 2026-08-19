#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;
int shared_variable = 0;

int main()
{
    auto shared_incr = []()
    {
        std::lock_guard<std::mutex> lock(mtx);
        shared_variable = shared_variable + 1;
    };

    std::vector<std::thread> jthreads;

    for (int i = 0; i < 1000; i++)
    {
        jthreads.push_back(std::thread(shared_incr));
    }

    for (int i = 0; i < 1000; i++)
    {
        jthreads[i].join();
    }

    std::cout << shared_variable << std::endl;
    return 0;
}