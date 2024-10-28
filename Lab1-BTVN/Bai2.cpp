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


int main() {
    cout << "Nhap so luong phan so: ";
    int n;  cin >> n;

    cout << "Nhap so thu k: ";
    int k; cin >> k;

    PhanSo *dsPhanSo = new PhanSo[n];
    for(int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i+1 << " (tuso mauso): ";
        nhap(dsPhanSo[i]);
    }

    sort(dsPhanSo, dsPhanSo + n);
    if (k >=0 && k <= n) {
        cout << "Phan so nho thu " << k << ": " << dsPhanSo[k-1] << endl;
        cout << "Phan so lon thu " << k << ": " << dsPhanSo[n-k] << endl;
    }

    // for(int i = 0; i < n; ++i) {
    //     cout << "Phan so thu " << i+1 << ": " << dsPhanSo[i] << endl;
    // }

    delete[] dsPhanSo;
    return 0;
}
