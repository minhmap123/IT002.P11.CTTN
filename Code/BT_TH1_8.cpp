#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <algorithm>    // sort()
#include <iomanip>
#include <sstream>
using namespace std;

double laiSuatNganHan = 8.0;
double laiSuatDaiHan = 4.0;
double laiSuatKhongKyHan = 0.5;

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct SoTietKiem {
    char maSo[6];         
    char loaiTietKiem[11]; 
    char hoTenKH[31];      
    char cmnd[13];          
    Ngay ngayMoSo;         
    double soTienGui;    
    double laiSuat;  
};

/**
 * Kiểm tra xem năm có phải là năm nhuận không.
 * @param nam Năm cần kiểm tra.
 * @return true nếu năm là năm nhuận, false nếu không.
 */
bool kiemTraNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

/**
 * Trả về số ngày trong tháng của một năm nhất định.
 * @param thang Tháng cần kiểm tra (1-12).
 * @param nam Năm cần kiểm tra.
 * @return Số ngày trong tháng.
 */
int soNgayTrongThang(int thang, int nam) {
    int soNgayCuaThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (kiemTraNamNhuan(nam)) 
        soNgayCuaThang[1] = 29;
    
    return soNgayCuaThang[thang - 1];
}

/**
 * Tính ngày Julian từ một ngày cụ thể.
 * @param date Ngày cần tính.
 * @return Giá trị Julian Day tương ứng.
 */
long long tinhJulianDay(const Ngay& date) {
    int a = (14 - date.thang) / 12;
    int y = date.nam + 4800 - a;
    int m = date.thang + 12 * a - 3;

    return date.ngay + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

/**
 * Tính số ngày giữa hai ngày.
 * @param batDau Ngày bắt đầu.
 * @param ketThuc Ngày kết thúc.
 * @return Số ngày giữa hai ngày.
 */
int tinhSoNgayGiuaHaiNgay(Ngay batDau, Ngay ketThuc) {
    long long jdn1 = tinhJulianDay(batDau);
    cout << jdn1 << endl;
    long long jdn2 = tinhJulianDay(ketThuc);
    cout << jdn2 << endl;
    return abs(jdn2 - jdn1);
}

/**
 * Lấy ngày hiện tại từ hệ thống.
 * @return Ngày hiện tại.
 */
Ngay layNgayHienTai() {
    Ngay ngayHienTai;
    time_t baygio = time(0);
    tm *ltm = localtime(&baygio);
    
    ngayHienTai.ngay = ltm->tm_mday;  
    ngayHienTai.thang = 1 + ltm->tm_mon;      
    ngayHienTai.nam = 1900 + ltm->tm_year;   

    return ngayHienTai;
}

/**
 * Kiểm tra tính hợp lệ của ngày tháng năm.
 * @param ngay_thang_nam Ngày tháng năm cần kiểm tra.
 * @return true nếu ngày hợp lệ, false nếu không.
 */
bool kiemTraNgayHopLe(const Ngay& ngay_thang_nam) {
    if (ngay_thang_nam.nam < 1 || ngay_thang_nam.thang < 1 || ngay_thang_nam.thang > 12) return false;
    return ngay_thang_nam.ngay >= 1 && ngay_thang_nam.ngay <= soNgayTrongThang(ngay_thang_nam.thang, ngay_thang_nam.nam);
}

/**
 * Kiểm tra tính hợp lệ của mã số.
 * @param ma Mã số cần kiểm tra.
 * @return true nếu mã hợp lệ, false nếu không.
 */
bool kiemTraMaSo(const char* ma) {
    if (strlen(ma) > 5) return false;
    
    for (int i = 0; ma[i] != '\0'; ++i) 
        if (!((ma[i] >= 'A' && ma[i] <= 'Z') || (ma[i] >= 'a' && ma[i] <= 'z') || (ma[i] >= '0' && ma[i] <= '9'))) 
            return false;
      
    return true;
}

/**
 * Kiểm tra loại tiết kiệm hợp lệ.
 * @param loai Loại tiết kiệm cần kiểm tra.
 * @return true nếu loại hợp lệ, false nếu không.
 */
bool kiemTraLoaiTietKiem(const char* loai) {
    return (strcmp(loai, "ngan han") == 0 || strcmp(loai, "dai han") == 0 || strcmp(loai, "khongkyhan") == 0);
}


/**
 * Kiểm tra tên khách hàng có hợp lệ không.
 * @param hoTen Tên khách hàng cần kiểm tra.
 * @return true nếu tên hợp lệ, false nếu không.
 */
bool kiemTraTenHopLe(string hoTen) {
    if (hoTen.length() > 30) return false;

    hoTen = ' ' + hoTen; 
    for (int i = 1; i < hoTen.length(); ++i) {
        if (hoTen[i] == ' ') {
            if (hoTen[i-1] == ' ') 
                return false;
            else 
                continue;
        }

        if (hoTen[i - 1] == ' ') {
            if (hoTen[i] < 'A' || hoTen[i] > 'Z') 
                return false; 
        } else {
            if (hoTen[i] < 'a' || hoTen[i] > 'z') 
                return false; 
        }
    }
    return true; 
}

/**
 * Nhập thông tin cho sổ tiết kiệm.
 * @param stk Sổ tiết kiệm cần nhập thông tin.
 */
bool kiemTraCMND(const char* cmnd) {
    int len = strlen(cmnd);
    if (len != 9 && len != 12) return false;

    for (int i = 0; i < len; ++i) 
        if (cmnd[i] < '0' || cmnd[i] > '9') 
            return false;

    return true;
}

/**
 * Nhập thông tin cho sổ tiết kiệm.
 * @param stk Sổ tiết kiệm cần nhập thông tin.
 */
void nhapThongTinSoTietKiem(SoTietKiem &stk) {
    bool hopLe; 

    do {
        cout << "Nhap ma so (toi da 5 ky tu, khong co ky tu dac biet): ";
        cin >> stk.maSo;
        hopLe = kiemTraMaSo(stk.maSo);
        if (!hopLe) 
            cout << "Ma so khong hop le. Vui long nhap lai.\n";
    } while (!hopLe);

    cin.ignore();
    do {
        cout << "Nhap loai tiet kiem (ngan han/dai han/khongkyhan): ";
        cin.getline(stk.loaiTietKiem, 11);
        hopLe = kiemTraLoaiTietKiem(stk.loaiTietKiem);
        if (!hopLe) 
            cout << "Loai tiet kiem khong hop le. Vui long nhap lai.\n";
    } while (!hopLe);

    if (strcmp(stk.loaiTietKiem, "ngan han") == 0) {
        stk.laiSuat = laiSuatNganHan;
    } else if (strcmp(stk.loaiTietKiem, "dai han") == 0) {
        stk.laiSuat = laiSuatDaiHan;
    } else if (strcmp(stk.loaiTietKiem, "khongkyhan") == 0) {
        stk.laiSuat = laiSuatKhongKyHan;
    } 

    string hoTen;
    do {
        cout << "Nhap ho ten khach hang (toi da 30 ky tu): ";
        getline(cin, hoTen);
        hopLe = kiemTraTenHopLe(hoTen);
        if (!hopLe) 
            cout << "Ho ten khong hop le. Vui long nhap lai.\n";
    } while (!hopLe);
    strcpy(stk.hoTenKH, hoTen.c_str());

    do {
        cout << "Nhap CMND (9 hoac 12 chu so): ";
        cin >> stk.cmnd;
        hopLe = kiemTraCMND(stk.cmnd);
        if (!hopLe) 
            cout << "CMND khong hop le. Vui long nhap lai.\n";
    } while (!hopLe);

    do {
        cout << "Nhap ngay mo so (dd mm yyyy): ";
        cin >> stk.ngayMoSo.ngay >> stk.ngayMoSo.thang >> stk.ngayMoSo.nam;
        hopLe = kiemTraNgayHopLe(stk.ngayMoSo);
        if (!hopLe) {
            cout << "Ngay khong hop le. Vui long nhap lai.\n";
        }
    } while (!hopLe);

    do {
        cout << "Nhap so tien gui (so duong): ";
        cin >> stk.soTienGui;
        hopLe = stk.soTienGui > 0.0;
        if (!hopLe) 
            cout << "So tien gui khong hop le. Vui long nhap lai.\n";
    } while (!hopLe);
}

/** 
 * Xuất ra tên các cột của bảng.
 */
void tieuDeBang() {
    // In tiêu đề bảng
    cout << left;
    cout << setw(7) << "Ma so" 
        << setw(15) << "Loai tiet kiem" 
        << setw(30) << "Ho ten khach hang" 
        << setw(14) << "CMND" 
        << setw(13) << "Ngay mo so" 
        << setw(20) << "So tien gui (VND)" 
        << setw(20) << "Lai suat (%/nam)" << endl;

    // In đường viền dưới tiêu đề
    cout << setfill('-') << setw(7) << "" 
        << setw(15) << "" 
        << setw(30) << "" 
        << setw(14) << "" 
        << setw(13) << "" 
        << setw(20) << "" 
        << setw(20) << "" << endl;
    cout << setfill(' '); // Trở về với ký tự trắng
}

/**
 * Xuất thông tin của một sổ tiết kiệm (dạng bảng).
 * @param stk Sổ tiết kiệm cần xuất thông tin.
 */
void xuatThongTinSoTietKiem(const SoTietKiem &stk) {
    ostringstream dateStream;
    dateStream << setfill('0') << setw(2) << stk.ngayMoSo.ngay << "/" 
               << setw(2) << stk.ngayMoSo.thang << "/" 
               << stk.ngayMoSo.nam;

    // In dữ liệu
    cout << setw(7) << stk.maSo 
         << setw(15) << stk.loaiTietKiem 
         << setw(30) << stk.hoTenKH 
         << setw(14) << stk.cmnd 
         << setw(13) << dateStream.str() 
         << setw(20) << fixed << setprecision(2) << stk.soTienGui  
         << setw(20) << fixed << setprecision(2) << stk.laiSuat << endl;
}

/**
 * Tính tiền lãi của sổ tiết kiệm dựa trên số tiền gửi, lãi suất và số ngày gửi.
 * @param stk Sổ tiết kiệm cần tính tiền lãi.
 * @return Số tiền lãi tính được.
 */
double tinhTienLai(const SoTietKiem &stk) {
    Ngay ngayHienTai = layNgayHienTai(); 

    int soNgayGui = tinhSoNgayGiuaHaiNgay(stk.ngayMoSo, ngayHienTai);
    
    double tienLai = (stk.soTienGui * (stk.laiSuat / 100) * soNgayGui) / 365;
    return tienLai;
}

/**
 * Rút tiền từ sổ tiết kiệm. Người dùng sẽ nhập số tiền muốn rút,
 * và nếu hợp lệ, số tiền sẽ được trừ từ số dư.
 * @param stk Sổ tiết kiệm cần rút tiền.
 */
void rutTien(SoTietKiem &stk) {
    double soTienRut;

    bool hopLe;
    do {
        cout << "Nhap so tien muon rut: ";
        cin >> soTienRut;
        hopLe = soTienRut > 0.0;
        if (!hopLe) 
            cout << "So tien rut khong hop le. Vui long nhap lai.\n";
    } while (!hopLe);

    if (soTienRut > stk.soTienGui) {
        cout << "So tien rut vuot qua so du hien co." << endl;
    } else {
        double tienLai = tinhTienLai(stk);
        
        Ngay ngayHienTai = layNgayHienTai();
        int soThangGui = tinhSoNgayGiuaHaiNgay(stk.ngayMoSo, ngayHienTai) / 30;
        
        if (soThangGui < 6) {
            if (strcmp(stk.loaiTietKiem, "ngan han") == 0) 
                cout << "Rut truoc han! Lai suat giam con 0.5%/nam." << endl;
            double tienLaiRutTruocHan = (stk.soTienGui * (0.5 / 100) * (ngayHienTai.ngay - stk.ngayMoSo.ngay)) / 365;
            cout << "Tien lai voi lai suat 0.5%: " << tienLaiRutTruocHan << endl;
            cout << "Tong so tien rut duoc: " << soTienRut + tienLaiRutTruocHan << endl;
        }

        stk.soTienGui -= soTienRut;
        cout << "Rut tien thanh cong. So du con lai: " << stk.soTienGui << endl;
    }
}

/**
 * Tìm sổ tiết kiệm theo mã số. Nếu tìm thấy, thông tin của sổ tiết kiệm sẽ được xuất ra.
 * @param stk Mảng các sổ tiết kiệm.
 * @param n Số lượng sổ tiết kiệm trong mảng.
 */
void timSoTietKiemTheoMaSo(const SoTietKiem* stk, int n) {
    char maSo[6];
    bool hopLe; 

    do {
        cout << "Nhap ma so (toi da 5 ky tu, khong co ky tu dac biet): ";
        cin >> maSo;
        hopLe = kiemTraMaSo(maSo);
        if (!hopLe) 
            cout << "Ma so khong hop le. Vui long nhap lai.\n";
    } while (!hopLe);

    bool timThay = false;
    tieuDeBang();
    for (int i = 0; i < n; ++i) {
        if (strcmp(stk[i].maSo, maSo) == 0) {
            xuatThongTinSoTietKiem(stk[i]);
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay so tiet kiem voi ma so " << maSo << "." << endl;
    }
}

/**
 * Tìm sổ tiết kiệm theo CMND. Nếu tìm thấy, thông tin của sổ tiết kiệm sẽ được xuất ra.
 * @param stk Mảng các sổ tiết kiệm.
 * @param n Số lượng sổ tiết kiệm trong mảng.
 */
void timSoTietKiemTheoCMND(const SoTietKiem* stk, int n) {
    char cmnd[13];

    bool hopLe;
    do {
        cout << "Nhap CMND (9 hoac 12 chu so): ";
        cin >> cmnd;
        hopLe = kiemTraCMND(cmnd);
        if (!hopLe) 
            cout << "CMND khong hop le. Vui long nhap lai.\n";
    } while (!hopLe);

    bool timThay = false;
    tieuDeBang();
    for (int i = 0; i < n; ++i) {
        if (strcmp(stk[i].cmnd, cmnd) == 0) {
            xuatThongTinSoTietKiem(stk[i]);
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay so tiet kiem voi CMND " << cmnd << "." << endl;
    }
}

/**
 * Liệt kê các sổ tiết kiệm mở trong khoảng thời gian chỉ định.
 * @param stk Mảng các sổ tiết kiệm.
 * @param n Số lượng sổ tiết kiệm trong mảng.
 */
void lietKeSoTietKiemTrongKhoangThoiGian(const SoTietKiem* stk, int n) {
    Ngay ngayBatDau, ngayKetThuc;
    bool hopLe;

    do {
        cout << "Nhap ngay bat dau (dd mm yyyy): ";
        cin >> ngayBatDau.ngay >> ngayBatDau.thang >> ngayBatDau.nam;
        hopLe = kiemTraNgayHopLe(ngayBatDau);
        if (!hopLe) {
            cout << "Ngay bat dau khong hop le. Vui long nhap lai.\n";
        }
    } while (!hopLe);

    do {
        cout << "Nhap ngay ket thuc (dd mm yyyy): ";
        cin >> ngayKetThuc.ngay >> ngayKetThuc.thang >> ngayKetThuc.nam;
        hopLe = kiemTraNgayHopLe(ngayKetThuc);
        if (!hopLe) {
            cout << "Ngay ket thuc khong hop le. Vui long nhap lai.\n";
        }
    } while (!hopLe);

    bool timThay = false;
    tieuDeBang();
    for (int i = 0; i < n; ++i) {
        Ngay ngayMo = stk[i].ngayMoSo;
        if ((ngayMo.nam > ngayBatDau.nam 
            || (ngayMo.nam == ngayBatDau.nam && (ngayMo.thang > ngayBatDau.thang 
            || (ngayMo.thang == ngayBatDau.thang && ngayMo.ngay >= ngayBatDau.ngay)))) 
            && (ngayMo.nam < ngayKetThuc.nam 
            || (ngayMo.nam == ngayKetThuc.nam && (ngayMo.thang < ngayKetThuc.thang 
            || (ngayMo.thang == ngayKetThuc.thang && ngayMo.ngay <= ngayKetThuc.ngay))))) {
            xuatThongTinSoTietKiem(stk[i]);
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong co so tiet kiem nao mo trong khoang thoi gian tu " << ngayBatDau.ngay << "/" << ngayBatDau.thang << "/" << ngayBatDau.nam 
             << " den " << ngayKetThuc.ngay << "/" << ngayKetThuc.thang << "/" << ngayKetThuc.nam << "." << endl;
    }
}

/**
 * Sắp xếp các sổ tiết kiệm theo số tiền gửi giảm dần.
 * @param stk Mảng các sổ tiết kiệm cần sắp xếp.
 * @param n Số lượng sổ tiết kiệm trong mảng.
 */
void sapXepTheoSoTienGui(SoTietKiem* stk, int n) {
    sort(stk, stk + n, [](const SoTietKiem& a, const SoTietKiem& b) {
        return a.soTienGui > b.soTienGui; 
    });
    cout << "Danh sach cac so tiet kiem da duoc sap xep theo so tien gui giam dan.\n";
}

/**
 * So sánh hai sổ tiết kiệm theo ngày mở sổ.
 * @param a Sổ tiết kiệm thứ nhất.
 * @param b Sổ tiết kiệm thứ hai.
 * @return true nếu ngày mở sổ của a nhỏ hơn b, ngược lại false.
 */
bool soSanhTheoNgayMoSo(const SoTietKiem& a, const SoTietKiem& b) {
    if (a.ngayMoSo.nam != b.ngayMoSo.nam) 
        return a.ngayMoSo.nam < b.ngayMoSo.nam;
    if (a.ngayMoSo.thang != b.ngayMoSo.thang) 
        return a.ngayMoSo.thang < b.ngayMoSo.thang;
    return a.ngayMoSo.ngay < b.ngayMoSo.ngay;
}

/**
 * Sắp xếp các sổ tiết kiệm theo ngày mở sổ tăng dần.
 * @param stk Mảng các sổ tiết kiệm cần sắp xếp.
 * @param n Số lượng sổ tiết kiệm trong mảng.
 */
void sapXepTheoNgayMoSo(SoTietKiem* stk, int n) {
    sort(stk, stk + n, soSanhTheoNgayMoSo);
    cout << "Danh sach cac so tiet kiem da duoc sap xep theo ngay mo so tang dan.\n";
}

/**
 * Cập nhật lãi suất của một sổ tiết kiệm theo yêu cầu của người dùng.
 * @param stk Sổ tiết kiệm cần cập nhật lãi suất.
 */
void capNhapLaiSuatNguoiDung(SoTietKiem& stk) {
    cout << "Nhap lai suat sau thay doi: ";
    int laiSuat;    cin >> laiSuat;
    stk.laiSuat = laiSuat;
    cout << "Lai suat cua nguoi dung da duoc cap nhap.\n";
}

/**
 * Hiển thị lãi suất hiện tại của ngân hàng cho các loại sổ tiết kiệm.
 */
void hienThiLaiSuat() {
    cout << "\t- Lai suat ngan han: " << laiSuatNganHan << "%" << endl;
    cout << "\t- Lai suat dai han: " << laiSuatDaiHan << "%" << endl;
    cout << "\t- Lai suat khong ky han: " << laiSuatKhongKyHan << "%" << endl;
}

/**
 * Hiển thị menu chính cho chương trình quản lý sổ tiết kiệm.
 */
void menu() {
    cout << "================ QUAN LY SO TIET KIEM ================\n";
    cout << "0. Hien thi menu\n";
    cout << "1. Nhap thong tin cac so tiet kiem\n";
    cout << "2. Xuat thong tin cac so tiet kiem\n";
    cout << "3. Sap xep so tiet kiem theo so tien gui (giam dan)\n";
    cout << "4. Sap xep so tiet kiem theo ngay mo so (tang dan)\n";
    cout << "5. Liet ke so tiet kiem mo trong khoang thoi gian\n";
    cout << "6. Tim kiem so tiet kiem theo ma so\n";
    cout << "7. Tim kiem so tiet kiem theo CMND\n";
    cout << "8. Cap nhap lai lai suat nguoi dung\n";
    cout << "9. Hien thi lai suat ngan hang hien tai\n";
    cout << "10. Tinh tien lai hien tai cua nguoi dung\n";
    cout << "11. Rut tien\n";
    cout << "12. Thoat\n";
    cout << "======================================================\n";
}

int main() {
    SoTietKiem* dsSoTietKiem = nullptr;
    int n = 0;
    int luaChon;
    bool hopLe;

    cout << fixed << setprecision(2);
    menu();
    do {
        cout << "\nNhap lua chon cua ban: ";    cin >> luaChon;
        cout << '\n';

        switch (luaChon)
        {
        case 0: {
            menu();
            break;
        }
        case 1: {
            cout << "Nhap so luong so tiet kiem: ";
            cin >> n;
            dsSoTietKiem = new SoTietKiem[n];

            for (int i = 0; i < n; ++i) {
                cout << "\nNhap thong tin so tiet kiem thu " << i + 1 << ":\n";
                nhapThongTinSoTietKiem(dsSoTietKiem[i]);
            }
            break;
        }
        case 2: {
            tieuDeBang();
            if (dsSoTietKiem != nullptr && n > 0) {
                for (int i = 0; i < n; ++i) {
                    xuatThongTinSoTietKiem(dsSoTietKiem[i]);
                }
            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }
        case 3: {
            if (dsSoTietKiem != nullptr && n > 0) {
                sapXepTheoSoTienGui(dsSoTietKiem, n);
            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }
        case 4: {
            if (dsSoTietKiem != nullptr && n > 0) {
                sapXepTheoNgayMoSo(dsSoTietKiem, n); 
            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }
        case 5: {
            if (dsSoTietKiem != nullptr && n > 0) {
                lietKeSoTietKiemTrongKhoangThoiGian(dsSoTietKiem, n);
            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }
        case 6: {
            if (dsSoTietKiem != nullptr && n > 0) {
                timSoTietKiemTheoMaSo(dsSoTietKiem, n);
            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }
        case 7: {
            if (dsSoTietKiem != nullptr && n > 0) {
                timSoTietKiemTheoCMND(dsSoTietKiem, n); 
            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }
        case 8: {
            if (dsSoTietKiem != nullptr && n > 0) {
                char maSo[6]; 

                do {
                    cout << "Nhap ma so (toi da 5 ky tu, khong co ky tu dac biet): ";
                    cin >> maSo;
                    hopLe = kiemTraMaSo(maSo);
                    if (!hopLe) 
                        cout << "Ma so khong hop le. Vui long nhap lai.\n";
                } while (!hopLe);

                for(int i = 0; i < n; ++i) 
                    if (maSo == dsSoTietKiem[i].maSo) 
                        capNhapLaiSuatNguoiDung(dsSoTietKiem[i]);

            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }
        case 9: {
            hienThiLaiSuat();
            break;
        }
        case 10: {
            if (dsSoTietKiem != nullptr && n > 0) {
                char maSo[6]; 

                do {
                    cout << "Nhap ma so (toi da 5 ky tu, khong co ky tu dac biet): ";
                    cin >> maSo;
                    hopLe = kiemTraMaSo(maSo);
                    if (!hopLe) 
                        cout << "Ma so khong hop le. Vui long nhap lai.\n";
                } while (!hopLe);

                for(int i = 0; i < n; ++i) 
                    if (maSo == dsSoTietKiem[i].maSo) 
                        cout << "\tLai suat tinh den hien tai cua nguoi dung: " << tinhTienLai(dsSoTietKiem[i]) << '\n';

            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }
        case 11: {
            if (dsSoTietKiem != nullptr && n > 0) {
                char maSo[6]; 

                do {
                    cout << "Nhap ma so (toi da 5 ky tu, khong co ky tu dac biet): ";
                    cin >> maSo;
                    hopLe = kiemTraMaSo(maSo);
                    if (!hopLe) 
                        cout << "Ma so khong hop le. Vui long nhap lai.\n";
                } while (!hopLe);

                for(int i = 0; i < n; ++i) 
                    if (maSo == dsSoTietKiem[i].maSo) 
                        rutTien(dsSoTietKiem[i]);

            } else {
                cout << "Chua co thong tin so tiet kiem nao duoc nhap.\n";
            }
            break;
        }

        case 12: {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }while (luaChon != 13);

    delete[] dsSoTietKiem;
    return 0;
}
