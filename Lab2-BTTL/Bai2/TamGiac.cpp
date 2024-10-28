#pragma once

#include <iostream>
#include <cmath>
#include "TamGiac.h"

using namespace std;

/**
 * @brief Nhập tọa độ cho ba đỉnh A, B, và C của tam giác từ người dùng.
 */
void TamGiac::Nhap() {
    cout << "Nhap toa do 3 dinh cua tam giac: \n";
    float x, y;

    cout << "\tNhap toa do dinh A (x y): ";
    cin >> x >> y;
    this->A = Diem(x, y);

    cout << "\tNhap toa do dinh B (x y): ";
    cin >> x >> y;
    this->B = Diem(x, y);

    cout << "\tNhap toa do dinh C (x y): ";
    cin >> x >> y;
    this->C = Diem(x, y);
}

/**
 * @brief Xuất tọa độ của ba đỉnh A, B, và C của tam giác ra màn hình.
 */
void TamGiac::Xuat() {
    cout << "Toa do 3 dinh cua tam giac: \n";
    cout << "\tA";    A.Xuat();   cout << '\n';
    cout << "\tB";    B.Xuat();   cout << '\n';
    cout << "\tC";    C.Xuat();   cout << '\n';
}

/**
 * @brief Tịnh tiến tam giác theo vector (x, y).
 * @param x Tọa độ tịnh tiến theo trục hoành.
 * @param y Tọa độ tịnh tiến theo trục tung.
 */
void TamGiac::TinhTien(float x, float y) {
    A.TinhTien(x, y);
    B.TinhTien(x, y);
    C.TinhTien(x, y);
}

/**
 * @brief Phóng to tam giác lên một số lần tỷ lệ soLan.
 * @param soLan Hệ số phóng to tam giác.
 */
void TamGiac::PhongTo(float soLan) {
    if (soLan == 0) return;

    A.SetHoanhDo(A.GetHoanhDo() * soLan);
    A.SetTungDo(A.GetTungDo() * soLan);

    B.SetHoanhDo(B.GetHoanhDo() * soLan);
    B.SetTungDo(B.GetTungDo() * soLan);

    C.SetHoanhDo(C.GetHoanhDo() * soLan);
    C.SetTungDo(C.GetTungDo() * soLan);
}

/**
 * @brief Thu nhỏ tam giác theo tỷ lệ soLan.
 * @param soLan Hệ số thu nhỏ tam giác.
 */
void TamGiac::ThuNho(float soLan) {
    if (soLan == 0) return;
    
    A.SetHoanhDo(A.GetHoanhDo() / soLan);
    A.SetTungDo(A.GetTungDo() / soLan);

    B.SetHoanhDo(B.GetHoanhDo() / soLan);
    B.SetTungDo(B.GetTungDo() / soLan);

    C.SetHoanhDo(C.GetHoanhDo() / soLan);
    C.SetTungDo(C.GetTungDo() / soLan);
}

/**
 * @brief Quay tam giác quanh gốc tọa độ một góc gocQuay (tính bằng radian).
 * @param gocQuay Góc quay tính bằng radian.
 */
void TamGiac::Quay(float gocQuay) {
    A.SetHoanhDo(A.GetHoanhDo() * cos(gocQuay) - A.GetTungDo() * sin(gocQuay));
    A.SetTungDo(A.GetHoanhDo() * sin(gocQuay) + A.GetTungDo() * cos(gocQuay));

    B.SetHoanhDo(B.GetHoanhDo() * cos(gocQuay) - B.GetTungDo() * sin(gocQuay));
    B.SetTungDo(B.GetHoanhDo() * sin(gocQuay) + B.GetTungDo() * cos(gocQuay));

    C.SetHoanhDo(C.GetHoanhDo() * cos(gocQuay) - C.GetTungDo() * sin(gocQuay));
    C.SetTungDo(C.GetHoanhDo() * sin(gocQuay) + C.GetTungDo() * cos(gocQuay));
}
