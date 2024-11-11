#include "SoPhuc.cpp"

int main() {
    cout << "Nhap so phuc 1: ";
    SoPhuc sp1;     cin >> sp1;

    cout << "Nhap so phuc 2: ";
    SoPhuc sp2;     cin >> sp2;

    cout << "--> So phuc 1: " << sp1 << endl;
    cout << "--> So phuc 2: " << sp2 << endl;

    cout << "--> Tong 2 so phuc: " << sp1 + sp2 << endl;
    cout << "--> Hieu 2 so phuc: " << sp1 - sp2 << endl;
    cout << "--> Tich 2 so phuc: " << sp1 * sp2 << endl;
    cout << "--> Thuong 2 so phuc: " << sp1 / sp2 << endl;

    cout << "--> 2 so phuc co bang nhau khong? " << ((sp1 == sp2) ? "Dung" : "Sai") << endl;
    cout << "--> 2 so phuc co khac nhau khong? " << ((sp1 != sp2) ? "Dung" : "Sai") << endl; 
    return 0;
}
