#include "DaGiac.h"
#include <cmath>

/**
 * @brief Nhập tọa độ cho các đỉnh của đa giác từ người dùng.
 *        Yêu cầu số lượng đỉnh phải lớn hơn 0.
 */
void DaGiac::Nhap() {
    cout << "Nhap so luong dinh cua da giac: ";
    cin >> n;
    while (n <= 0) {
        cout << "(!) So luuong dinh khong hop le, vui long nhap lai: ";
        cin >> n;
    }

    Dinh = new Diem[n];
    cout << "Nhap lan luot toa do tung diem cua da giac:\n";

    float x, y;
    for(int i = 0; i < n; ++i) {
        cout << "Nhap toa do dinh thu " << i+1 << " (x  y): ";
        cin >> x >> y;
        Dinh[i] = Diem(x, y);
    }
}

/**
 * @brief Xuất tọa độ của tất cả các đỉnh của đa giác ra màn hình.
 */
void DaGiac::Xuat() {
    cout << "Toa do cac dinh cua da giac:\n";
    for(int i = 0; i < n; ++i) {
        cout << "\tDinh " << i+1 << ": ";    Dinh[i].Xuat();   cout << '\n';
    }
}

/**
 * @brief Tịnh tiến toàn bộ đa giác theo vector (x, y).
 * @param x Khoảng cách tịnh tiến theo trục hoành.
 * @param y Khoảng cách tịnh tiến theo trục tung.
 */
void DaGiac::TinhTien(float x, float y) {
    for(int i = 0; i < n; ++i) 
        Dinh[i].TinhTien(x, y);
}

/**
 * @brief Phóng to đa giác theo hệ số tỷ lệ soLan.
 * @param soLan Hệ số phóng to đa giác.
 */
void DaGiac::PhongTo(float soLan) {
    if (soLan == 0) return;

    for(int i = 0; i < n; ++i) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() * soLan);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() * soLan);
    }
}

/**
 * @brief Thu nhỏ đa giác theo hệ số tỷ lệ soLan.
 * @param soLan Hệ số thu nhỏ đa giác.
 */
void DaGiac::ThuNho(float soLan) {
    if (soLan == 0) return;
    
    for(int i = 0; i < n; ++i) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() / soLan);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() / soLan);
    }
}

/**
 * @brief Quay đa giác quanh gốc tọa độ một góc gocQuay (tính bằng radian).
 * @param gocQuay Góc quay tính bằng radian.
 */
void DaGiac::Quay(float gocQuay) {
    for(int i = 0; i < n; ++i) {
        float x = Dinh[i].GetHoanhDo();
        float y = Dinh[i].GetTungDo();

        Dinh[i].SetHoanhDo(x * cos(gocQuay) - y * sin(gocQuay));
        Dinh[i].SetTungDo(x * sin(gocQuay) + y * cos(gocQuay));
    }
}

/**
 * @brief Tính diện tích của đa giác bằng công thức Shoelace.
 * 
 * https://en.wikipedia.org/wiki/Shoelace_formula
 * 
 * @return Diện tích của đa giác (đơn vị diện tích).
 */
float DaGiac::TinhDienTich() {
    float S = 0;

    // Dùng công thức Shoelace để tính diện tích
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;  
        S += Dinh[i].GetHoanhDo() * Dinh[j].GetTungDo() - Dinh[i].GetTungDo() * Dinh[j].GetHoanhDo();
    }

    return fabs(S) / 2.0;  
}

/**
 * @brief Hàm hủy của đa giác, giải phóng bộ nhớ đã cấp phát cho mảng các đỉnh.
 */
DaGiac::~DaGiac() {
    delete[] Dinh;
}
