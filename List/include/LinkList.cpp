#include "LinkList.hpp"
#include <iostream>

LinkList::LinkList()
{
    head = new Node();
    tail = nullptr;

    length = 0;
}

LinkList::~LinkList()
{
    Delete();
}

void LinkList::InsertBegin(std::vector<int> &vec)
{
    for(auto v : vec){
        Node* node = new Node(v, head->next);
        if(tail == nullptr) tail = node;
        head->next = node;
        length++;
    }
}

void LinkList::InsertEnd(std::vector<int> &vec)
{
    for(auto v : vec){
        Node* node = new Node(v);
        if(tail == nullptr){
            head->next = node;
            tail = node;            
        }else{
            tail->next = node;
            tail = tail->next;
        }
        length++;
    }
}

void LinkList::Delete()
{
    Node* cur = head->next;
    while(cur){
        Node* tmp = cur->next;
        delete cur;
        length--;
        cur = tmp;
    }
    head->next = nullptr;   // 在删除所有节点后，应该将 head 指针设置为 nullptr，以避免悬空指针。
    std::cout << "link list has been deleted" << std::endl;
}

std::ostream &operator<<(std::ostream &os, LinkList &list)
{
    os << "LinkList length: " << list.length << ", {";
    Node* cur = list.head->next;
    while(cur && cur->next){
        os << cur->value << ", ";
        cur = cur->next;
    }
    if(cur) os << cur->value;
    os << "}";

    return os;
}
