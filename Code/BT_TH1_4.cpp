#include <iostream>
#include <cmath>
using namespace std;

const double limit = 0.00001;

/**
 * Hàm tính giá trị sin(x) sử dụng chuỗi Taylor.
 * Chuỗi Taylor của sin(x) là:
 * sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 * 
 * Hàm này sẽ tính giá trị sin(x) với sai số nhỏ hơn giá trị giới hạn cho trước (limit).
 * 
 * @param x Giá trị góc tính theo radian.
 * @return Giá trị xấp xỉ của sin(x).
 */
double tinhSin(double x) {
    double result = x;  
    double term = x;    
    int i = 1;         

    while (fabs(term) > limit) {
        term *= (-1) * x * x / ((2 * i) * (2 * i + 1));
        result += term;  
        ++i;       
    }

    return result;  
}

int main() {
    cout << "X = ";
    double x;   cin >> x;

    double result = tinhSin(x);

    cout << "sin(" << x << ") = " << result << endl;

    return 0;
}
