class Prince {
private:
    long long soTien;
    int triTue;
    int sucManh;

public: 
    Prince(int tienBanDau, int triTueBanDau, int sucManhBanDau);

    void Nhap();

    long long getTien() const;
    int getTriTue() const;
    int getSucManh() const;

    void setTien(int tien);
    void setSucManh(int sm);

    void hienThiTrangThai();
};
