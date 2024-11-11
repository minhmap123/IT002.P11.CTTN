#include "ThoiGian.cpp"

int main() {
    cout << "Nhap thoi gian 1 (gio phut giay): ";
    ThoiGian time1;     
    cin >> time1;

    cout << "Nhap thoi gian 2 (gio phut giay): ";
    ThoiGian time2;     
    cin >> time2;

    cout << "--> Thoi gian 1: " << time1 << endl;
    cout << "--> Thoi gian 2: " << time2 << endl;

    cout << "--> Tong 2 thoi gian: " << time1 + time2 << endl;
    cout << "--> Hieu 2 thoi gian: " << time1 - time2 << endl;

    int x;
    cout << "Nhap so giay muon cong them vao thoi gian 1: ";
    cin >> x;
    cout << "--> Thoi gian 1 sau khi cong " << x << " giay: " << (time1 + x) << endl;

    cout << "Nhap so giay muon tru khoi thoi gian 2: ";
    cin >> x;
    cout << "--> Thoi gian 2 sau khi tru " << x << " giay: " << (time2 - x) << endl;

    cout << "--> 2 thoi gian co bang nhau khong? " << ((time1 == time2) ? "Dung" : "Sai") << endl;
    cout << "--> 2 thoi gian co khac nhau khong? " << ((time1 != time2) ? "Dung" : "Sai") << endl;
    cout << "--> Thoi gian 1 lon hon thoi gian 2? " << ((time1 > time2) ? "Dung" : "Sai") << endl;
    cout << "--> Thoi gian 1 nho hon thoi gian 2? " << ((time1 < time2) ? "Dung" : "Sai") << endl;

    cout << "--> Thoi gian 1 sau khi tang 1 giay: " << ++time1 << endl;
    cout << "--> Thoi gian 2 sau khi giam 1 giay: " << ++time2 << endl;

    return 0;
}
