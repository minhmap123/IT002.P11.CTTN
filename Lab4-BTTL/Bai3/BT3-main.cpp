#include "GiaSuc.cpp"
#include <ctime>

int main() {
    // Nhập thông tin số lượng gia súc, tổng sữa ban đầu là 0
    int soLuongBo, soLuongCuu, soLuongDe;

    cout << "Nhap so luong bo ban dau: ";
    cin >> soLuongBo;
    Bo bo(soLuongBo, 0); 

    cout << "Nhap so luong cuu ban dau: ";
    cin >> soLuongCuu;
    Cuu cuu(soLuongCuu, 0); 

    cout << "Nhap so luong de ban dau: ";
    cin >> soLuongDe;
    De de(soLuongDe, 0); 


    // Gia súc kêu khi đói
    cout << "\nTat ca gia suc deu doi:" << endl;
    bo.keu();
    cuu.keu();
    de.keu();

    // Thống kê sau một lứa sinh và cho sữa
    cout << "\n\nThong ke sau mot luot sinh va cho sua:" << endl;

    bo.sinhCon();
    cuu.sinhCon();
    de.sinhCon();

    bo.choSua();
    cuu.choSua();
    de.choSua();

    cout << "\nTong so gia suc va sua:" << endl;
    cout << "Bo: " << bo.getSoLuong() << " con, " << bo.getTongSua() << " lit sua." << endl;
    cout << "Cuu: " << cuu.getSoLuong() << " con, " << cuu.getTongSua() << " lit sua." << endl;
    cout << "De: " << de.getSoLuong() << " con, " << de.getTongSua() << " lit sua." << endl;

    return 0;
}
