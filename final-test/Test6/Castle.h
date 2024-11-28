# pragma once

#include "Prince.cpp"

class Gate {
public:
    virtual ~Gate() {}
    virtual bool quaCong(Prince&) = 0;
};

class BusinessGate : public Gate {
private: 
    long long donGia;
    int soHang;

public: 
    BusinessGate(long long gia, int so);
    bool quaCong(Prince& hoangTu);
};

class AcademicGate : public Gate {
private:
    int triTueCanThiet;

public: 
    AcademicGate(int triTue);
    bool quaCong(Prince& hoangTu);
};


class PowerGate : public Gate {
private:
    int sucManhCanThiet;

public:    
    PowerGate(int sucManh);
    bool quaCong(Prince& hoangTu);
};


class Castle {
private: 
    Gate** dsGate;
    int soCong;

public:
    Castle(int n);
    ~Castle();
    void Nhap();
    bool vuotQuaHetCong(Prince& hoangTu);
};
