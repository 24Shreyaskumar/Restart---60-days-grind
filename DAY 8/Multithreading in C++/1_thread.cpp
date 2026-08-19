#include <iostream>
#include <thread>

void worker(int arg)
{
    std::cout << "Hello from thread\n";
    std::cout << "Arg passed in : " << arg << std::endl;
    return;
}

int main()
{
    std::thread t1(&worker, 100);
    t1.join(); // wait for the thread to finish executing
    std::cout << "Hello from main thread" << std::endl;
    return 0;
}