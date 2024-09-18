/**
 * @file LinkQueue.hpp
 * @author your name (you@domain.com)
 * @brief 队列的链式存储结构的实现，基于单链表
 * 1、头指针 head 指向虚拟头节点，尾指针 rear 指向最后一个节点
 * 2、单链表头部为队头，弹出元素；单链表尾部为队尾，添加元素；
 * 3、当 head == rear 时，队列为空
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class LinkQueue
{
    struct Node
    {
        int value;
        Node* next;
        Node() : value(0), next(nullptr){};
        Node(int value) : value(value), next(nullptr) {};
        Node(int value, Node* next) : value(value), next(next) {};
    };

private:
    Node* head;
    Node* rear;
    int length;

public:
    LinkQueue();
    ~LinkQueue();

    void ClearQueue();      // 清空队列
    int Popfront();
    void Pushback(int value);
};