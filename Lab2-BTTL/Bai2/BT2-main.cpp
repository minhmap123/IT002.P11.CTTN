#include "TamGiac.cpp"

int main() {
    TamGiac tg;

    tg.Nhap();
    tg.Xuat();

    cout << "Nhap toa do de tinh tien tam giac: ";
    float x, y;     cin >> x >> y;
    tg.TinhTien(x, y);
    tg.Xuat();

    cout << "Nhap so lan ban muon phong to tam giac: ";
    float soLan;    cin >> soLan;
    tg.PhongTo(soLan);
    tg.Xuat();

    cout << "Nhap so lan ban muon thu nho tam giac: ";
    cin >> soLan;
    tg.ThuNho(soLan);
    tg.Xuat();

    cout << "Nhap goc quay ban muon quay (radian): ";
    float gocQuay;  cin >> gocQuay;
    tg.Quay(gocQuay);
    tg.Xuat();

    return 0;
}
