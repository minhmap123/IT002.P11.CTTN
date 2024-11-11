#pragma once

#include <iostream>
using namespace std;

/**
 * @class SoPhuc
 * @brief Lớp biểu diễn số phức với phần thực và phần ảo.
 */
class SoPhuc {
private: 
    float iThuc;    // Phần thực của số phức
    float iAo;      // Phần ảo của số phức

public: 
    SoPhuc();
    SoPhuc(float thuc, float ao);

    friend SoPhuc operator + (const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator - (const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator * (const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator / (const SoPhuc& a, const SoPhuc& b);

    friend bool operator == (const SoPhuc& a, const SoPhuc& b);
    friend bool operator != (const SoPhuc& a, const SoPhuc& b);

    friend ostream& operator << (ostream &os, const SoPhuc& ps);
    friend istream& operator >> (istream &is, SoPhuc& ps);
};
