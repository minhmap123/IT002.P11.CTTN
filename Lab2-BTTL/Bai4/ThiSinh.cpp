#pragma once

#include <iostream>
#include "ThiSinh.h"

/**
 * @brief Nhập thông tin của thí sinh từ bàn phím, bao gồm tên, MSSV, ngày sinh và điểm các môn Toán, Văn, Anh.
 */
void ThiSinh::Nhap() {
    cout << "\tNhap ten thi sinh: ";
    cin.ignore();
    getline(cin, Ten);

    cout << "\tNhap MSSV: ";
    getline(cin, MSSV);

    cout << "\tNhap ngay sinh (dd mm yyyy): ";
    cin >> iNgay >> iThang >> iNam;

    cout << "\tNhap diem Toan: ";
    cin >> fToan;

    cout << "\tNhap diem Van: ";
    cin >> fVan;

    cout << "\tNhap diem Anh: ";
    cin >> fAnh;
}

/**
 * @brief Xuất thông tin của thí sinh ra màn hình, bao gồm tên, MSSV, ngày sinh, điểm các môn và tổng điểm.
 */
void ThiSinh::Xuat() {
    cout << "\nThong tin thi sinh:\n";
    cout << "\tTen: " << Ten << endl;
    cout << "\tMSSV: " << MSSV << endl;
    cout << "\tNgay sinh: " << iNgay << "/" << iThang << "/" << iNam << endl;
    cout << "\tDiem Toan: " << fToan << endl;
    cout << "\tDiem Van: " << fVan << endl;
    cout << "\tDiem Anh: " << fAnh << endl;
    cout << "\tTong diem: " << Tong() << endl;
}

/**
 * @brief Xuất thông tin của thí sinh ra màn hình, bao gồm tên, MSSV, ngày sinh, điểm các môn và tổng điểm.
 */
float ThiSinh::Tong() {
    return fToan + fVan + fAnh;
}
