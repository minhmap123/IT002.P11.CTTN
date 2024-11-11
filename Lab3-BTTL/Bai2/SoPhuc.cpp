#pragma once

#include "SoPhuc.h"


/**
 * @brief Khởi tạo số phức với phần thực và phần ảo mặc định là 0.
 */
SoPhuc::SoPhuc() : iThuc(0.0), iAo(0.0) {}

/**
 * @brief Khởi tạo số phức với phần thực và phần ảo được chỉ định.
 * @param thuc Phần thực của số phức.
 * @param ao Phần ảo của số phức. Mặc định là 0 nếu không chỉ định.
 */
SoPhuc::SoPhuc(float thuc, float ao = 0.0) : iThuc(thuc), iAo(ao) {}

/**
 * @brief Toán tử cộng hai số phức.
 * @param a Số phức thứ nhất.
 * @param b Số phức thứ hai.
 * @return Số phức kết quả của phép cộng.
 */
SoPhuc operator + (const SoPhuc& a, const SoPhuc& b) {
    return SoPhuc(a.iThuc + b.iThuc, a.iAo + b.iAo);
}

/**
 * @brief Toán tử trừ hai số phức.
 * @param a Số phức thứ nhất.
 * @param b Số phức thứ hai.
 * @return Số phức kết quả của phép trừ.
 */
SoPhuc operator - (const SoPhuc& a, const SoPhuc& b) {
    return SoPhuc(a.iThuc - b.iThuc, a.iAo - b.iAo);
}

/**
 * @brief Toán tử nhân hai số phức.
 * @param a Số phức thứ nhất.
 * @param b Số phức thứ hai.
 * @return Số phức kết quả của phép nhân.
 */
SoPhuc operator * (const SoPhuc& a, const SoPhuc& b) {
    float thuc = a.iThuc * b.iThuc - a.iAo * b.iAo;
    float ao = a.iThuc * b.iAo + a.iAo * b.iThuc;
    return SoPhuc(thuc, ao);
}

/**
 * @brief Toán tử chia hai số phức.
 * @param a Số phức thứ nhất.
 * @param b Số phức thứ hai.
 * @return Số phức kết quả của phép chia.
 * @throws std::runtime_error nếu số phức b có phần thực và phần ảo đều bằng 0.
 */
SoPhuc operator / (const SoPhuc& a, const SoPhuc& b) {
    float mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
    float thuc = (a.iThuc * b.iThuc + a.iAo * b.iAo) / mau;
    float ao = (a.iAo * b.iThuc - a.iThuc * b.iAo) / mau;
    return SoPhuc(thuc, ao);
}

/**
 * @brief So sánh hai số phức có bằng nhau không.
 * @param a Số phức thứ nhất.
 * @param b Số phức thứ hai.
 * @return true nếu hai số phức bằng nhau, ngược lại là false.
 */
bool operator == (const SoPhuc& a, const SoPhuc& b) {
    return (a.iThuc == b.iThuc) && (a.iAo == b.iAo); 
}

/**
 * @brief So sánh hai số phức có khác nhau không.
 * @param a Số phức thứ nhất.
 * @param b Số phức thứ hai.
 * @return true nếu hai số phức khác nhau, ngược lại là false.
 */
bool operator != (const SoPhuc& a, const SoPhuc& b) {
    return !(a == b); 
}

/**
 * @brief Toán tử xuất số phức ra luồng.
 * @param os Luồng đầu ra.
 * @param sp Số phức cần xuất.
 * @return Luồng đầu ra với số phức được xuất.
 */
ostream& operator << (ostream &os, const SoPhuc& sp) {
    os << sp.iThuc;
    if (sp.iAo >= 0) 
        os << " + " << sp.iAo << "i";
    else 
        os << " - " << -sp.iAo << "i";
    return os;
}

/**
 * @brief Toán tử nhập số phức từ luồng.
 * @param is Luồng đầu vào.
 * @param sp Số phức để lưu dữ liệu đầu vào.
 * @return Luồng đầu vào sau khi đọc số phức.
 */
istream& operator >> (istream &is, SoPhuc& sp) {
    is >> sp.iThuc >> sp.iAo;
    return is;
}
