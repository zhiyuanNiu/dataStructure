/**
 * @file SqStack.hpp
 * @author your name (you@domain.com)
 * @brief 栈的顺序存储结构，顺序栈
 *  1、用数组实现顺序栈，索引为0的位置为栈底，索引top表示栈顶的位置
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include <iostream>

class SqStack{
private:
    int* data;      // 数组首地址
    int top;        // 栈顶位置的数组索引，初始值为-1，表示栈为空
    int size;       // 栈的最大容量
public:
    SqStack(int size);
    ~SqStack();

    void Push(int elem);
    int Pop();
};