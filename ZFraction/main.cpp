#include "iostream"
#include "ZFraction.h"

using namespace std;

std::ostream & operator<<(std::ostream & os, const ZFraction & fraction) {
    os << fraction.getNum() << "/" << fraction.getDen();
    return os;
}

ZFraction operator*(const ZFraction& a, const ZFraction& b){
    ZFraction res;
    res.setNum(a.getNum()*b.getNum());
    res.setDen(a.getDen()*b.getDen());
    return res;
}

int main(){
    ZFraction a(4, 5);
    ZFraction b(1, 1);
    a = a * b;
    cout << "Fraction : " << a << " fin !";
}
