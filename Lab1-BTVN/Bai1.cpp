#include <iostream>
using namespace std;

struct PhanSo { 
    int tuso;  // Tử số
    int mauso; // Mẫu số
};

void nhap(PhanSo& ps) {
    cin >> ps.tuso >> ps.mauso;

    while (ps.mauso == 0) {
        cout << "(!) Mau so khong hop le, yeu cau nhap lai: ";
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

PhanSo timPhanSoNhoNhat(PhanSo *dsPhanSo, int n) {
    PhanSo minPS = dsPhanSo[0];

    for(int i = 1; i < n; ++i) 
        if (dsPhanSo[i] < minPS) 
            minPS = dsPhanSo[i];

    return minPS;
}

PhanSo timPhanSoLonNhat(PhanSo *dsPhanSo, int n) {
    PhanSo maxPS = dsPhanSo[0];

    for(int i = 1; i < n; ++i) 
        if (dsPhanSo[i] > maxPS) 
            maxPS = dsPhanSo[i];

    return maxPS;
}

int main() {
    cout << "Nhap so luong phan so: ";
    int n;  cin >> n;

    PhanSo *dsPhanSo = new PhanSo[n];
    for(int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i+1 << ": ";
        nhap(dsPhanSo[i]);
    }
    
    cout << "Phan so lon nhat: " << timPhanSoLonNhat(dsPhanSo, n) << endl;
    cout << "Phan so nho nhat: " << timPhanSoNhoNhat(dsPhanSo, n) << endl;


    delete[] dsPhanSo;
    return 0;
}
