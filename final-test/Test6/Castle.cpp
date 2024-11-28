# pragma once

#include "Castle.h"

#include <iostream>
using namespace std;



BusinessGate::BusinessGate(long long gia = 0, int so = 0) : donGia(gia), soHang(so) {}
    
bool BusinessGate::quaCong(Prince& hoangTu) {
    if (hoangTu.getTien() >= donGia * soHang) {
        hoangTu.setTien(hoangTu.getTien() - donGia * soHang);
        return true;
    } 
    else 
        return false;
}



AcademicGate::AcademicGate(int triTue = 0) : triTueCanThiet(triTue) {}

bool AcademicGate::quaCong(Prince& hoangTu) {
    return hoangTu.getTriTue() >= triTueCanThiet;
}



PowerGate::PowerGate(int sucManh = 0) : sucManhCanThiet(sucManh) {}

bool PowerGate::quaCong(Prince& hoangTu) {
    if (hoangTu.getSucManh() >= sucManhCanThiet) {
        hoangTu.setSucManh(hoangTu.getSucManh() - sucManhCanThiet);
        return true;
    }
    else 
        return false;
}



Castle::Castle(int n = 0) : soCong(n), dsGate(nullptr) {
    if (soCong > 0) 
        dsGate = new Gate*[soCong];
}

Castle::~Castle() {
    for (int i = 0; i < soCong; ++i)
        delete dsGate[i]; 
    delete[] dsGate; 
}

void Castle::Nhap() {
    cout << "Nhap danh sach N cong cua lau dai: ";
    cin >> soCong;
    dsGate = new Gate*[soCong];

    int loaiCong;
    for(int i = 0; i < soCong; ++i) {
        cout << "Nhap loai cong thu " << i+1 << " (1: Giao thuong, 2: Hoc Thuat, 3: Suc manh): ";
        cin >> loaiCong;

        switch (loaiCong)
        {
        case 1: {
            cout << "\tNhap don gia: ";
            long long gia;    cin >> gia;
            cout << "\tNhap so hang hoa: ";
            int so;     cin >> so;
            dsGate[i] = new BusinessGate(gia, so);
            break;
        }
        case 2: {
            cout << "\tNhap chi so tri tue cua nha hien triet: ";
            int triTue;     cin >> triTue;
            dsGate[i] = new AcademicGate(triTue);
            break;
        }
        case 3: {
            cout << "\tNhap chi so suc manh cua nguoi gac cong: ";
            int sucManh;    cin >> sucManh;
            dsGate[i] = new PowerGate(sucManh);
            break;
        }
        
        default:
            cout << "Loai cong khong hop le, vui long nhap lai.\n";
            --i;
            break;
        }
    }
}

bool Castle::vuotQuaHetCong(Prince& hoangTu) {
    for(int i = 0; i < soCong; ++i) 
        if (!dsGate[i]->quaCong(hoangTu)) {
            cout << "Hoang tu that bai tai cong thu " << i+1 << " .\n";
            return false;
        }
    return true;
}
