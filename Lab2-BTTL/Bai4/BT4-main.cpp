#include "ThiSinh.cpp"

int main() {
    int n;

    cout << "Nhap so luong thi sinh: ";
    cin >> n;

    ThiSinh* dsThiSinh = new ThiSinh[n];
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        dsThiSinh[i].Nhap();
    }

    cout << "\n---------------------------------------------------\n";
    cout << "\nDanh sach thi sinh co tong diem lon hon 15:\n";
    for (int i = 0; i < n; i++) 
        if (dsThiSinh[i].Tong() > 15) 
            dsThiSinh[i].Xuat();
        
    int viTriDiemCaoNhat = 0;
    for (int i = 1; i < n; i++) 
        if (dsThiSinh[i].Tong() > dsThiSinh[viTriDiemCaoNhat].Tong()) 
            viTriDiemCaoNhat = i;
    
    cout << "\n---------------------------------------------------\n";
    cout << "\nThi sinh co tong diem cao nhat la:\n";
    dsThiSinh[viTriDiemCaoNhat].Xuat();

    delete[] dsThiSinh;
    return 0;
}
