# pragma once

#include "Prince.h"
#include <iostream>
using namespace std;

Prince::Prince(int tienBanDau = 0, int triTueBanDau = 0, int sucManhBanDau = 0) 
    : soTien(tienBanDau), triTue(triTueBanDau), sucManh(sucManhBanDau) {}

void Prince::Nhap() {
    cout << "\nNhap chi so cho hoang tu: \n";
    
    cout << "\tNhap so tien ban dau: ";
    cin >> soTien;
    cout << "\tNhap chi so tri tue: ";
    cin >> triTue;
    cout << "\tNhap chi so suc manh: ";
    cin >> sucManh;
}

long long Prince::getTien() const { return soTien; }
int Prince::getTriTue() const { return triTue; }
int Prince::getSucManh() const { return sucManh; }

void Prince::setTien(int tien) { this->soTien = tien; }
void Prince::setSucManh(int sm) { this->sucManh = sm; }

void Prince::hienThiTrangThai() {
    cout << "\nTrang thai hien tai cua hoang tu: " << endl;
    cout << "\tSo tien hien co: " << soTien << endl;
    cout << "\tTri tue: " << triTue << endl;
    cout << "\tSuc manh: " << sucManh << endl;
}
