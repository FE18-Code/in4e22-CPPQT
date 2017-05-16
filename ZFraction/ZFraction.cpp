#include "iostream"
#include "ZFraction.h"

using namespace std;

ZFraction::ZFraction() {
    ZFraction(0, 0);
}

ZFraction::ZFraction(int num, int den) {
    m_den=den;
    m_num=num;
}

ZFraction::~ZFraction() {
    /* void */
}

int ZFraction::getNum() const {
    return m_num;
}

void ZFraction::setNum(int m_num) {
    ZFraction::m_num = m_num;
}

int ZFraction::getDen() const {
    return m_den;
}

void ZFraction::setDen(int m_den) {
    ZFraction::m_den = m_den;
}
