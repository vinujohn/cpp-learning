#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "list.h"
#include "node.h"

template<typename T>
class LinkedList : public List<T>
{
private:
    int size;
    Node<T> *head;

public:
    LinkedList();
    void PushBack(T);
    void PushFront(T);
    T PopBack();
    T PopFront();
    int Size();
};

#endif