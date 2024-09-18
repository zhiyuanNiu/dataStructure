#include "CircularQueue.hpp"
#include <iostream>

int main()
{
    CircularQueue queue(4);

    queue.Popfront();       // "ERROR: queue is empty, can't pop front"

    queue.Pushback(1);
    queue.Pushback(2);
    queue.Pushback(3);
    queue.Pushback(4);      // "ERROR: queue is full, can't push back"

    std::cout << queue.Popfront() << std::endl;     // 1

    queue.Pushback(4);     
    std::cout << queue.Popfront() << std::endl;     // 2
    std::cout << queue.Popfront() << std::endl;     // 3
    std::cout << queue.Popfront() << std::endl;     // 4
    std::cout << queue.Popfront() << std::endl;     // "ERROR: queue is empty, can't pop front"

    return 0;
}
