#include <iostream>
using namespace std;

const int MAX_N = 1000;
int matrix[MAX_N][MAX_N], tempMatrix[MAX_N][MAX_N], originalMatrix[MAX_N][MAX_N];
int n, steps = 0;

// Kiểm tra xem ma trận hiện tại có giống với ma trận ban đầu không
bool isEqualToOriginal() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] != originalMatrix[i][j]) 
                return false;
        }
    }
    return true;
}

// Thực hiện một lần biến đổi ma trận
void transformMatrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int newRow = (2 * i + j) % n + 1;
            int newCol = (i + j) % n + 1;
            tempMatrix[newRow][newCol] = matrix[i][j];
        }
    }

    // Cập nhật lại ma trận `matrix` từ `tempMatrix`
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }

    steps++;

    // Nếu ma trận đã trở về dạng ban đầu, in số bước và thoát chương trình
    if (isEqualToOriginal()) {
        cout << steps;
        exit(0);
    }
}

int main() {
    // Nhập kích thước và các phần tử của ma trận
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
            originalMatrix[i][j] = matrix[i][j];
        }
    }

    // Lặp vô hạn, thực hiện biến đổi cho đến khi ma trận trở về dạng ban đầu
    while (true) transformMatrix();
    

    return 0;
}
