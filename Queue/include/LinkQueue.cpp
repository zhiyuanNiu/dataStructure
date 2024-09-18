#include "LinkQueue.hpp"
#include <iostream>

LinkQueue::LinkQueue() : length(0)
{
    Node* dummy = new Node();
    head = dummy;
    rear = dummy;
}

LinkQueue::~LinkQueue()
{
    ClearQueue();
}

void LinkQueue::ClearQueue()
{
    while(head != rear)
    {
        Popfront();
    }
}

int LinkQueue::Popfront()
{
    if(head == rear)
    {
        std::cerr << "ERROR: queue is empty, can't pop front" << std::endl;
        return -1;
    }

    Node* front = head->next;
    int value = front->value;

    head->next = head->next->next;
    if(rear == front) rear = head;      // 避免最后一个节点删除后 rear 变为悬空指针；同时，将队列恢复为空队列的状态
    delete front;
    length--;

    return value;
}

void LinkQueue::Pushback(int value)
{
    Node* node = new Node(value);
    rear->next = node;
    rear = node;
    length++;
}