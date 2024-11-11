#include "PhanSo.cpp"

int main() {
    cout << "Nhap phan so 1 (a hoac a/b): ";
    PhanSo ps1;     cin >> ps1;

    cout << "Nhap phan so 2 (a hoac a/b): ";
    PhanSo ps2;     cin >> ps2;

    cout << "--> Phan so 1 : " << ps1 << '\n';
    cout << "--> Phan so 2 : " << ps2 << '\n';
    cout << "--> Tong 2 phan so: " << ps1 + ps2 << '\n';
    cout << "--> Hieu 2 phan so: " << ps1 - ps2 << '\n';
    cout << "--> Tich 2 phan so: " << ps1 * ps2 << '\n';
    cout << "--> Thuong 2 phan so: " << ps1 / ps2 << '\n';

    cout << "--> 2 phan so co bang nhau? " << ((ps1 == ps2)? "Dung" : "Sai") << '\n';
    cout << "--> 2 phan so co khac nhau? " << ((ps1 != ps2)? "Dung" : "Sai") << '\n';
    cout << "--> Phan so 1 lon hon bang phan so 2? " << ((ps1 >= ps2)? "Dung" : "Sai") << '\n';
    cout << "--> Phan so 1 be hon bang phan so 2? " << ((ps1 <= ps2)? "Dung" : "Sai") << '\n';
    cout << "--> Phan so 1 lon hon phan so 2? " << ((ps1 > ps2)? "Dung" : "Sai") << '\n'; 
    cout << "--> Phan so 1 be hon phan so 2? " << ((ps1 < ps2)? "Dung" : "Sai") << '\n';

    return 0;
}
