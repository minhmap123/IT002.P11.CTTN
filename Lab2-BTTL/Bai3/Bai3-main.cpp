#include "DaGiac.cpp"

int main() {
    DaGiac dg;

    dg.Nhap();
    dg.Xuat();

    cout << "Nhap toa do de tinh tien da giac: ";
    float x, y;     cin >> x >> y;
    dg.TinhTien(x, y);
    dg.Xuat();

    cout << "Nhap so lan ban muon phong to da giac: ";
    float soLan;    cin >> soLan;
    dg.PhongTo(soLan);
    dg.Xuat();

    cout << "Nhap so lan ban muon thu nho da giac: ";
    cin >> soLan;
    dg.ThuNho(soLan);
    dg.Xuat();

    cout << "Nhap goc quay ban muon quay (radian): ";
    float gocQuay;  cin >> gocQuay;
    dg.Quay(gocQuay);
    dg.Xuat();

    return 0;
}
