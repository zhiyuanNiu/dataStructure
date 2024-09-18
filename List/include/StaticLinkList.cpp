#include "StaticLinkList.hpp"

StaticLinkList::StaticLinkList(int size) : size(size), length(0){
    list = new Node[size + 2];  // 第一个节点和最后一个节点作为功能节点：第一个节点指向备用链表第一个节点，最后一个节点指向链表的第一个节点
    for(int i = 0; i < size; i++){
        list[i].next = i + 1;
    }
    list[size].next = 0;    // 备用链表的最后一个节点指向0
    list[size + 1].next = 0;    // 最后一个节点指向零，链表为空
}

StaticLinkList::~StaticLinkList()
{
    delete list;
}

void StaticLinkList::InsertNode(int i, int data)
{
    // 链表已满，直接结束
    if(length == size){
        std::cerr << "ERROR: list is already full, can't create new node to insert" << std::endl;
        return;
    }

    // 如果 i 是不在在合法范围内，直接结束
    if(i < 1 || i > length){
        std::cerr << "ERROR: the Node to delete is invalid" << std::endl;
        return;
    }  

    // 分配新节点
    int insertNodeIndex = list[0].next;
    list[insertNodeIndex].data = data;
    list[0].next = list[insertNodeIndex].next;

    // 插入节点
    int insertPosIndex = size + 1;
    for(int j = 1; j < i; j++){     // 查找插入位置索引，第 i-1 个节点的索引
        insertPosIndex = list[insertPosIndex].next;   
    }  
    list[insertNodeIndex].next = list[insertPosIndex].next;
    list[insertPosIndex].next = insertNodeIndex;
    length++;
}

void StaticLinkList::DeleteNode(int i)
{
    // 如果 i 是不在在合法范围内，直接结束
    if(i < 1 || i > length){
        std::cerr << "ERROR: the Node to delete is invalid" << std::endl;
        return;
    }

    // 查找第 i-1 个节点的索引
    int index = size + 1;
    for(int j = 1; j < i; j++){
        index = list[index].next;   // 执行后，index为第j个节点的索引
    }

    // 删除第 i 个节点
    int tmp = list[index].next;     // 第i个节点的索引
    list[index].next = list[tmp].next;      // 从链表中删除
    length--;
    list[tmp].next = list[0].next;      // 加入到备用链表
    list[0].next = tmp;
}

void StaticLinkList::PushBack(int data)
{
    // 链表已满，直接结束
    if(length == size){
        std::cerr << "ERROR: list is already full, can't create new node to insert" << std::endl;
        return;
    }

    // 分配新节点
    int newNodeIndex = list[0].next;
    list[0].next = list[newNodeIndex].next;
    list[newNodeIndex].data = data;
    
    // 添加
    int tailIndex = size + 1;
    while(list[tailIndex].next){    // 查找链表最后一个节点
        tailIndex = list[tailIndex].next;
    }
    list[tailIndex].next = newNodeIndex;
    list[newNodeIndex].next = 0;
    length++;
}

std::ostream &operator<<(std::ostream &os, StaticLinkList &staticList)
{
    os << "StaticLinkList: length = " << staticList.length << ", size = " << staticList.size << ", {";
    int curIndex = staticList.list[staticList.size + 1].next;
    while(curIndex != 0 && staticList.list[curIndex].next != 0){
        os << staticList.list[curIndex].data << ", ";
        curIndex = staticList.list[curIndex].next;
    }
    if(curIndex != 0) os << staticList.list[curIndex].data;
    os << "}";

    return os;
}
