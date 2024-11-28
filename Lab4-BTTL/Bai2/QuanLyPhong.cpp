# pragma once

#include "QuanLyPhong.h"

/**
 * @brief Constructor của lớp PhongKhachSan.
 * @param ma Mã số phòng (mặc định: rỗng).
 * @param dem Số đêm lưu trú (mặc định: 0).
 */
PhongKhachSan::PhongKhachSan(string ma = "", int dem = 0) : maPhong(ma), soDem(dem) {}

/**
 * @brief Nhập thông tin cơ bản của phòng.
 */
void PhongKhachSan::Nhap() {
    cout << "Nhap ma phong: ";  cin >> maPhong;
    cout << "Nhap so dem: ";    cin >> soDem;
}

/**
 * @brief Hiển thị thông tin cơ bản của phòng.
 */
void PhongKhachSan::Xuat() const {
    cout << "\tMa phong: " << maPhong;
    cout << "\tSo dem: " << soDem;
}

/**
 * @brief Constructor của lớp Deluxe.
 * @param ma Mã số phòng.
 * @param dem Số đêm lưu trú.
 * @param phiDV Phí dịch vụ.
 * @param phiPV Phí phục vụ.
 */
Deluxe::Deluxe(string ma = "", int dem = 0, long long phiDV = 0, long long phiPV = 0) 
    : PhongKhachSan(ma, dem), phiDichVu(phiDV), phiPhucVu(phiPV) {}

/**
 * @brief Nhập thông tin phòng Deluxe.
 */
void Deluxe::Nhap() {
    PhongKhachSan::Nhap();
    cout << "Nhap phi dich vu: ";     cin >> phiDichVu;
    cout << "Nhap phi phuc vu: ";     cin >> phiPhucVu;
}

/**
 * @brief Hiển thị thông tin phòng Deluxe.
 */
void Deluxe::Xuat() const {
    PhongKhachSan::Xuat();
    cout << "\tPhi dich vu: " << phiDichVu;
    cout << "\tPhi phuc vu: " << phiPhucVu;
    cout << "\tTong doanh thu: " << tinhDoanhThu() << endl;
}

/**
 * @brief Tính doanh thu của phòng Deluxe.
 * @return Doanh thu phòng = Số đêm * 750,000 + Phí dịch vụ + Phí phục vụ.
 */
long long Deluxe::tinhDoanhThu() const {
    return soDem * 750000 + phiDichVu + phiPhucVu;
}

/**
 * @brief Constructor của lớp Premium.
 * @param ma Mã số phòng.
 * @param dem Số đêm lưu trú.
 * @param phiDV Phí dịch vụ.
 */
Premium::Premium(string ma = "", int dem = 0, long long phiDV = 0) 
    : PhongKhachSan(ma, dem), phiDichVu(phiDV){}

/**
 * @brief Nhập thông tin phòng Premium.
 */
void Premium::Nhap() {
    PhongKhachSan::Nhap();
    cout << "Nhap phi dich vu: ";     cin >> phiDichVu;
}

/**
 * @brief Hiển thị thông tin phòng Premium.
 */
void Premium::Xuat() const {
    PhongKhachSan::Xuat();
    cout << "\tPhi dich vu: " << phiDichVu;
    cout << "\tTong doanh thu: " << tinhDoanhThu() << endl;
}

/**
 * @brief Tính doanh thu của phòng Premium.
 * @return Doanh thu phòng = Số đêm * 500,000 + Phí dịch vụ.
 */
long long Premium::tinhDoanhThu() const {
    return soDem * 500000 + phiDichVu;
}

/**
 * @brief Constructor của lớp Business.
 * @param ma Mã số phòng.
 * @param dem Số đêm lưu trú.
 */
Business::Business(string ma = "", int dem = 0) 
    : PhongKhachSan(ma, dem) {}

/**
 * @brief Hiển thị thông tin phòng Business.
 */
void Business::Xuat() const {
    PhongKhachSan::Xuat();
    cout << "\tTong doanh thu: " << tinhDoanhThu() << endl;
}

/**
 * @brief Tính doanh thu của phòng Business.
 * @return Doanh thu phòng = Số đêm * 300,000.
 */
long long Business::tinhDoanhThu() const {
    return soDem * 300000;
}

