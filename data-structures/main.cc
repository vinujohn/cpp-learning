#include "linked_list.h"
#include <iostream>
#include <assert.h>

int main(){
    // new list should have size 0
    LinkedList<int> t1; 
    assert(t1.Size() == 0);

    // push_back: list with one element
    LinkedList<int> t2;
    t2.PushBack(5);
    assert(t2.Size()==1);
    assert(t2.PopBack() == 5);

    // push_back: list with two elements
    LinkedList<int> t3;
    t3.PushBack(5);
    t3.PushBack(7);
    t3.PushBack(13);
    assert(t3.Size()==3);
    assert(t3.PopBack() == 13);
    assert(t3.PopBack() == 7);
    assert(t3.Size()==1);
    assert(t3.PopBack() == 5);
    assert(t3.Size()==0);
    assert(t3.PopBack() == 0);
}