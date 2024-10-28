#include "Diem.cpp"

int main() {
    float x, y;

    cin >> x >> y;
    Diem diem1(x, y);

    cin >> x >> y;
    Diem diem2(x, y);
    
    cin >> x >> y;
    Diem diem3(x, y);

    float goc, doDai;
    cin >> goc >> doDai;

    diem1.TinhTien(goc, doDai);
    diem2.TinhTien(goc, doDai);
    diem3.TinhTien(goc, doDai);

    diem1.Xuat();   cout << '\n';
    diem2.Xuat();   cout << '\n';
    diem3.Xuat();   cout << '\n';

    return 0;
}
