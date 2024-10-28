#include "List.h"
#include <iostream>
using namespace std;

/**
 * @brief Khởi tạo một danh sách liên kết trống.
 */
List::List() {
    head = nullptr;
    size = 0;
}

/**
 * @brief Giải phóng bộ nhớ của danh sách liên kết.
 */
List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

/**
 * @brief Thêm một phần tử vào cuối danh sách.
 * @param x Giá trị của phần tử cần thêm.
 */
void List::insertAtBeginning(double x) {
    Node* newNode = new Node(x);

    if (head == nullptr) 
        head = newNode; 
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; 
        }
        current->next = newNode; 
    }
    ++size;
}

/**
 * @brief Xóa phần tử đầu tiên có giá trị cho trước trong danh sách.
 * @param x Giá trị của phần tử cần xóa.
 */
void List::RemoveFirst(double x) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == x) {
            if (prev == nullptr) 
                head = current->next;
            else 
                prev->next = current->next;
            delete current;  
            --size;
            return;  
        }
        prev = current;
        current = current->next;
    }
}

/**
 * @brief Xóa tất cả các phần tử có giá trị cho trước trong danh sách.
 * @param x Giá trị của các phần tử cần xóa.
 */
void List::RemoveAll(double x) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == x) {
            if (prev == nullptr) 
                head = current->next;
            else 
                prev->next = current->next;
            Node* temp = current;
            current = current->next;
            delete temp; 
            ++size;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

/**
 * @brief Thay thế giá trị của phần tử tại chỉ số cho trước.
 * @param index Vị trí phần tử cần thay thế.
 * @param y Giá trị mới thay thế.
 */
void List::Replace(int index, double y) {
    if (index < 0 || index >= size) return;

    Node* current = head;
    for (int i = 0; i < index; ++i) 
        current = current->next;
    
    current->data = y;  
}

/**
 * @brief In danh sách ra màn hình ở dạng `[val1, val2, ...]`.
 */
void List::Print() {
    cout << "[";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        current = current->next;
        if (current != nullptr) cout << ", ";
    }
    cout << "]" << endl;
}
