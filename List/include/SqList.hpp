/**
 * @file SqList.hpp
 * @author your name (you@domain.com)
 * @brief 线性表的顺序存储结构实现，基于数组实现
 * @version 0.1
 * @date 2024-09-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include <vector>
#include <iostream>

class SqList{
private:
    int *data;    // 存储空间起始地址
    int length; // 线性表当前长度
    int size;   // 线性表最大容量

public:
    SqList(int size);
    SqList(std::vector<int>& vec);
    ~SqList();

    int GetElem(int i);   // 获取第i个元素
    void ListInsert(int i, int elem);   // 在第i个位置插入元素elem
    int ListDelete(int i);     // 删除第i个元素

    friend std::ostream& operator<<(std::ostream& os, const SqList& sqList);
};

