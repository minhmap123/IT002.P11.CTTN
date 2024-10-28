# pragma once

#include <iostream>
#include "Diem.h"
using namespace std;

/**
 * @brief Hàm tạo không tham số, khởi tạo một điểm tại gốc tọa độ (0, 0).
 */
Diem::Diem() {
    iHoanh = 0;
    iTung = 0;
}

/**
 * @brief Hàm tạo với giá trị hoành độ và tung độ cho trước.
 * @param Hoanh Giá trị hoành độ.
 * @param Tung Giá trị tung độ.
 */
Diem::Diem(float Hoanh, float Tung) {
    iHoanh = Hoanh;
    iTung = Tung;
}

/**
 * @brief Hàm tạo sao chép, khởi tạo một điểm mới với tọa độ của một điểm khác.
 * @param x Đối tượng Diem để sao chép.
 */
Diem::Diem(const Diem& x) {
    this->iHoanh = x.iHoanh;
    this->iTung = x.iTung;
}

/**
 * @brief Xuất tọa độ của điểm ra màn hình dưới dạng (hoành độ, tung độ).
 */
void Diem::Xuat() {
    // cout << "Toa do cua diem: \n";
    // cout << "\tHoanh do: " << iHoanh << '\n';
    // cout << "\tTung do: " << iTung << '\'n';
    cout << '(' << iHoanh << ", " << iTung << ')'; 
}

/**
 * @brief Lấy giá trị tung độ của điểm.
 * @return Giá trị tung độ.
 */
float Diem::GetTungDo() {
    return iTung;
}

/**
 * @brief Lấy giá trị tung độ của điểm.
 * @return Giá trị tung độ.
 */
float Diem::GetHoanhDo() {
    return iHoanh;
}

/**
 * @brief Đặt giá trị tung độ mới cho điểm.
 * @param Tung Giá trị tung độ mới.
 */
void Diem::SetTungDo(float Tung) {
    iTung = Tung;
}

/**
 * @brief Đặt giá trị hoành độ mới cho điểm.
 * @param Hoanh Giá trị hoành độ mới.
 */
void Diem::SetHoanhDo(float Hoanh) {
    iHoanh = Hoanh;
}

/**
 * @brief Dịch chuyển điểm theo vector (x, y) cho trước.
 * @param x Giá trị dịch chuyển theo trục x.
 * @param y Giá trị dịch chuyển theo trục y.
 */
void Diem::TinhTien(float x, float y) {
    iHoanh += x;
    iTung += y;
}
