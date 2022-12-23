#pragma once

#include "Date.h"

class TaiKhoan {
protected:
    string tenDangNhap, matKhau;
    int ID;

public:
    TaiKhoan();
    TaiKhoan(string tenDangNhap, string matKhau, int ID);
    ~TaiKhoan(void);

    //get set
    string getTenDangNhap()
    {
        return this->tenDangNhap;
    };
    string getMatKhau()
    {
        return this->matKhau;
    };
    int getID()
    {
        return this->ID;
    };
    void setTenDangNhap(string tenDangNhap)
    {
        this->tenDangNhap = tenDangNhap;
    };
    void setMatKhau(string matKhau)
    {
        this->matKhau = matKhau;
    };
    void setID(int ID)
    {
        this->ID = ID;
    };
};

