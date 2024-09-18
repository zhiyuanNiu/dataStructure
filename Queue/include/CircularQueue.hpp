/**
 * @file CircularQueue.hpp
 * @author your name (you@domain.com)
 * @brief 循环队列，队列的数组实现
 * 1、头指针head指向队列头部，值为队列首元素在数组中的索引
 * 2、尾指针rear指向队列尾部后边一个位置，值为队尾后一个位置在数组中的索引
 * 3、head == rear, 表示队列为空
 * 4、(rear + 1) % arrayLength == head, 表示队列已满
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

class CircularQueue{
private:
    int* array;
    int head;
    int rear;
    int size;

public:
    CircularQueue(int size);
    ~CircularQueue();

    int Size();
    void Pushback(int value);
    int Popfront();
};