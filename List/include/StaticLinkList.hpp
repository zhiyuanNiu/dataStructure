/**
 * @file StaticLinkList.hpp
 * @author your name (you@domain.com)
 * @brief 静态链表，用数组实现单链表，这种方法主要是用于在没有指针的高级编程语言中实现单链表
 *  1. 数组的每个元素包含两部分：数据部分存放节点的值，指针部分存放后继结点在数组中的索引位置；
 *  2. 数组的最后一个节点保留作为链表的头节点，指向链表的第一个节点；
 *  3. 数组的第一个节点保留作为备用链表的头节点，指向备用链表的第一个节点；
 *  4. 链表和备用链表的最后一个节点的指针部分的值均为0；
 * @version 0.1
 * @date 2024-09-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include <iostream>

struct Node{
    int data;  // 节点数据
    int next;  // 后继结点数组索引
};

class StaticLinkList{
private:
    Node* list;     // 数组首元素指针
    int size;       // 链表节点最大容量
    int length;     // 链表当前长度

public:
    StaticLinkList(int size);
    ~StaticLinkList();

    void InsertNode(int i, int data);   // 在链表中第i个节点前插入节点
    void DeleteNode(int i);   // 删除链表中第i个节点
    void PushBack(int data);          // 在尾部添加节点

    friend std::ostream& operator<<(std::ostream& os, StaticLinkList& staticList);    
};
