#pragma once
#include "Node.h"

/**
 * @class List
 * @brief Quản lý một danh sách liên kết đơn với các phương thức thao tác.
 */
class List {
private:
    Node* head;  
    int size; 

public:
    List();      
    ~List();      
    void insertAtBeginning(double x);        
    void RemoveFirst(double x);   
    void RemoveAll(double x);    
    void Replace(int index, double y); 
    void Print();    
};
