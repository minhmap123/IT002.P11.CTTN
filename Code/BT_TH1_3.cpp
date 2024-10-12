#include <iostream>
#include <numeric>
using namespace std;

struct PhanSo { 
    int tu;  // Tử số
    int mau; // Mẫu số
};

/**
 * Hàm rút gọn phân số.
 * Chia cả tử số và mẫu số cho ước chung lớn nhất (UCLN) để đơn giản hóa phân số.
 * Nếu mẫu số âm, sẽ chuyển dấu để mẫu số luôn dương.
 * 
 * @param ps Phân số cần rút gọn (truyền tham chiếu).
 */
void rutGon(PhanSo& ps) {
    int ucln = gcd(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;

    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
}

/**
 * Hàm kiểm tra phân số.
 * Nếu mẫu số bằng 0, ném ra ngoại lệ invalid_argument.
 * 
 * @param ps Phân số cần kiểm tra (truyền tham chiếu hằng).
 * @throws invalid_argument Nếu mẫu số bằng 0.
 */
void kiemtra(const PhanSo& ps) {
    if (ps.mau == 0) 
        throw invalid_argument("Mau so khong the bang 0!"); 
}

/**
 * Hàm nhập phân số từ người dùng.
 * Yêu cầu người dùng nhập tử số và mẫu số, sau đó kiểm tra và rút gọn phân số.
 * 
 * @param ps Phân số cần nhập (truyền tham chiếu).
 * @throws invalid_argument Nếu mẫu số bằng 0.
 */
void nhap(PhanSo& ps) {
    cout << "\tNhap tu so: ";     cin >> ps.tu;
    cout << "\tNhap mau so: ";    cin >> ps.mau;
    kiemtra(ps);
    rutGon(ps);
}

/**
 * Toán tử cộng hai phân số.
 * Tính tổng hai phân số và trả về kết quả sau khi rút gọn.
 * 
 * @param ps1 Phân số thứ nhất.
 * @param ps2 Phân số thứ hai.
 * @return Phân số là tổng của hai phân số.
 */
PhanSo operator+(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo kq;
    kq.tu = ps2.tu * ps1.mau + ps1.tu * ps2.mau;
    kq.mau = ps2.mau * ps1.mau;
    rutGon(kq);
    return kq;
}

/**
 * Toán tử trừ hai phân số.
 * Tính hiệu của hai phân số và trả về kết quả sau khi rút gọn.
 * 
 * @param ps1 Phân số thứ nhất.
 * @param ps2 Phân số thứ hai.
 * @return Phân số là hiệu của hai phân số.
 */
PhanSo operator-(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutGon(kq);
    return kq;
}

/**
 * Toán tử nhân hai phân số.
 * Tính tích của hai phân số và trả về kết quả sau khi rút gọn.
 * 
 * @param ps1 Phân số thứ nhất.
 * @param ps2 Phân số thứ hai.
 * @return Phân số là tích của hai phân số.
 */
PhanSo operator*(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    rutGon(kq);
    return kq;
}

/**
 * Toán tử chia hai phân số.
 * Tính thương của hai phân số và trả về kết quả sau khi rút gọn.
 * Nếu tử số của phân số thứ hai bằng 0, ném ra ngoại lệ.
 * 
 * @param ps1 Phân số thứ nhất.
 * @param ps2 Phân số thứ hai.
 * @throws invalid_argument Nếu tử số của phân số thứ hai bằng 0.
 * @return Phân số là thương của hai phân số.
 */
PhanSo operator/(const PhanSo& ps1, const PhanSo& ps2) {
    if (ps2.tu == 0) 
        throw invalid_argument("Mau so khong the bang 0!");  

    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    rutGon(kq);
    return kq;
}

/**
 * Toán tử xuất ra phân số.
 * In phân số dưới dạng "tử/mẫu" hoặc chỉ in tử số nếu mẫu số là 1.
 * 
 * @param os Luồng đầu ra (ostream).
 * @param ps Phân số cần xuất ra (truyền tham chiếu hằng).
 * @return Trả về luồng đầu ra (ostream).
 */
ostream& operator<<(ostream& os, const PhanSo& ps) {
    if (ps.mau == 1) 
        os << ps.tu;
    else
        os << ps.tu << "/" << ps.mau;
    return os;
}

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so 1\n";
    nhap(ps1);

    cout << "Nhap phan so 2\n";
    nhap(ps2);

    cout << "\n\n";
    cout << "Phan so 1: " << ps1 << '\n';
    cout << "Phan so 2: " << ps2 << '\n';
    cout << "Tong: " << ps1 + ps2 << '\n';
    cout << "Hieu: " << ps1 - ps2 << '\n';
    cout << "Tich: " << ps1 * ps2 << '\n';
    cout << "Thuong: " << ps1 / ps2 << '\n';
}
