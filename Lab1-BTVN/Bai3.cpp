#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo { 
    int tuso;  // Tử số
    int mauso; // Mẫu số
};

void nhap(PhanSo& ps) {
    cin >> ps.tuso >> ps.mauso;

    while (ps.mauso == 0) {
        cout << "(!) Mau so khong hop le, yeu cau nhap lai mau so: ";
        cin >> ps.mauso;
    }
}

ostream& operator<<(ostream& os, const PhanSo& ps) {
    os << ps.tuso << "/" << ps.mauso;
    return os;
}

bool operator<(const PhanSo& a, const PhanSo& b) {
    return a.tuso * b.mauso < b.tuso * a.mauso; 
}

bool operator>(const PhanSo& a, const PhanSo& b) {
    return a.tuso * b.mauso > b.tuso * a.mauso; 
}

bool operator==(const PhanSo& a, const PhanSo& b) {
    return a.tuso * b.mauso == a.mauso * b.tuso;
}

PhanSo operator*(const PhanSo& a, const PhanSo& b) {
    PhanSo result = {a.tuso * b.tuso, a.mauso * b.mauso};
    return result;
}

void timTapHopCon(PhanSo* dsPhanSo, PhanSo* tapHopCon, int tapHopConSize, PhanSo tichHienTai, int idx, int n, const PhanSo& phanSoDich, PhanSo* ketQua, int& soPhanTuItNhat, int& ketQuaSize) {
    if (tichHienTai == phanSoDich) {
        if (tapHopConSize < soPhanTuItNhat) {
            soPhanTuItNhat = tapHopConSize;
            for (int i = 0; i < tapHopConSize; ++i) 
                ketQua[i] = tapHopCon[i];
            
            ketQuaSize = tapHopConSize;
        }
        return;
    }
    
    if (idx >= n) return;

    // Không chọn phân số hiện tại
    timTapHopCon(dsPhanSo, tapHopCon, tapHopConSize, tichHienTai, idx + 1, n, phanSoDich, ketQua, soPhanTuItNhat, ketQuaSize);

    // Chọn phân số hiện tại
    tapHopCon[tapHopConSize] = dsPhanSo[idx];
    timTapHopCon(dsPhanSo, tapHopCon, tapHopConSize + 1, tichHienTai * dsPhanSo[idx], idx + 1, n, phanSoDich, ketQua, soPhanTuItNhat, ketQuaSize);
}

int main() {
    cout << "Nhap so luong phan so: ";
    int n;  cin >> n;

    PhanSo *dsPhanSo = new PhanSo[n];
    for(int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i+1 << " (tuso mauso): ";
        nhap(dsPhanSo[i]);
    }

        PhanSo phanSoDich;
    cout << "Nhap phan so dich (tuso mauso): ";
    nhap(phanSoDich);

    PhanSo* tapHopCon = new PhanSo[n];
    PhanSo* ketQua = new PhanSo[n];
    PhanSo tichHienTai = {1, 1}; 
    int soPhanTuItNhat = n + 1;   // Số lượng phần tử ít nhất
    int ketQuaSize = 0;

    timTapHopCon(dsPhanSo, tapHopCon, 0, tichHienTai, 0, n, phanSoDich, ketQua, soPhanTuItNhat, ketQuaSize);
    
    if (ketQuaSize > 0) {
        sort(ketQua, ketQua + ketQuaSize);
        for(int i = 0; i < ketQuaSize; ++i) {
            cout << "Phan so thu " << i+1 << ": " << ketQua[i] << endl;
        }
    }
    // for(int i = 0; i < n; ++i) {
    //     cout << "Phan so thu " << i+1 << ": " << dsPhanSo[i] << endl;
    // }

    delete[] dsPhanSo;
    return 0;
}
