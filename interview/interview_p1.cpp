#include<iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        std::cout << "Base\n";
    }
};
class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived\n";
    }
};
int main() {
    Base* b;
    Derived d;
    b = &d;
    b->show();
    return 0;
}