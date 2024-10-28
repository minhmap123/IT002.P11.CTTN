#include "List.cpp"

int main() {
    List myList;
    int n;

    while (true) {
        // cout << "Nhap chi thi (0: them, 1: xoa 1, 2: xoa tat ca, 3: thay the, -1: ket thuc): ";
        cin >> n;

        if (n == -1) {
            break;  
        }

        if (n == 0) {
            double x;
            // cout << "Nhap gia tri can them: ";
            cin >> x;
            myList.insertAtBeginning(x);
        } 
        else if (n == 1) {
            double x;
            // cout << "Nhap gia tri can xoa (dau tien): ";
            cin >> x;
            myList.RemoveFirst(x);
        } 
        else if (n == 2) {
            double x;
            // cout << "Nhap gia tri can xoa (tat ca): ";
            cin >> x;
            myList.RemoveAll(x);
        } 
        else if (n == 3) {
            int x;
            double y;
            // cout << "Nhap chi so va gia tri moi: ";
            cin >> x >> y;
            myList.Replace(x, y);
        }
    }

    // cout << "List hien tai: ";
    myList.Print(); 

    return 0;
}
