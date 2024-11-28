#include "Prince.cpp"
#include "Castle.cpp"

#include<iostream>
using namespace std;


int main() {
    Castle castle;
    castle.Nhap();

    Prince hoangTu;
    hoangTu.Nhap();

    if (castle.vuotQuaHetCong(hoangTu)) {
        cout << "Hoang tu cuu duoc Cong chua!\n";
        hoangTu.hienThiTrangThai();
    }
    else 
        cout << "Hoang tu khong the cuu duoc cong chua.\n";

    return 0;
}
