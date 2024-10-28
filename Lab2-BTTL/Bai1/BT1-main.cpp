#include "Diem.cpp"

int main() {
    cout << "--> Khoi tao mac dinh: ";
    Diem diem;  diem.Xuat();
    cout << '\n';

    float x, y;   

    cout << "Nhap toa do cho diem 1 (x  y): ";
    cin >> x >> y;  Diem diem1(x, y);   
    cout << "--> Toa do diem 1: ";  
    diem1.Xuat();
    cout << '\n';

    cout << "--> Sao chep diem 1 da co sang diem 2: ";
    Diem diem2(diem1);   diem2.Xuat();
    cout << '\n';

    cout << "--> Hoanh do cua diem 1: " << diem1.GetHoanhDo() << '\n';
    cout << "--> Tung do cua diem 1: " << diem1.GetTungDo() << '\n';

    cout << "Chinh sua hoanh do cua diem 1: ";
    cin >> x;
    diem1.SetHoanhDo(x);
    cout << "--> Toa do diem 1 sau chinh sua: "; 
    diem1.Xuat();
    cout << '\n';

    cout << "Chinh sua tung do cua diem 1: ";
    cin >> y;
    diem1.SetTungDo(y);
    cout << "--> Toa do diem 1 sau chinh sua: "; 
    diem1.Xuat();
    cout << '\n';

    cout << "Nhap don vi ban muon tinh tien diem 1: ";
    cin >> x >> y;
    diem1.TinhTien(x, y);
    cout << "--> Toa do diem 1 sau tinh tien: ";
    diem1.Xuat();

    return 0;
}
