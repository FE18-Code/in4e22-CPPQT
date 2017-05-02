#include "iostream"
using namespace std;

/* class A */

class A{
public:
    virtual void f(int);
};

void A::f(int) {
    cout << "A" << endl;
    return;
}

/* class B */

class B : public A{
public:
    void f(int);
};

void B::f(int) {
    cout << "B" << endl;
    return;
}

/* main */

int main(){
    B b;
    A *ptra = &b;

    b.f(0);
    b.A::f(0);
    ptra->f(0);
}
