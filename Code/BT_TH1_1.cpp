#include <iostream>
#include <numeric>  // gcd()
using namespace std;

struct PhanSo { 
    int tu;  // Tử số
    int mau; // Mẫu số
};

/**
 * Hàm rút gọn phân số.
 * Chia cả tử số và mẫu số của phân số cho ước chung lớn nhất (UCLN).
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
 * Nếu mẫu số bằng 0, ném ra ngoại lệ invalid_argument và kết thúc chương trình.
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
 * Yêu cầu người dùng nhập tử số và mẫu số, sau đó rút gọn phân số.
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
    PhanSo ps;
    cout << "Nhap phan so: \n";
    nhap(ps);

    cout << "-> Phan so sau khi rut gon: " << ps;
    return 0;
}
