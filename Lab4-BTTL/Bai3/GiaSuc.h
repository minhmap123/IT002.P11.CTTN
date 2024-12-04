#pragma once


/**
 * @class GiaSuc
 * @brief Lớp cơ sở đại diện cho các loại gia súc, bao gồm các thuộc tính và hành vi cơ bản.
 */
class GiaSuc {
protected:
    int soLuong;  // số lượng gia súc (con)
    int tongSua;  // tổng số lượng sữa (lít)
public:
    GiaSuc(int, int);

    virtual void keu() const = 0;
    virtual void sinhCon() = 0;
    virtual void choSua() = 0;

    int getSoLuong() const;
    int getTongSua() const;
};


/**
 * @class Bo
 * @brief Lớp đại diện cho gia súc loại bò, kế thừa từ GiaSuc.
 */
class Bo : public GiaSuc {
public:
    Bo(int, int);

    void keu() const override;
    void sinhCon() override;
    void choSua() override;
};


/**
 * @class Cuu
 * @brief Lớp đại diện cho gia súc loại cừu, kế thừa từ GiaSuc.
 */
class Cuu : public GiaSuc {
public:
    Cuu(int, int);

    void keu() const override;
    void sinhCon() override;
    void choSua() override;
};


/**
 * @class De
 * @brief Lớp đại diện cho gia súc loại dê, kế thừa từ GiaSuc.
 */
class De : public GiaSuc {
public:
    De(int, int);
    
    void keu() const override;
    void sinhCon() override;
    void choSua() override;
};
