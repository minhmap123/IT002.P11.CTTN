#include <iostream>
#include <algorithm>    // sort()
#include <cstring>      // strlen()
#include <iomanip>
using namespace std;

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct Gio {
    int gio;
    int phut;
};

struct ChuyenBay {
    char maChuyenBay[6];
    Ngay ngayKhoiHanh;
    Gio gioKhoiHanh;
    char diemKhoiHanh[21];
    char diemDen[21];
};

/**
 * @brief Kiểm tra tính hợp lệ của mã chuyến bay.
 * 
 * @param maChuyenBay Mã chuyến bay cần kiểm tra.
 * @return true nếu mã chuyến bay hợp lệ, false nếu không.
 */
bool kiemTraMaChuyenBay(const char* ma) {
    if (strlen(ma) > 5) return false;
    for (int i = 0; ma[i] != '\0'; ++i) 
        if (!((ma[i] >= 'A' && ma[i] <= 'Z') || (ma[i] >= 'a' && ma[i] <= 'z') || (ma[i] >= '0' && ma[i] <= '9'))) 
            return false;
      
    return true;
}


/**
 * @brief Kiểm tra năm nhuận.
 * 
 * @param nam Năm cần kiểm tra.
 * @return true nếu năm là năm nhuận, false nếu không.
 */
bool kiemTraNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

/**
 * @brief Trả về số ngày trong tháng tương ứng với năm.
 * 
 * @param thang Tháng cần kiểm tra.
 * @param nam Năm tương ứng.
 * @return Số ngày trong tháng.
 */
int soNgayTrongThang(int thang, int nam) {
    int soNgayCuaThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (kiemTraNamNhuan(nam)) 
        soNgayCuaThang[1] = 29;
    
    return soNgayCuaThang[thang - 1];
}

/**
 * @brief Kiểm tra tính hợp lệ của ngày tháng năm.
 * 
 * @param ngay Ngày cần kiểm tra.
 * @param thang Tháng cần kiểm tra.
 * @param nam Năm cần kiểm tra.
 * @return `true` nếu ngày hợp lệ, `false` nếu không.
 */
bool kiemTraNgayHopLe(const Ngay& ngay_thang_nam) {
    if (ngay_thang_nam.nam < 1 || ngay_thang_nam.thang < 1 || ngay_thang_nam.thang > 12) return false;
    return ngay_thang_nam.ngay >= 1 && ngay_thang_nam.ngay <= soNgayTrongThang(ngay_thang_nam.thang, ngay_thang_nam.nam);
}

/**
 * @brief Kiểm tra tính hợp lệ của giờ và phút.
 * 
 * @param gio Giờ cần kiểm tra.
 * @param phut Phút cần kiểm tra.
 * @return `true` nếu giờ và phút hợp lệ, `false` nếu không.
 */
bool kiemTraGioHopLe(int gio, int phut) {
    return gio >= 0 && gio < 24 && phut >= 0 && phut < 60;
}

/**
 * @brief Kiểm tra tính hợp lệ của địa điểm.
 * 
 * @param noi Nơi cần kiểm tra.
 * @return `true` nếu địa điểm hợp lệ, `false` nếu không.
 */
bool kiemTraNoi(const char* diadiem) {
    if (strlen(diadiem) > 20) return false;

    for (int i = 0; diadiem[i] != '\0'; ++i) 
        if (!((diadiem[i] >= 'A' && diadiem[i] <= 'Z') || (diadiem[i] >= 'a' && diadiem[i] <= 'z') || diadiem[i] == ' ')) 
            return false;
        
    return true;
}

/**
 * @brief Nhập thông tin chuyến bay từ người dùng.
 * 
 * @param chuyenBay Tham chiếu đến đối tượng ChuyenBay để lưu thông tin nhập vào.
 */
ChuyenBay nhapChuyenBay() {
    ChuyenBay cb;

    bool kiemTra;
    do {
        cout << "\t-Nhap ma chuyen bay (toi da 5 ky tu): ";
        cin >> cb.maChuyenBay;
        kiemTra = kiemTraMaChuyenBay(cb.maChuyenBay);
        if (!kiemTra) {
            cout << "(!)Loi: Ma chuyen bay khong hop le. Vui long nhap lai.\n";
        }
    } while (!kiemTra);

    do {
        cout << "\t-Nhap ngay khoi hanh (dd/mm/yyyy): ";
        char ngayNhap[11];
        cin >> ngayNhap;
        sscanf(ngayNhap, "%d/%d/%d", &cb.ngayKhoiHanh.ngay, &cb.ngayKhoiHanh.thang, &cb.ngayKhoiHanh.nam);
        kiemTra = kiemTraNgayHopLe(cb.ngayKhoiHanh);
        if (!kiemTra) {
            cout << "(!)Loi: Ngay khong hop le. Vui long nhap lai.\n";
        }
    } while (!kiemTra);

    do {
        cout << "\t-Nhap gio khoi hanh (HH:MM, 24h): ";
        char gioNhap[6];
        cin >> gioNhap;
        sscanf(gioNhap, "%d:%d", &cb.gioKhoiHanh.gio, &cb.gioKhoiHanh.phut);
        kiemTra = kiemTraGioHopLe(cb.gioKhoiHanh.gio, cb.gioKhoiHanh.phut);
        if (!kiemTra) {
            cout << "(!)Loi: Gio khong hop le. Vui long nhap lai.\n";
        }
    } while (!kiemTra);

    do {
        cout << "\t-Nhap diem khoi hanh (toi da 20 ky tu): ";
        cin.ignore();
        cin.getline(cb.diemKhoiHanh, 21);
        kiemTra = kiemTraNoi(cb.diemKhoiHanh);
        if (!kiemTra) {
            cout << "(!)Loi: Diem khoi hanh khong hop le. Vui long nhap lai.\n";
        }
    } while (!kiemTra);

    do {
        cout << "\t-Nhap diem den (toi da 20 ky tu): ";
        cin.getline(cb.diemDen, 21);
        kiemTra = kiemTraNoi(cb.diemDen);
        if (!kiemTra) {
            cout << "(!)Loi: Diem den khong hop le. Vui long nhap lai.\n";
        }
    } while (!kiemTra);

    return cb;
}

/**
 * @brief Xuất thông tin chuyến bay ra màn hình.
 * 
 * @param chuyenBay Tham chiếu đến đối tượng ChuyenBay chứa thông tin cần xuất.
 */
void xuatThongTinChuyenBay(const ChuyenBay& cb) {
    cout << setw(7) << left << cb.maChuyenBay;

    if (cb.ngayKhoiHanh.ngay < 10) cout << '0';
    cout << cb.ngayKhoiHanh.ngay << "/";

    if (cb.ngayKhoiHanh.thang < 10) cout << '0';
    cout << cb.ngayKhoiHanh.thang << "/";

    cout << cb.ngayKhoiHanh.nam << "  ";  

    if (cb.gioKhoiHanh.gio < 10) cout << '0';
    cout << cb.gioKhoiHanh.gio << ":";

    if (cb.gioKhoiHanh.phut < 10) cout << '0';
    cout << cb.gioKhoiHanh.phut << "  ";

    cout << setw(21) << left << cb.diemKhoiHanh
         << setw(21) << left << cb.diemDen << endl;
}

/**
 * @brief So sánh hai chuyến bay để sắp xếp theo ngày giờ.
 * 
 * @param a Chuyến bay đầu tiên.
 * @param b Chuyến bay thứ hai.
 * @return `true` nếu a trước b, `false` nếu ngược lại.
 */
bool soSanhChuyenBay(const ChuyenBay& a, const ChuyenBay& b) {
    if (a.ngayKhoiHanh.nam != b.ngayKhoiHanh.nam)
        return a.ngayKhoiHanh.nam < b.ngayKhoiHanh.nam;
    if (a.ngayKhoiHanh.thang != b.ngayKhoiHanh.thang)
        return a.ngayKhoiHanh.thang < b.ngayKhoiHanh.thang;
    if (a.ngayKhoiHanh.ngay != b.ngayKhoiHanh.ngay)
        return a.ngayKhoiHanh.ngay < b.ngayKhoiHanh.ngay;
    if (a.gioKhoiHanh.gio != b.gioKhoiHanh.gio)
        return a.gioKhoiHanh.gio < b.gioKhoiHanh.gio;
    return a.gioKhoiHanh.phut < b.gioKhoiHanh.phut;
}

/**
 * @brief Tìm chuyến bay theo mã chuyến bay.
 * 
 * @param danhSachChuyenBay Danh sách các chuyến bay.
 * @param maChuyenBay Mã chuyến bay cần tìm.
 * @return Chuyến bay nếu tìm thấy, ngược lại trả về ChuyenBay() mặc định.
 */
void timKiemChuyenBayTheoMa(ChuyenBay* ds, int n, const char* maChuyenBay) {
    bool timThay = false;

    cout << "\nKET QUA TIM KIEM THEO MA CHUYEN BAY:\n";
    cout << setw(7) << left << "Ma CB"
         << setw(12) << "Ngay"
         << setw(7) << "Gio"
         << setw(21) << "Noi Di"
         << setw(21) << "Noi Den" << endl;

    for (int i = 0; i < n; ++i) {
        if (strcmp(ds[i].maChuyenBay, maChuyenBay) == 0) {
            timThay = true;
            xuatThongTinChuyenBay(ds[i]);
        }
    }

    if (!timThay) {
        cout << "Khong tim thay chuyen bay nao phu hop.\n";
    }
}

/**
 * @brief Tìm chuyến bay theo địa điểm khởi hành.
 * 
 * @param danhSachChuyenBay Danh sách các chuyến bay.
 * @param noiDi Địa điểm khởi hành cần tìm.
 * @return Vector chứa các chuyến bay phù hợp.
 */
void timKiemChuyenBayTheoNoiDi(ChuyenBay* ds, int n, const char* noiDi) {
    bool timThay = false;

    cout << "\nKET QUA TIM KIEM THEO NOI DI:\n";
    cout << setw(7) << left << "Ma CB"
         << setw(12) << "Ngay"
         << setw(7) << "Gio"
         << setw(21) << "Noi Di"
         << setw(21) << "Noi Den" << endl;

    for (int i = 0; i < n; ++i) {
        if (strcmp(ds[i].diemKhoiHanh, noiDi) == 0) {
            timThay = true;
            xuatThongTinChuyenBay(ds[i]);
        }
    }

    if (!timThay) {
        cout << "Khong tim thay chuyen bay nao phu hop.\n";
    }
}

/**
 * @brief Tìm chuyến bay theo địa điểm đến.
 * 
 * @param danhSachChuyenBay Danh sách các chuyến bay.
 * @param noiDen Địa điểm đến cần tìm.
 * @return Vector chứa các chuyến bay phù hợp.
 */
void timKiemChuyenBayTheoNoiDen(ChuyenBay* ds, int n, const char* noiDen) {
    bool timThay = false;

    cout << "\nKET QUA TIM KIEM THEO NOI DEN:\n";
    cout << setw(7) << left << "Ma CB"
         << setw(12) << "Ngay"
         << setw(7) << "Gio"
         << setw(21) << "Noi Di"
         << setw(21) << "Noi Den" << endl;

    for (int i = 0; i < n; ++i) {
        if (strcmp(ds[i].diemDen, noiDen) == 0) {
            timThay = true;
            xuatThongTinChuyenBay(ds[i]);
        }
    }

    if (!timThay) {
        cout << "(!) Khong tim thay chuyen bay nao phu hop.\n";
    }
}

/**
 * @brief Liệt kê chuyến bay theo địa điểm và ngày khởi hành.
 * 
 * @param danhSachChuyenBay Danh sách các chuyến bay.
 * @param noiDi Địa điểm khởi hành cần tìm.
 * @param ngay Ngày khởi hành cần tìm.
 * @return Vector chứa các chuyến bay phù hợp.
 */
void lietKeChuyenBayTheoNoiVaNgay(const ChuyenBay* ds, int soLuong, const char* noiDi, const Ngay& ngay) {
    bool timThay = false;

    cout << "\nKET QUA TIM KIEM THEO NOI KHOI HANH VA NGAY KHOI HANH:\n";
    cout << setw(7) << left << "Ma CB"
         << setw(12) << "Ngay"
         << setw(7) << "Gio"
         << setw(21) << "Noi Di"
         << setw(21) << "Noi Den" << endl;

    for (int i = 0; i < soLuong; ++i) {
        if (strcmp(ds[i].diemKhoiHanh, noiDi) == 0 &&
            ds[i].ngayKhoiHanh.ngay == ngay.ngay &&
            ds[i].ngayKhoiHanh.thang == ngay.thang &&
            ds[i].ngayKhoiHanh.nam == ngay.nam) {
            xuatThongTinChuyenBay(ds[i]);
            timThay = true;
        }
    }
    if (!timThay) cout << "(!) Khong co chuyen bay nao khoi hanh tu " << noiDi << " vao ngay " << ngay.ngay << "/" << ngay.thang << "/" << ngay.nam << ".\n";
}

/**
 * @brief Đếm số chuyến bay từ một địa điểm đến địa điểm khác.
 * 
 * @param danhSachChuyenBay Danh sách các chuyến bay.
 * @param noiDi Địa điểm khởi hành.
 * @param noiDen Địa điểm đến.
 * @return Số lượng chuyến bay từ địa điểm khởi hành đến địa điểm đến.
 */
int demChuyenBay(const ChuyenBay* ds, int soLuong, const char* noiDi, const char* noiDen) {
    int dem = 0;
    for (int i = 0; i < soLuong; ++i) {
        if (strcmp(ds[i].diemKhoiHanh, noiDi) == 0 && strcmp(ds[i].diemDen, noiDen) == 0) {
            dem++;
        }
    }
    return dem;
}

/**
 * @brief Hiển thị menu tùy chọn cho người dùng.
 */
void menu() {
    cout << "\n=== CHUONG TRINH QUAN LY CHUYEN BAY ===\n";
    cout << "0. Hien thi menu\n";
    cout << "1. Nhap thong tin cac chuyen bay\n";
    cout << "2. Xuat danh sach chuyen bay\n";
    cout << "3. Tim kiem chuyen bay theo ma chuyen bay\n";
    cout << "4. Tim kiem chuyen bay theo noi di\n";
    cout << "5. Tim kiem chuyen bay theo noi den\n";
    cout << "6. Liet ke chuyen bay theo noi di va ngay\n";
    cout << "7. Dem chuyen bay theo noi di va noi den\n";
    cout << "8. Thoat\n";
}

int main() {
    
    ChuyenBay* danhSachChuyenBay = nullptr;
    int soLuong = 0;
    int luaChon;

    menu();
    do {
        cout << "\nChon: "; 
        cin >> luaChon;

        switch (luaChon)
        {
        case 0: {
            menu();
            break;
        }
        case 1: {
            cout << "Nhap so luong chuyen bay: ";
            while (true) {
                cin >> soLuong;
                if (soLuong > 0) break;
                else 
                    cout << "(!) Loi: So luong chuyen bay phai lon hon 0. Vui long nhap lai: ";
            }

            danhSachChuyenBay = new ChuyenBay[soLuong];
            for (int i = 0; i < soLuong; ++i) {
                    cout << "\nNhap thong tin chuyen bay " << (i + 1) << ":\n";
                    danhSachChuyenBay[i] = nhapChuyenBay();
            }

            sort(danhSachChuyenBay, danhSachChuyenBay + soLuong, soSanhChuyenBay);
            break;
        }
        case 2: {
            cout << "\nDANH SACH CHUYEN BAY:\n";
            cout << setw(7) << left << "Ma CB"
                    << setw(12) << "Ngay"
                    << setw(7) << "Gio"
                    << setw(21) << "Noi Di"
                    << setw(21) << "Noi Den" << endl;

            for (int i = 0; i < soLuong; ++i) {
                xuatThongTinChuyenBay(danhSachChuyenBay[i]);
            }
            break;
        }
        case 3: {
            char maChuyenBay[6];
            while (true) {
                cout << "Nhap ma chuyen bay can tim: ";
                cin >> maChuyenBay;

                if (!kiemTraMaChuyenBay(maChuyenBay)) {
                    cout << "(!) Loi: Ma chuyen bay khong hop le. Vui long nhap lai.\n";
                } else {
                    timKiemChuyenBayTheoMa(danhSachChuyenBay, soLuong, maChuyenBay);
                    break;  
                }
            }
            break;
        }
        case 4: {
            char noiDi[21];
            while (true) {
                cout << "Nhap noi di: ";
                cin.ignore();
                cin.getline(noiDi, 21);

                if (!kiemTraNoi(noiDi)) {
                    cout << "(!) Loi: Noi di khong hop le. Vui long nhap lai.\n";
                } else {
                    timKiemChuyenBayTheoNoiDi(danhSachChuyenBay, soLuong, noiDi);
                    break;  
                }
            }
            break;
        }
        case 5: {
            char noiDen[21];
            while (true) {
                cout << "Nhap noi den: ";
                cin.ignore();
                cin.getline(noiDen, 21);

                if (!kiemTraNoi(noiDen)) {
                    cout << "(!) Loi: Noi den khong hop le. Vui long nhap lai.\n";
                } else {
                    timKiemChuyenBayTheoNoiDen(danhSachChuyenBay, soLuong, noiDen);
                    break;  
                }
            }
            break;
        }
        case 6: {
            char noiDi[21];
            Ngay ngay;
            while (true) {
                cout << "Nhap noi di: ";
                cin.ignore();
                cin.getline(noiDi, 21);

                cout << "Nhap ngay khoi hanh (dd/mm/yyyy): ";
                char ngayNhap[11];
                cin >> ngayNhap;
                sscanf(ngayNhap, "%d/%d/%d", &ngay.ngay, &ngay.thang, &ngay.nam);

                if (!kiemTraNoi(noiDi)) {
                    cout << "(!) Loi: Noi di khong hop le. Vui long nhap lai.\n";
                } else if (!kiemTraNgayHopLe(ngay)) {
                    cout << "(!) Loi: Ngay khong hop le. Vui long nhap lai.\n";
                } else {
                    lietKeChuyenBayTheoNoiVaNgay(danhSachChuyenBay, soLuong, noiDi, ngay);
                    break;  
                }
            }
            break;
        }
        case 7: {
            char noiDi[21], noiDen[21];
            while (true) {
                cout << "- Nhap noi di: ";
                cin.ignore();
                cin.getline(noiDi, 21);

                cout << "- Nhap noi den: ";
                cin.getline(noiDen, 21);

                if (!kiemTraNoi(noiDi) || !kiemTraNoi(noiDen)) {
                    cout << "(!) Loi: Noi di hoac noi den khong hop le. Vui long nhap lai.\n";
                } else {
                    int soChuyenBay = demChuyenBay(danhSachChuyenBay, soLuong, noiDi, noiDen);
                    cout << "(+) So chuyen bay tu " << noiDi << " den " << noiDen << " la: " << soChuyenBay << endl;
                    break;  
                }
            }
            break;
        }
        case 8: {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";;
        }
    } while (luaChon != 8);

    delete[] danhSachChuyenBay;

    return 0;
}
