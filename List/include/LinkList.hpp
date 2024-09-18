/**
 * @file LinkList.hpp
 * @author your name (you@domain.com)
 * @brief 线性表的链式存储结构，单链表实现
 * @version 0.1
 * @date 2024-09-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <vector>
#include <iostream>

struct Node{
    int value;
    Node* next;
    Node() : value(0), next(nullptr) {};
    Node(int value) : value(value), next(nullptr) {};
    Node(int value, Node* next) : value(value), next(next) {};
    ~Node(){};
};

class LinkList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkList();
    ~LinkList();

    void InsertBegin(std::vector<int>& vec);    // 头插法
    void InsertEnd(std::vector<int>& vec);      // 尾插法
    void Delete();

    friend std::ostream& operator<<(std::ostream& os, LinkList& list);
};