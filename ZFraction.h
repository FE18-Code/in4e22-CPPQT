#ifndef ZFRACTION_H
#define ZFRACTION_H


class ZFraction {
public:
    ZFraction();
    ZFraction(int num, int den);
    ~ZFraction();
    int getNum() const;
    void setNum(int m_num);
    int getDen() const;
    void setDen(int m_den);

private:
    int m_num;
    int m_den;
};


#endif //ZFRACTION_H
