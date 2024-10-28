#include <iostream>
#include <algorithm>
using namespace std;

// Kiểm tra xem rìa của hình chữ nhật có toàn số 0 không
bool isBorderZero(int** matrix, int x, int y, int w, int h, int rows, int cols) {
    for (int j = x; j < x + w; ++j) 
        if ((y > 0 && matrix[y - 1][j] != 0) || (y + h < rows && matrix[y + h][j] != 0)) return false;
    
    for (int i = y; i < y + h; ++i) 
        if ((x > 0 && matrix[i][x - 1] != 0) || (x + w < cols && matrix[i][x + w] != 0)) return false;
    
    return true;
}

// Kiểm tra xem tất cả phần tử trong hình chữ nhật có bằng 1 không
bool areAllOnes(int** matrix, int x, int y, int w, int h) {
    for (int i = y; i < y + h; ++i) 
        for (int j = x; j < x + w; ++j) 
            if (matrix[i][j] != 1) return false;
        
    return true;
}

// Tìm tất cả hình chữ nhật kích thước tối thiểu 2x2 với điều kiện phần tử bên trong là 1 và rìa là 0
int** findRectangles(int** matrix, int rows, int cols, int& rectCount) {
    bool** visited = new bool*[rows];
    for (int i = 0; i < rows; ++i) visited[i] = new bool[cols]();

    int** rectangles = new int*[1000];
    rectCount = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int width = 0, height = 0;

                // Tính chiều rộng
                while (j + width < cols && matrix[i][j + width] == 1) ++width;
                // Tính chiều cao
                while (i + height < rows && matrix[i + height][j] == 1) ++height;

                // Kiểm tra và thêm vào danh sách nếu thỏa mãn điều kiện
                if (width >= 2 && height >= 2 && isBorderZero(matrix, j, i, width, height, rows, cols) && areAllOnes(matrix, j, i, width, height)) {
                    rectangles[rectCount] = new int[4]{j, i, width, height};
                    rectCount++;

                    for (int p = i; p < i + height; ++p)
                        for (int q = j; q < j + width; ++q)
                            visited[p][q] = true;
                }
            }
        }
    }

    // Sắp xếp danh sách hình chữ nhật từ trên xuống dưới và trái sang phải
    sort(rectangles, rectangles + rectCount, [](int* a, int* b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    });

    for (int i = 0; i < rows; ++i) delete[] visited[i];
    delete[] visited;

    return rectangles;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int rectCount = 0;
    int** rectangles = findRectangles(matrix, rows, cols, rectCount);

    if (rectCount == 0) {
        cout << "Khong co hinh chu nhat nao thoa\n";
    } else {
        for (int i = 0; i < rectCount; ++i) {
            cout << "[" << rectangles[i][0] << ", " << rectangles[i][1] << ", " << rectangles[i][2] << ", " << rectangles[i][3] << "]\n";
            delete[] rectangles[i];
        }
    }

    delete[] rectangles;
    for (int i = 0; i < rows; ++i) delete[] matrix[i];
    delete[] matrix;

    return 0;
}
