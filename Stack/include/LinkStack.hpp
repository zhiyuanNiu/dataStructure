/**
 * @file LinkStack.hpp
 * @author your name (you@domain.com)
 * @brief 栈的链式存储结构，链栈的单链表实现
 * @version 0.1
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

class LinkStack{
    struct Node{
        int value;
        Node* next;
        Node();
        Node(int value) : value(value), next(nullptr){};
        Node(int value, Node* next) : value(value), next(next) {};
    };

private:
    Node* top;
    int length;

public:
    LinkStack();
    ~LinkStack();

    bool IsEmpty();
    int TopElem();
    void Push(int value);
    int Pop();
    void ClearStack();
};