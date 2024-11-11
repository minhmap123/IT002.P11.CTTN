#pragma once

#include "ThoiGian.h"

/**
 * @brief Khởi tạo đối tượng `ThoiGian` với giờ, phút và giây mặc định là 0.
 */
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

/**
 * @brief Khởi tạo đối tượng `ThoiGian` với các giá trị giờ, phút, và giây được chỉ định.
 * @param Gio Số giờ.
 * @param Phut Số phút.
 * @param Giay Số giây.
 */
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) 
    : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    }

/**
 * @brief Tính tổng số giây từ các thành phần giờ, phút và giây của đối tượng.
 * @return Tổng số giây dưới dạng một số nguyên.
 */
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

/**
 * @brief Chuyển đổi số giây thành giờ, phút, giây và trả về đối tượng `ThoiGian` mới.
 * @param TongGiay Tổng số giây cần chuyển đổi.
 * @return Đối tượng `ThoiGian` với giờ, phút và giây tương ứng.
 */
ThoiGian ThoiGian::TinhLaiGio(int TongGiay) {
    ThoiGian result;

    while (TongGiay < 0) 
        TongGiay += 24 * 3600; 
    
    result.iGio = (TongGiay / 3600) % 24;
    TongGiay %= 3600;
    result.iPhut = (TongGiay / 60) % 60;
    result.iGiay = TongGiay % 60;

    return result;
}

/**
 * @brief Thêm số giây chỉ định vào đối tượng `ThoiGian`.
 * @param Giay Số giây cần thêm.
 * @return Đối tượng `ThoiGian` mới sau khi thêm giây.
 */
ThoiGian ThoiGian::operator + (int Giay) {
    return TinhLaiGio(TinhGiay() + Giay);
}

/**
 * @brief Trừ số giây chỉ định khỏi đối tượng `ThoiGian`.
 * @param Giay Số giây cần trừ.
 * @return Đối tượng `ThoiGian` mới sau khi trừ giây.
 */
ThoiGian ThoiGian::operator - (int Giay) {
    return TinhLaiGio(TinhGiay() - Giay);
}

/**
 * @brief Cộng hai đối tượng `ThoiGian`.
 * @param other Đối tượng `ThoiGian` cần cộng với đối tượng hiện tại.
 * @return Đối tượng `ThoiGian` mới sau khi cộng.
 */
ThoiGian ThoiGian::operator + (const ThoiGian& other) {
    return TinhLaiGio(TinhGiay() + other.TinhGiay());
}

/**
 * @brief Trừ một đối tượng `ThoiGian` khỏi đối tượng hiện tại.
 * @param other Đối tượng `ThoiGian` cần trừ.
 * @return Đối tượng `ThoiGian` mới sau khi trừ.
 */
ThoiGian ThoiGian::operator - (const ThoiGian& other) {
    return TinhLaiGio(TinhGiay() - other.TinhGiay());
}

/**
 * @brief Toán tử tiền tố tăng đối tượng `ThoiGian` lên 1 giây.
 * @return Đối tượng `ThoiGian` mới sau khi tăng.
 */
ThoiGian ThoiGian::operator ++ () {
    return TinhLaiGio(TinhGiay() + 1);
}

/**
 * @brief Toán tử tiền tố giảm đối tượng `ThoiGian` xuống 1 giây.
 * @return Đối tượng `ThoiGian` mới sau khi giảm.
 */
ThoiGian ThoiGian::operator -- () {
    return TinhLaiGio(TinhGiay() - 1);
}

/**
 * @brief Kiểm tra xem hai đối tượng `ThoiGian` có bằng nhau hay không bằng cách quy đổi về giây.
 * @param other Đối tượng `ThoiGian` cần so sánh.
 * @return true nếu hai đối tượng bằng nhau, ngược lại là false.
 */
bool ThoiGian::operator == (const ThoiGian& other) {
    return (TinhGiay() == other.TinhGiay());
}

/**
 * @brief Kiểm tra xem hai đối tượng `ThoiGian` có khác nhau không bằng cách quy đổi về giây.
 * @param other Đối tượng `ThoiGian` cần so sánh.
 * @return true nếu hai đối tượng khác nhau, ngược lại là false.
 */
bool ThoiGian::operator != (const ThoiGian& other) {
    return (TinhGiay() != other.TinhGiay());
}

/**
 * @brief Kiểm tra xem đối tượng hiện tại có lớn hơn hoặc bằng đối tượng `ThoiGian` khác không.
 * @param other Đối tượng `ThoiGian` cần so sánh.
 * @return true nếu đối tượng hiện tại lớn hơn hoặc bằng, ngược lại là false.
 */
bool ThoiGian::operator >= (const ThoiGian& other) {
    return (TinhGiay() >= other.TinhGiay());
}

/**
 * @brief Kiểm tra xem đối tượng hiện tại có nhỏ hơn hoặc bằng đối tượng `ThoiGian` khác không.
 * @param other Đối tượng `ThoiGian` cần so sánh.
 * @return true nếu đối tượng hiện tại nhỏ hơn hoặc bằng, ngược lại là false.
 */
bool ThoiGian::operator <= (const ThoiGian& other) {
    return (TinhGiay() <= other.TinhGiay());
}

/**
 * @brief Kiểm tra xem đối tượng hiện tại có lớn hơn đối tượng `ThoiGian` khác không.
 * @param other Đối tượng `ThoiGian` cần so sánh.
 * @return true nếu đối tượng hiện tại lớn hơn, ngược lại là false.
 */
bool ThoiGian::operator > (const ThoiGian& other) {
    return (TinhGiay() > other.TinhGiay());
}

/**
 * @brief Kiểm tra xem đối tượng hiện tại có nhỏ hơn đối tượng `ThoiGian` khác không.
 * @param other Đối tượng `ThoiGian` cần so sánh.
 * @return true nếu đối tượng hiện tại nhỏ hơn, ngược lại là false.
 */
bool ThoiGian::operator < (const ThoiGian& other) {
    return (TinhGiay() < other.TinhGiay());
}

/**
 * @brief Xuất đối tượng `ThoiGian` ra luồng đầu ra.
 * @param os Luồng đầu ra.
 * @param tg Đối tượng `ThoiGian` cần xuất.
 * @return Luồng đầu ra với đối tượng `ThoiGian` được xuất.
 */
ostream& operator<<(ostream& os, const ThoiGian& tg) {
    os << tg.iGio << " gio, " << tg.iPhut << " phut, " << tg.iGiay << " giay";
    return os;
}

/**
 * @brief Nhập đối tượng `ThoiGian` từ luồng đầu vào, đảm bảo thời gian đúng định dạng 24h
 * @param is Luồng đầu vào.
 * @param tg Đối tượng `ThoiGian` để lưu dữ liệu đầu vào.
 * @return Luồng đầu vào sau khi đọc dữ liệu `ThoiGian`.
 */
istream& operator>>(istream& is, ThoiGian& tg) {
    int Gio, Phut, Giay;
    is >> Gio >> Phut >> Giay;

    Gio = (Gio % 24 + 24) % 24; 
    Phut = (Phut % 60 + 60) % 60; 
    Giay = (Giay % 60 + 60) % 60; 

    tg = ThoiGian(Gio, Phut, Giay);
    return is;
}
