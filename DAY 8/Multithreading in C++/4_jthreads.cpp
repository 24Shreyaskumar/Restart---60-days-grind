#include <iostream>
#include <vector>
#include <thread>

int main()
{
    auto lambda = [](int x)
    {
        std::cout << "Hello from thread : " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed is : " << x << std::endl;
    };

    std::vector<std::jthread> jthreads;

    for (int i = 0; i < 10; i++)
    {
        jthreads.push_back(std::jthread(lambda, i));
    }

    // notice that we are not joining the threads as the jthread will join by itself.

    std::cout << "Hello from main thread" << std::endl;
    return 0;
}