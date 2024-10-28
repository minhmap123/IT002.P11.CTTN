#pragma once

#include "Diem.cpp"


/**
 * @class TamGiac
 * @brief Đại diện cho một tam giác với ba đỉnh A, B, và C.
 */
class TamGiac {
private: 
    Diem A;
    Diem B;
    Diem C;

public: 
    void Nhap();
    void Xuat();
    void TinhTien(float x, float y);
    void PhongTo(float soLan);
    void ThuNho(float soLan);
    void Quay(float gocQuay);
};
