#pragma once

#include <string>
using namespace std;

/**
 * @class ThiSinh
 * @brief Đại diện cho một thí sinh với thông tin cá nhân và điểm số các môn thi.
 */
class ThiSinh {
private:
    string Ten;
    string MSSV;
    int iNgay;
    int iThang;
    int iNam;
    float fToan;
    float fVan;
    float fAnh;

public:
    void Nhap();
    void Xuat();
    float Tong();
};
