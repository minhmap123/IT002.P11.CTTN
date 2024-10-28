#pragma once

/**
 * @struct Node
 * @brief Đại diện cho một nút trong danh sách liên kết, chứa dữ liệu và con trỏ đến nút tiếp theo.
 */
struct Node {
    double data;  
    Node* next;   

    Node(double value) {
        data = value;
        next = nullptr;
    }
};
