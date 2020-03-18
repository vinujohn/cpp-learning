#include "Classes.h"
#include <iostream>
#include <algorithm>


void copyA(A a){
    std::cout << "A should have been copied." << std::endl;
}

void moveA(A &&a) {
    std::cout << "A should have been moved." << std::endl;
}

int main() {
    A a; // call default constructor
    //copyA(a); // test copy constructor
    
    //TODO: Left off here. not working
    moveA(std::move(a)); // test move constructor

    std::cout << "end main" << std::endl;
    return 0;
}

