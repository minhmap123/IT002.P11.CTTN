#pragma once
#include "Diem.cpp"

/**
 * @class DaGiac
 * @brief Đại diện cho một đa giác với n đỉnh
 */
class DaGiac {
private: 
    Diem *Dinh;
    int n;      // so dinh da giac

public: 
    void Nhap();
    void Xuat();
    void TinhTien(float x, float y);
    void PhongTo(float soLan);
    void ThuNho(float soLan);
    void Quay(float gocQuay);
    float TinhDienTich();

    ~DaGiac();
};
