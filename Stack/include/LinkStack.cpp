#include "LinkStack.hpp"
#include <iostream>

LinkStack::LinkStack() : top(nullptr), length(0)
{
}

LinkStack::~LinkStack()
{
    ClearStack();
}

bool LinkStack::IsEmpty()
{
    if(length == 0) return true;
    return false;
}

int LinkStack::TopElem()
{
    return top->value;
}

void LinkStack::Push(int value)
{
    Node* node = new Node(value);
    node->next = top;
    top = node;
    length++;
}

int LinkStack::Pop()
{
    if(length <= 0){
        std::cerr << "ERROR: LinkStack is empty, can't pop back element" << std::endl;
        return -1;
    }

    int elem;
    elem = top->value;
    Node* curNode = top;
    top = top->next;
    delete curNode;
    length--;

    return elem;
}

void LinkStack::ClearStack()
{
    while(length){
        Pop();
    }
}
