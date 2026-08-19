#include <iostream>
#include <vector>
#include <thread>

int shared_variable = 0;

int main()
{
    auto shared_incr = []()
    {
        shared_variable = shared_variable + 1;
    };

    std::vector<std::jthread> jthreads;

    for (int i = 0; i < 1000; i++)
    {
        jthreads.push_back(std::jthread(shared_incr));
    }

    std::cout << shared_variable << std::endl;
    return 0;
}