#include "linked_list.h"

template<typename T>
LinkedList<T>::LinkedList(){
    this->size = 0;
    this->head = nullptr;
}

template<typename T>
void LinkedList<T>::PushBack(T data){
    auto newNode = new Node(data);
    if(this->Size() == 0){
        this->head = newNode;
    }else{
        auto tailNode = this->head->GetPrev();
        tailNode->SetNext(newNode);
        newNode->SetPrev(tailNode);
        newNode->SetNext(this->head);
        this->head->SetPrev(newNode);
    }
    this->size++;
}

template<typename T>
void LinkedList<T>::PushFront(T data){
    
}

template<typename T>
T LinkedList<T>::PopBack(){
    if(this->Size() > 0){
        auto delNode = this->head->GetPrev();
        auto ret = delNode->GetData();
        delNode->GetPrev()->SetNext(this->head);
        this->head->SetPrev(delNode->GetPrev());
        this->size--;
        return ret;
    }
    return T();
}

// template<typename T>
// T LinkedList<T>::PopFront(){
//     return nullptr;
// }

template<typename T>
int LinkedList<T>::Size(){
    return this->size;
}