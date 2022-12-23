#include "TaiKhoan.h"

TaiKhoan::TaiKhoan() {
    this->tenDangNhap = "";
    this->matKhau = "";
}

TaiKhoan::TaiKhoan(string tenDangNhap, string matKhau, int ID) {
    this->tenDangNhap = tenDangNhap;
    this->matKhau = matKhau;
    this->ID = ID;
}

TaiKhoan::~TaiKhoan() {

}