#include <string>
#include <iostream>

class Base {
    public:
    const std::string name;

    Base(std::string name) : name(name){}
};

class A : public Base {
    public:
    
    // default constructor
    A() : Base("A") {
        std::cout << "class: " << name << " initialized with DEFAULT constructor." << std::endl;
    }

    // copy constructor
    A(A &a) : Base(a.name) {
        std::cout << "class: " << name << " initialized with COPY constructor." << std::endl;
    }

    A(A &&a) : Base(a.name) {
        std::cout << "class: " << name << " initialized with MOVE constructor." << std::endl;
    }
};