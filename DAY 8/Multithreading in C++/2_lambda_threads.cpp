#include <iostream>
#include <thread>

int main()
{
    auto lambda = [](int x)
    {
        std::cout << "Hello from thread\n";
        std::cout << "Argument passed is : " << x << std::endl;
    };

    std::thread t1(lambda, 100);
    t1.join();

    std::cout << "Hello from main thread" << std::endl;
    return 0;
}