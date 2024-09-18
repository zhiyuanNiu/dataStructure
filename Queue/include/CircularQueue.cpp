#include "CircularQueue.hpp"
#include <iostream>

CircularQueue::CircularQueue(int size) : size(size)
{
    array = new int[size];
    head = 0;
    rear = 0;
}

CircularQueue::~CircularQueue()
{
    delete array;
}

int CircularQueue::Size()
{
    return size;
}

void CircularQueue::Pushback(int value)
{
    if((rear + 1) % size == head)   // 队列已满
    {
        std::cerr << "ERROR: queue is full, can't push back" << std::endl;
        return;
    }

    array[rear] = value;
    rear = (rear + 1) % size;
}

int CircularQueue::Popfront()
{
    if(rear == head)    // 队列为空
    {
        std::cerr << "ERROR: queue is empty, can't pop front" << std::endl;
        return -1;
    }

    int front = array[head];
    head = (head + 1) % size;

    return front;
}
