#pragma once

/**
 * @class Diem
 * @brief Đại diện cho một điểm trong hệ tọa độ 2D.
 *
 * Lớp Diem cung cấp các phương thức để khởi tạo, xuất tọa độ, 
 * lấy và đặt giá trị hoành độ, tung độ, và dịch chuyển điểm theo vector cho trước.
 */
class Diem {
private:
    float iHoanh;
    float iTung;

public:
    Diem();
    Diem(float Hoanh, float Tung);
    Diem(const Diem& x);
    void Xuat();
    float GetTungDo();
    float GetHoanhDo();
    void SetTungDo(float Tung);
    void SetHoanhDo(float Hoanh);
    void TinhTien(float x, float y); 
};
