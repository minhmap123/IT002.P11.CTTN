#include <iostream>
using namespace std;

/**
 * Hàm tính toán mảng LPS (Longest Prefix Suffix) cho một chuỗi.
 * 
 * @param A Mảng chứa các ký tự của chuỗi.
 * @param m Độ dài của chuỗi A.
 * @param lps Mảng để lưu trữ giá trị LPS.
 */
void computeLPSArray(int* A, int m, int* lps) {
    int length = 0; 
    lps[0] = 0; 
    int i = 1;

    while (i < m) {
        if (A[i] == A[length]) {
            ++length;
            lps[i] = length;
            ++i;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}

/**
 * Hàm tìm kiếm chuỗi con trong chuỗi lớn bằng thuật toán KMP.
 * 
 * @param A Mảng chứa các ký tự của chuỗi mẫu.
 * @param m Độ dài của chuỗi mẫu A.
 * @param B Mảng chứa các ký tự của chuỗi lớn.
 * @param n Độ dài của chuỗi lớn B.
 * @param count Biến tham chiếu để lưu số lượng vị trí tìm thấy.
 * @return Mảng chứa các vị trí bắt đầu của chuỗi mẫu trong chuỗi lớn.
 */
int* KMPsearch(int* A, int m, int* B, int n, int& count) {
    int* positions = new int[n]; 
    count = 0; 

    int* lps = new int[m]; 
    computeLPSArray(A, m, lps);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (A[j] == B[i]) {
            ++i;
            ++j;
        }

        if (j == m) {
            positions[count++] = i - j; 
            j = lps[j - 1];
        } else if (i < n && A[j] != B[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    delete[] lps; 
    return positions; 
}

int main() {
    int m, n; 
    cout << "Nhap do dai mang A va mang B: ";
    cin >> m >> n;

    int* A = new int[m];
    int* B = new int[n];

    cout << "Nhap mang A: ";
    for (int i = 0; i < m; ++i) 
        cin >> A[i];

    cout << "Nhap mang B: ";
    for (int i = 0; i < n; ++i) 
        cin >> B[i];
    
    int count; 
    int* positions = KMPsearch(A, m, B, n, count);

    cout << "So luong vi tri tim thay: " << count << endl;
    if (count > 0) {
        cout << "Cac vi tri tim thay: ";
        for (int i = 0; i < count; ++i) 
            cout << positions[i] << " ";
        cout << endl;
    } else {
        cout << "Khong tim thay vi tri nao." << endl;
    }

    delete[] A;
    delete[] B;
    delete[] positions;

    return 0;
}
