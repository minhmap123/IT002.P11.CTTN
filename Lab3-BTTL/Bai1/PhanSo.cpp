#pragma once

#include <numeric>  // gcd()
#include <stdexcept> // invalid_argument
#include <sstream>
#include "PhanSo.h"

/**
 * @brief Khởi tạo một phân số mặc định là 0/1.
 */
PhanSo::PhanSo() : iTu(0), iMau(1) {}

/**
 * @brief Khởi tạo một phân số với tử số và mẫu số.
 * @param Tu Tử số.
 * @param Mau Mẫu số (phải khác 0).
 * @throws std::invalid_argument nếu mẫu số bằng 0.
 */
PhanSo::PhanSo(int Tu, int Mau = 1) : iTu(Tu), iMau(Mau) {
    if (iMau == 0) 
        throw invalid_argument("(!) Mau so khong the bang 0");

    int GCD = gcd(iTu, iMau);
    iTu = iTu / GCD;
    iMau = iMau / GCD;

    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

/**
 * @brief Toán tử cộng hai phân số.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return Phân số kết quả của phép cộng.
 */
PhanSo operator + (const PhanSo& a, const PhanSo& b) {
    int Tu = a.iTu * b.iMau + b.iTu * a.iMau;
    int Mau = a.iMau * b.iMau;
    return PhanSo(Tu, Mau);
}

/**
 * @brief Toán tử trừ hai phân số.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return Phân số kết quả của phép trừ.
 */
PhanSo operator - (const PhanSo& a, const PhanSo& b) {
    int Tu = a.iTu * b.iMau - b.iTu * a.iMau;
    int Mau = a.iMau * b.iMau;
    return PhanSo(Tu, Mau);
}

/**
 * @brief Toán tử nhân hai phân số.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return Phân số kết quả của phép nhân.
 */
PhanSo operator * (const PhanSo& a, const PhanSo& b) {
    int Tu = a.iTu * b.iTu;
    int Mau = a.iMau * b.iMau;
    return PhanSo(Tu, Mau);
}

/**
 * @brief Toán tử chia hai phân số.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return Phân số kết quả của phép chia.
 * @throws std::runtime_error nếu chia cho phân số có tử số bằng 0.
 */
PhanSo operator / (const PhanSo& a, const PhanSo& b) {
    if (b.iTu == 0) {
        cerr << "\nLoi: Khong the thuc hien phep chia cho 0. Tra ve gia tri mac dinh 0/1" << endl;
        return PhanSo(0, 1);
    }
    int Tu = a.iTu * b.iMau;
    int Mau = a.iMau * b.iTu;
    return PhanSo(Tu, Mau);
}

/**
 * @brief So sánh bằng hai phân số.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return true nếu hai phân số bằng nhau, ngược lại là false.
 */
bool operator == (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau == b.iTu * a.iMau);
}

/**
 * @brief So sánh khác hai phân số.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return true nếu hai phân số khác nhau, ngược lại là false.
 */
bool operator != (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau != b.iTu * a.iMau);
}

/**
 * @brief So sánh lớn hơn bằng.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return true nếu phân số thứ nhất lớn hơn bằng phân số thứ hai, ngược lại là false.
 */
bool operator >= (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau >= b.iTu * a.iMau);
}

/**
 * @brief So sánh bé hơn bằng.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return true nếu phân số thứ nhất bé hơn bằng phân số thứ hai, ngược lại là false.
 */
bool operator <= (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau <= b.iTu * a.iMau);
}

/**
 * @brief So sánh lớn hơn.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return true nếu phân số thứ nhất lớn hơn phân số thứ hai, ngược lại là false.
 */
bool operator > (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau > b.iTu * a.iMau);
}

/**
 * @brief So sánh bé hơn.
 * @param a Phân số thứ nhất.
 * @param b Phân số thứ hai.
 * @return true nếu phân số thứ nhất bé hơn phân số thứ hai, ngược lại là false.
 */
bool operator < (const PhanSo& a, const PhanSo& b) {
    return (a.iTu * b.iMau < b.iTu * a.iMau);
}

/**
 * @brief Toán tử xuất phân số ra luồng.
 * @param os Luồng đầu ra.
 * @param ps Phân số.
 * @return Luồng đầu ra với phân số được xuất.
 */
ostream& operator << (ostream &os, const PhanSo& ps) {
    os << ps.iTu << '/' << ps.iMau;
    return os;
}

/**
 * @brief Toán tử nhập phân số từ luồng.
 *        Cho phép nhập phân số dạng "a/b" hoặc "a".
 * @param is Luồng đầu vào.
 * @param ps Phân số.
 * @return Luồng đầu vào sau khi đọc phân số.
 * @throws std::invalid_argument nếu mẫu số bằng 0.
 */
istream& operator >> (istream &is, PhanSo& ps) {
    string input;
    is >> input;

    size_t vitri = input.find('/');
    if (vitri != string::npos) {
        ps.iTu = stoi(input.substr(0, vitri));
        ps.iMau = stoi(input.substr(vitri+1));
    }
    else 
        ps.iTu = stoi(input);

    if (ps.iMau == 0) 
        throw invalid_argument("(!) Mau so khong the bang 0");

    int GCD = gcd(ps.iTu, ps.iMau);
    ps.iTu = ps.iTu / GCD;
    ps.iMau = ps.iMau / GCD;

    if (ps.iMau < 0) {
        ps.iTu = -ps.iTu;
        ps.iMau = -ps.iMau;
    }
    return is;
}

