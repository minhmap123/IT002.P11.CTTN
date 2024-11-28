# pragma once

#include "QuanLyNhanVien.h"

/**
 * @brief Constructor mặc định, khởi tạo các thuộc tính cơ bản.
 */
NhanVien::NhanVien() : maNhanVien(""), hoTen(""), luongCoBan(0) {}

/**
 * @brief Constructor có tham số, khởi tạo các thuộc tính với giá trị cụ thể.
 * @param ma Mã số nhân viên.
 * @param ht Họ và tên nhân viên.
 * @param lCB Lương cơ bản của nhân viên.
 */
NhanVien::NhanVien(string ma, string ht, long long lCB)
    : maNhanVien(ma), hoTen(ht), luongCoBan(lCB) {}

/**
 * @brief Nhập thông tin của nhân viên.
 */
void NhanVien::Nhap() {
    cout << "\tNhap ma nhan vien: ";  cin >> maNhanVien;
    cin.ignore();
    cout << "\tNhap ho va ten: ";     getline(cin, hoTen);
    cout << "\tNhap luong co ban: ";  cin >> luongCoBan;
}

/**
 * @brief Hiển thị thông tin chi tiết của nhân viên.
 */
void NhanVien::Xuat() {
    cout << "\tMa nhan vien: " << maNhanVien << endl;
    cout << "\tHo ten: " << hoTen << endl;
    cout << "\tLuong co ban: " << luongCoBan << endl;
}

/**
 * @brief Tính tiền thưởng của quản lý.
 * @return Tiền thưởng dựa trên tỷ lệ thưởng và lương cơ bản.
 */
long long QuanLy::TienThuong() {
    return luongCoBan * (tyleThuong);
}

/**
 * @brief Nhập thông tin của quản lý.
 */
void QuanLy::Nhap() {
    NhanVien::Nhap();
    cout << "\tNhap ty le thuong (0-100): ";  cin >> tyleThuong;
    tyleThuong /= 100;
}

/**
 * @brief Hiển thị thông tin chi tiết của quản lý.
 */
void QuanLy::Xuat() {
    NhanVien::Xuat();
    cout << "\tTien thuong: " << TienThuong() << endl;
}

/**
 * @brief Tính tiền thưởng của kỹ sư.
 * @return Tiền thưởng dựa trên số giờ làm thêm.
 */
long long KySu::TienThuong() {
    return soGioLamThem * 100000;
}

/**
 * @brief Nhập thông tin của kỹ sư.
 */
void KySu::Nhap() {
    NhanVien::Nhap();
    cout << "\tNhap so gio lam them: ";   cin >> soGioLamThem;
}

/**
 * @brief Hiển thị thông tin chi tiết của kỹ sư.
 */
void KySu::Xuat() {
    NhanVien::Xuat();
    cout << "\tTien thuong: " << TienThuong() << endl;
}
