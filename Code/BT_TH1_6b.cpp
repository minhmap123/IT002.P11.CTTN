#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

// Cấu trúc lưu trữ thông tin của học sinh
struct HocSinh {
    string hoTen;
    double diemToan;
    double diemVan;
    double diemAnh;
    double diemTrungBinh;
    string xepLoai;
};

/**
 * Kiểm tra tính hợp lệ của tên học sinh.
 * 
 * @param hoTen Tên học sinh cần kiểm tra.
 * @return true nếu tên hợp lệ, false nếu không hợp lệ.
 */
bool kiemTraTenHopLe(string hoTen) {
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
 * Kiểm tra tính hợp lệ của điểm số.
 * 
 * @param diem Điểm cần kiểm tra.
 * @return true nếu điểm hợp lệ, false nếu không hợp lệ.
 */
bool kiemTraDiemHopLe(const double& diem) {
    return diem >= 0 && diem <= 10;
}

/**
 * Tính điểm trung bình dựa trên điểm các môn học.
 * 
 * @param toan Điểm môn Toán.
 * @param van Điểm môn Văn.
 * @param anh Điểm môn Ngoại ngữ.
 * @return Điểm trung bình.
 */
double tinhDiemTrungBinh(const double& toan, const double& van, const double& anh) {
    return (2 * toan + van + anh) / 4;
}


/**
 * Xếp loại học sinh dựa trên điểm trung bình.
 * 
 * @param diemTrungBinh Điểm trung bình của học sinh.
 * @return Xếp loại của học sinh.
 */
string xepLoaiHocSinh(const double& diemTrungBinh) {
    if (diemTrungBinh >= 9) return "Xuat sac";
    else if (diemTrungBinh >= 8) return "Gioi";
    else if (diemTrungBinh >= 6.5) return "Kha";
    else if (diemTrungBinh >= 5) return "Trung binh";
    return "Yeu";
}

/**
 * Nhập điểm cho một môn học.
 * 
 * @param monHoc Tên môn học.
 * @return Điểm nhập vào.
 */
double nhapDiem(const string& monHoc) {
    double diem;
    cout << "Nhap diem " << monHoc << " (0-10): ";
    while (true) {
        cin >> diem;
        if (kiemTraDiemHopLe(diem)) break;
        else {
            cout << "Diem " << monHoc << " khong hop le. Vui long nhap lai: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return diem;
}

/**
 * Nhập thông tin cho một học sinh.
 * 
 * @param hs Học sinh cần nhập thông tin.
 */
void nhapThongTinHocSinh(HocSinh& hs) {
    cout << "Nhap ho ten hoc sinh (vd: Nguyen Van A): ";
    while (true) {
        getline(cin, hs.hoTen);
        if (kiemTraTenHopLe(hs.hoTen)) break;
        else cout << "Ten khong hop le. Vui long nhap lai: ";
    }

    hs.diemToan = nhapDiem("Toan");
    hs.diemVan = nhapDiem("Van");
    hs.diemAnh = nhapDiem("Ngoai ngu");

    hs.diemTrungBinh = tinhDiemTrungBinh(hs.diemToan, hs.diemVan, hs.diemAnh);
    hs.xepLoai = xepLoaiHocSinh(hs.diemTrungBinh);
}

/**
 * In thông tin của một học sinh.
 * 
 * @param hs Học sinh cần in thông tin.
 */
void inThongTinHocSinh(const HocSinh& hs) {
    cout << "Ho ten: " << hs.hoTen << '\n';
    cout << "\tDiem Toan: " << hs.diemToan << '\n';
    cout << "\tDiem Van: " << hs.diemVan << '\n';
    cout << "\tDiem Anh: " << hs.diemAnh << '\n';
    cout << "\tDiem trung binh: " << fixed << setprecision(2) << hs.diemTrungBinh << '\n';
    cout << "\tXep loai: " << hs.xepLoai << '\n';
}

/**
 * Tìm học sinh có điểm trung bình cao nhất.
 * 
 * @param hsArr Mảng chứa thông tin học sinh.
 * @param n Số lượng học sinh.
 */
void timHocSinhDiemCaoNhat(HocSinh* hsArr, int n) {
    double maxDiem = hsArr[0].diemTrungBinh;
    HocSinh hsXuatSac = hsArr[0];

    for (int i = 1; i < n; ++i) {
        if (hsArr[i].diemTrungBinh > maxDiem) {
            maxDiem = hsArr[i].diemTrungBinh;
            hsXuatSac = hsArr[i];
        }
    }

    cout << "\nHoc sinh co diem trung binh cao nhat:\n";
    inThongTinHocSinh(hsXuatSac);
}

/**
 * Tìm học sinh theo tên.
 * 
 * @param hsArr Mảng chứa thông tin học sinh.
 * @param n Số lượng học sinh.
 * @param tuKhoa Từ khóa để tìm kiếm.
 */
void timTheoTen(HocSinh* hsArr, int n, string& tuKhoa) {
    cout << "\nKet qua tim kiem cho \"" << tuKhoa << "\":\n";
    for (char& c : tuKhoa) 
        if (c >= 'A' && c <= 'Z') 
            c += 32;
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        string tenThuong = "";
        for (char c : hsArr[i].hoTen) 
            if (c >= 'A' && c <= 'Z') 
                tenThuong += c + 32; 
            else 
                tenThuong += c; 

        if (tenThuong.find(tuKhoa) != string::npos) {
            ++count;
            cout << count << ". ";
            inThongTinHocSinh(hsArr[i]);
        }     
    }
}

/**
 * Tìm học sinh có điểm Toán thấp nhất.
 * 
 * @param hsArr Mảng chứa thông tin học sinh.
 * @param n Số lượng học sinh.
 */
void timHocSinhDiemToanThapNhat(HocSinh* hsArr, int n) {
    double minDiemToan = hsArr[0].diemToan;

    for (int i = 1; i < n; ++i) 
        if (hsArr[i].diemToan < minDiemToan) 
            minDiemToan = hsArr[i].diemToan; 

    cout << "\nHoc sinh co diem toan thap nhat (diem Toan = " << minDiemToan <<"):\n";
    int count = 0;
    for (int i = 0; i < n; ++i) 
        if (hsArr[i].diemToan == minDiemToan) {
            ++count;
            cout << count << ". ";
            cout << "Ho ten: " << hsArr[i].hoTen << '\n';
        }
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    cin.ignore();

    HocSinh* hsArr = new HocSinh[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin cho hoc sinh thu " << i + 1 << ":\n";
        nhapThongTinHocSinh(hsArr[i]);
        cin.ignore();
    }
    sort(hsArr, hsArr + n, [](const HocSinh& hs1, const HocSinh& hs2) {
        return hs1.hoTen < hs2.hoTen; 
    });

    cout << "-------------------------------------------------------------------------";
    cout << "\nDanh sach hoc sinh:\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". ";
        inThongTinHocSinh(hsArr[i]);
    }
        
    cout << "-------------------------------------------------------------------------";
    timHocSinhDiemCaoNhat(hsArr, n);

    cout << "-------------------------------------------------------------------------";
    string tuKhoa;
    cout << "\nNhap ten de tim kiem: ";
    getline(cin, tuKhoa);
    timTheoTen(hsArr, n, tuKhoa);

    cout << "-------------------------------------------------------------------------";
    timHocSinhDiemToanThapNhat(hsArr, n);

    delete[] hsArr;

    return 0;
}
