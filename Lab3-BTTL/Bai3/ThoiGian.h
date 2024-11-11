#pragma once 

#include <iostream>
using namespace std;

/**
 * @class ThoiGian
 * @brief Lớp biểu diễn thời gian theo định dạng 24 giờ.
 */
class ThoiGian {
private: 
    int iGio;
    int iPhut;
    int iGiay;

public:
    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay);
    int TinhGiay() const;
    ThoiGian TinhLaiGio(int Giay);

    ThoiGian operator + (int Giay);
    ThoiGian operator - (int Giay);
    ThoiGian operator + (const ThoiGian& other);
    ThoiGian operator - (const ThoiGian& other);
    ThoiGian operator ++ ();
    ThoiGian operator -- ();
    
    bool operator == (const ThoiGian& other);
    bool operator != (const ThoiGian& other);
    bool operator >= (const ThoiGian& other);
    bool operator <= (const ThoiGian& other);
    bool operator >  (const ThoiGian& other);
    bool operator <  (const ThoiGian& other);
    friend ostream& operator << (ostream& os, const ThoiGian& tg);
    friend istream& operator >> (istream& is, ThoiGian& tg);
};
