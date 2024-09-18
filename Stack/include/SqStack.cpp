#include "SqStack.hpp"
#include <vector>

SqStack::SqStack(int size) : size(size), top(-1)
{
    data = new int[size];
}

SqStack::~SqStack()
{
    delete data;
}

void SqStack::Push(int elem)
{
    if(top >= size - 1){
        std::cerr << "ERROR: stack is full, can't push data" << std::endl;
        return;
    }

    top++;
    data[top] = elem;
}

int SqStack::Pop()
{
    if(top < 0){
        std::cerr << "ERROR: stack is empty, can't pop data" << std::endl;
        return -1;
    }

    int elem;
    elem = data[top];
    top--;

    return elem;
}

