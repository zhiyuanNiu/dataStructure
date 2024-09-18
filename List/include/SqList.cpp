/**
 * @file SqList.cpp
 * @author your name (you@domain.com)
 * @brief 线性表的顺序存储结构实现，数组
 * @version 0.1
 * @date 2024-09-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "SqList.hpp"


SqList::SqList(int size): size(size){
    data = new int[size];
    length = 0;
}


SqList::SqList(std::vector<int> &vec)
{
    size = vec.size();
    data = new int[size];
    length = 0;
    for(auto elem : vec){
        data[length] = elem;
        length++;
    }
}


SqList::~SqList(){
    delete[] data;
}


int SqList::GetElem(int i)
{
    return data[i-1];
}


void SqList::ListInsert(int i, int elem)
{
    if(i < 1 || i > length){
        std::cerr << "Error: index out of SqList's range." << std::endl;
        return;
    }
    if(length == size){
        std::cerr << "Error: SqList is full." << std::endl;
        return;
    }

    for(int j = length - 1; j >= i - 1; j--){
        data[j+1] = data[j];
    }
    data[i-1] = elem;
    length++;
}


int SqList::ListDelete(int i)
{
    if(i < 1 || i > length){
        std::cerr << "Error: index out of the range of SqList" << std::endl;
        return -1;
    }

    int elem = data[i-1];
    for(int j = i - 1; j < length - 1; j++){
        data[j] = data[j+1];
    }
    length--;
    
    return elem;
}

std::ostream &operator<<(std::ostream &os, const SqList &sqList)
{
    os << "SqList length: " << sqList.length << ", SqList size: " << sqList.size << ", ";
    if(sqList.length != 0){
        os << "{";
        for(int i = 0; i < sqList.length - 1; i++){
            os << sqList.data[i] << ", ";
        }
        os << sqList.data[sqList.length - 1] << "}";
    }

    return os;
}

