#pragma once

#include "GiaSuc.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


/**
 * @brief Constructor của lớp GiaSuc.
 * @param so Số lượng gia súc ban đầu.
 * @param sua Tổng lượng sữa ban đầu.
 */
GiaSuc::GiaSuc(int so, int sua) : soLuong(so), tongSua(sua)  {}

/**
 * @brief Lấy số lượng gia súc.
 * @return Số lượng gia súc hiện tại.
 */
int GiaSuc::getSoLuong() const { return soLuong; }

/**
 * @brief Lấy tổng số lượng sữa của gia súc.
 * @return Tổng lượng sữa gia súc cho được.
 */
int GiaSuc::getTongSua() const { return tongSua; }

/**
 * @brief Constructor của lớp Bo.
 * @param so Số lượng bò ban đầu.
 * @param sua Tổng lượng sữa ban đầu.
 */
Bo::Bo(int so, int sua) : GiaSuc(so, sua) {}

/**
 * @brief Định nghĩa âm thanh của bò ("Moo Moo").
 */
void Bo::keu() const { 
    for (int i = 0; i < soLuong; ++i)
        cout << "Moo" << ' '; 
}

/**
 * @brief Mô tả hành vi sinh con của bò.
 *        Số con non được sinh ra ngẫu nhiên.
 */
void Bo::sinhCon() {
    int conNon = 0;
    for (int i = 0; i < soLuong; ++i) 
        conNon += rand() % 3;
    this->soLuong += conNon;
    cout << "Bo sinh ra " << conNon << " con." << endl;
}


/**
 * @brief Mô tả hành vi cho sữa của bò.
 *        Lượng sữa cho được tính ngẫu nhiên.
 */
void Bo::choSua() {
    int luongSua = 0;
    for (int i = 0; i < soLuong; ++i) 
        luongSua += rand() % 21;
    this->tongSua += luongSua;
    cout << "Bo cho " << luongSua << " lit sua." << endl;
}

/**
 * @class Cuu
 * @brief Lớp đại diện cho gia súc loại cừu, kế thừa từ GiaSuc.
 */
Cuu::Cuu(int so, int sua) : GiaSuc(so, sua) {}


/**
 * @brief Định nghĩa âm thanh của cừu ("Baa Baa").
 */
void Cuu::keu() const {
    for (int i = 0; i < soLuong; ++i)
        cout << "Baa" << ' '; 
}

/**
 * @brief Mô tả hành vi sinh con của cừu.
 *        Số con non được sinh ra ngẫu nhiên.
 */
void Cuu::sinhCon() {
    int conNon = 0;
    for (int i = 0; i < soLuong; ++i) 
        conNon += rand() % 3;
    this->soLuong += conNon;
    cout << "Cuu sinh ra " << conNon << " con." << endl;
}

/**
 * @brief Mô tả hành vi cho sữa của cừu.
 *        Lượng sữa cho được tính ngẫu nhiên.
 */
void Cuu::choSua() {
    int luongSua = 0;
    for (int i = 0; i < soLuong; ++i) 
        luongSua += rand() % 6;
    this->tongSua += luongSua;
    cout << "Cuu cho " << luongSua << " lit sua." << endl;
}

/**
 * @brief Constructor của lớp De.
 * @param so Số lượng dê ban đầu.
 * @param sua Tổng lượng sữa ban đầu.
 */
De::De(int so, int sua) : GiaSuc(so, sua) {} 


/**
 * @brief Định nghĩa âm thanh của dê ("Mee Mee").
 */
void De::keu() const {
    for (int i = 0; i < soLuong; ++i)
        cout << "Mee" << ' '; 
}

/**
 * @brief Mô tả hành vi sinh con của dê.
 *        Số con non được sinh ra ngẫu nhiên.
 */
void De::sinhCon() {
    int conNon = 0;
    for (int i = 0; i < soLuong; ++i) 
        conNon += rand() % 3;
    this->soLuong += conNon;
    cout << "De sinh ra " << conNon << " con." << endl;
}

/**
 * @brief Mô tả hành vi cho sữa của dê.
 *        Lượng sữa cho được tính ngẫu nhiên.
 */
void De::choSua() {
    int luongSua = 0;
    for (int i = 0; i < soLuong; ++i) 
        luongSua += rand() % 11;
    this->tongSua += luongSua;
    cout << "De cho " << luongSua << " lit sua." << endl;
}