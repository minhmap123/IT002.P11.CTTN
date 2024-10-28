#include "Diem.cpp"

int main() {
    float x, y; cin >> x >> y;
    Diem diem(x, y);

    int n;  cin >> n;
    int choice;
    int k;  float d;
    while (n--) {
        cin >> choice;
        switch (choice) {
        case 1: {
            diem.SetHoanhDo(diem.GetHoanhDo() * 2);
            diem.SetTungDo(diem.GetTungDo() * 2);
            break;
        }
        case 2: {
            diem.SetHoanhDo(0);
            diem.SetTungDo(0);
            break;
        }
        case 3: {
            cin >> k >> d;
            if (!k) diem.TinhTien(d, 0);
            else diem.TinhTien(0, d);
            break;
        }

        default:
            break;
        }
    }

    diem.Xuat();

    return 0;
}
