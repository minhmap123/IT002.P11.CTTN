# include "QuanLyPhong.cpp"

int main() {
    Deluxe a("D1", 3, 200000, 150000);
    Deluxe b("D2", 2, 100000, 50000);
    Premium c("P1", 4, 2000000);
    Premium d("P2", 1,   50000);
    Business e("B1", 5);
    PhongKhachSan* dsPhong[] = {&a, &b, &c, &d, &e};

    long long tongDoanhThuDeluxe = 0;
    long long tongDoanhThuPremium = 0;
    long long tongDoanhThuBusiness = 0;

    for (auto phong : dsPhong) {
        switch (phong->getLoaiPhong())
        {
        case PhongKhachSan::DELUXE:
            tongDoanhThuDeluxe += phong->tinhDoanhThu();
            break;
        case PhongKhachSan::PREMIUM:
            tongDoanhThuPremium += phong->tinhDoanhThu();
            break;
        case PhongKhachSan::BUSINESS:
            tongDoanhThuBusiness += phong->tinhDoanhThu();
            break;
        default:
            break;
        }
    }

    cout << "Doanh thu cua phong Deluxe: " << tongDoanhThuDeluxe << endl;
    cout << "Doanh thu cua phong Premium: " << tongDoanhThuPremium << endl;
    cout << "Doanh thu cua phong Business: " << tongDoanhThuBusiness << endl;


    cout << "Loai phong co tong doanh thu lon nhat: ";
    int maxDoanhThu = max(max(tongDoanhThuDeluxe, tongDoanhThuPremium), tongDoanhThuBusiness);
    if (maxDoanhThu == tongDoanhThuDeluxe) 
        cout << "Deluxe";
    else if (maxDoanhThu == tongDoanhThuPremium)
        cout << "Premium";
    else 
        cout << "Business";

    return 0;
}
