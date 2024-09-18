#include "LinkQueue.hpp"
#include <iostream>

int main()
{
    LinkQueue queue;

    queue.Pushback(1);
    queue.Pushback(2);
    queue.Pushback(3);

    std::cout << queue.Popfront() << std::endl;     // 1      
    std::cout << queue.Popfront() << std::endl;     // 2     
    std::cout << queue.Popfront() << std::endl;     // 3
    std::cout << queue.Popfront() << std::endl;     // ERROR

    return 0;
}