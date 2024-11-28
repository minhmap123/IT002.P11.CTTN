# pragma once

# include <iostream>
using namespace std;


/**
 * @class PhongKhachSan
 * @brief Lớp cơ sở đại diện cho phòng khách sạn, cung cấp các thuộc tính và phương thức chung.
 */
class PhongKhachSan {
protected:
    string maPhong;     // Mã số của phòng khách sạn
    int soDem;      // Số đêm khách lưu trú

public:
    PhongKhachSan(string ma, int dem);

    /**
     * @enum LoaiPhong
     * @brief Liệt kê các loại phòng khách sạn: DELUXE, PREMIUM, BUSINESS.
     */
    enum LoaiPhong { DELUXE, PREMIUM, BUSINESS }; 

    virtual void Nhap();
    virtual void Xuat() const;
    
    virtual long long tinhDoanhThu() const = 0;

    virtual LoaiPhong getLoaiPhong() const = 0;   
    virtual ~PhongKhachSan() {};
};

/**
 * @class Deluxe
 * @brief Lớp đại diện cho phòng Deluxe, kế thừa từ PhongKhachSan.
 */
class Deluxe : public PhongKhachSan {
private:
    long long phiDichVu;    // Phí dịch vụ của phòng Deluxe.
    long long phiPhucVu;    // Phí phục vụ của phòng Deluxe.

public:
    Deluxe(string ma, int dem, long long phiDichVu, long long phiPhucVu);
    LoaiPhong getLoaiPhong() const override { return DELUXE; }
    
    void Nhap();
    void Xuat() const;
    long long tinhDoanhThu() const override;
};

/**
 * @class Premium
 * @brief Lớp đại diện cho phòng Premium, kế thừa từ PhongKhachSan.
 */
class Premium : public PhongKhachSan {
private: 
    long long phiDichVu;    // Phí dịch vụ của phòng Premium.

public:
    Premium(string ma, int dem, long long phiDichVu);
    LoaiPhong getLoaiPhong() const override { return PREMIUM; }
    void Nhap();
    void Xuat() const;

    long long tinhDoanhThu() const override;
};

/**
 * @class Business
 * @brief Lớp đại diện cho phòng Business, kế thừa từ PhongKhachSan.
 */
class Business : public PhongKhachSan {
private:
public:
    Business(string ma, int dem);
    LoaiPhong getLoaiPhong() const override { return BUSINESS; }
    void Xuat() const;

    long long tinhDoanhThu() const override;
};
