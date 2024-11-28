# pragma once

#include <iostream>
#include <string>
using namespace std;

/**
 * @class NhanVien
 * @brief Lớp cơ sở đại diện cho một nhân viên với các thuộc tính và phương thức cơ bản.
 */
class NhanVien {
protected: 
    string maNhanVien;  // Mã số nhân viên
    string hoTen;       // Họ và tên nhân viên
    long long luongCoBan;   // Lương cơ bản của nhân viên

public:
    NhanVien();
    NhanVien(string, string, long long);

    void Nhap();
    void Xuat();
};

/**
 * @class QuanLy
 * @brief Lớp đại diện cho nhân viên quản lý, kế thừa từ lớp NhanVien.
 */
class QuanLy : public NhanVien {
private:
    float tyleThuong;      // Tỷ lệ thưởng của quản lý
public:
    long long TienThuong();

    void Nhap();
    void Xuat();
};

/**
 * @class KySu
 * @brief Lớp đại diện cho nhân viên kỹ sư, kế thừa từ lớp NhanVien.
 */
class KySu : public NhanVien {
private:
    float soGioLamThem;     // Số giờ làm thêm của kỹ sư.

public:
    long long TienThuong();

    void Nhap();
    void Xuat();
};

