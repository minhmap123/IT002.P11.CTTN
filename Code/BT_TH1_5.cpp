#include <iostream>

using namespace std;

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

/**
 * Hàm kiểm tra xem một năm có phải là năm nhuận hay không.
 * 
 * @param nam Năm cần kiểm tra.
 * @return true nếu là năm nhuận, false nếu không phải.
 */
bool laNamNhuan(int nam) {
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
        return true;
    return false;
}

/**
 * Hàm trả về số ngày trong một tháng của một năm.
 * 
 * @param thang Tháng cần kiểm tra.
 * @param nam Năm cần kiểm tra (để xác định năm nhuận).
 * @return Số ngày trong tháng.
 */
int soNgayTrongThang(int thang, int nam) {
    int ngayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (laNamNhuan(nam)) {
        ngayTrongThang[1] = 29;
    }
    return ngayTrongThang[thang - 1];
}

/**
 * Hàm kiểm tra xem ngày, tháng, năm có hợp lệ hay không.
 * 
 * @param ngay Ngày cần kiểm tra.
 * @param thang Tháng cần kiểm tra.
 * @param nam Năm cần kiểm tra.
 * @return true nếu ngày hợp lệ, false nếu không.
 */
bool laNgayHopLe(int ngay, int thang, int nam) {
    if (nam < 1 || thang < 1 || thang > 12) {
        return false;
    }
    int maxNgay = soNgayTrongThang(thang, nam);
    if (ngay < 1 || ngay > maxNgay) {
        return false;
    }
    return true;
}

/**
 * Hàm trả về ngày tiếp theo của một ngày cho trước.
 * 
 * @param ngayHienTai Ngày hiện tại.
 * @return Ngày tiếp theo.
 */
Ngay ngayKeTiep(Ngay ngayHienTai) {
    if (ngayHienTai.ngay < soNgayTrongThang(ngayHienTai.thang, ngayHienTai.nam)) {
        ++ngayHienTai.ngay;
    } else {
        ngayHienTai.ngay = 1;
        if (ngayHienTai.thang < 12) {
            ++ngayHienTai.thang;
        } else {
            ngayHienTai.thang = 1;
            ++ngayHienTai.nam;
        }
    }
    return ngayHienTai;
}

/**
 * Hàm trả về ngày trước đó của một ngày cho trước.
 * 
 * @param ngayHienTai Ngày hiện tại.
 * @return Ngày trước đó.
 */
Ngay ngayTruocDo(Ngay ngayHienTai) {
    if (ngayHienTai.ngay > 1) {
        --ngayHienTai.ngay;
    } else {
        if (ngayHienTai.thang > 1) {
            --ngayHienTai.thang;
            ngayHienTai.ngay = soNgayTrongThang(ngayHienTai.thang, ngayHienTai.nam);
        } else {
            ngayHienTai.thang = 12;
            ngayHienTai.ngay = 31;
            --ngayHienTai.nam;
        }
    }
    return ngayHienTai;
}

/**
 * Hàm trả về ngày thứ bao nhiêu trong năm của một ngày cho trước.
 * 
 * @param ngayHienTai Ngày hiện tại.
 * @return Số thứ tự ngày trong năm.
 */
int ngayThuBaoNhieuTrongNam(Ngay ngayHienTai) {
    int ngayThu = 0;
    for (int i = 1; i < ngayHienTai.thang; ++i) {
        ngayThu += soNgayTrongThang(i, ngayHienTai.nam);
    }
    ngayThu += ngayHienTai.ngay;
    return ngayThu;
}

int main() {
    Ngay ngayHienTai;

    cout << "Nhap ngay thang nam (dd mm yyyy): ";
    cin >> ngayHienTai.ngay >> ngayHienTai.thang >> ngayHienTai.nam;

    if (!laNgayHopLe(ngayHienTai.ngay, ngayHienTai.thang, ngayHienTai.nam)) {
        cout << "Ngay khong hop le!" << endl;
        return 1;
    }

    Ngay ngayKe = ngayKeTiep(ngayHienTai);
    cout << "Ngay ke tiep: " << ngayKe.ngay << "/" << ngayKe.thang << "/" << ngayKe.nam << endl;

    Ngay ngayTruoc = ngayTruocDo(ngayHienTai);
    cout << "Ngay truoc do: " << ngayTruoc.ngay << "/" << ngayTruoc.thang << "/" << ngayTruoc.nam << endl;

    cout << "Ngay " << ngayHienTai.ngay << "/" << ngayHienTai.thang << "/" << ngayHienTai.nam << " la ngay thu " << ngayThuBaoNhieuTrongNam(ngayHienTai) << " trong nam." << endl;

    return 0;
}
