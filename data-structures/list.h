#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
public:
    virtual void PushBack(T) = 0;
    virtual void PushFront(T) = 0;
    virtual T PopBack() = 0;
    // virtual T PopFront() = 0;
    virtual int Size() = 0;
};

#endif