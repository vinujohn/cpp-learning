#include <iostream>

int x = 1;

class Foo{
public:
    int x;
    std::string s;
    Foo(){
        x = 2;
        s = "hello there";
    }
};

int &setGlobal(){
    return x;
}

void setYRef(){
    int y = 10;
    int &yref = y;
    yref++;

    std::cout << "Value of yRef " << yref << std::endl;

    y = 15;

    std::cout << "Value of yRef after y has changed " << yref << std::endl;
}

void modifyRef(Foo &x){
    x.s = "changed";
}

void modifyVal(Foo x){
    x.s = "changed";
}

int main(){
    // setGlobal() = 3;
    // std::cout << "Value of setGlobal() " << setGlobal() << std::endl;

    // setYRef();

    Foo x;
    modifyRef(x);
    std::cout << "Value of Foo.s after modifyRef " << x.s << std::endl;

    Foo x2;
    modifyVal(x2);
    std::cout << "Value of Foo.s after modifyRef " << x2.s << std::endl;

    return 0;
}

