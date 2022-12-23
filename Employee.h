#pragma once

#include <string>
#include <fstream>
#include "taiKhoan.h"
#include <iomanip>


//include lib
#define _CRT_SECURE_NO_WARNINGS

class Employee :public Date
{
public:
	int idNhanVien, idAdmin;
	string maNhanVien, hoTen, maChucVu, gioiTinh, diaChi, hocVan;
	Date ngaySinh, ngayVaoLam;
	int soDienThoai;
	string soCMND;

	//them 
	int luong;
	int luongCoBan;
	double heSoLuong;
	double phuCap;

public:
	Employee();
	Employee(string maNhanVien, string hoTen, string maChucVu, string gioiTinh, string diaChi, string hocVan, Date ngaySinh, Date ngayVaoLam, int soDienThoai, string soCMND, int luongCoBan, double heSoLuong);
	~Employee(void);

	int getIdNhanVien() { return idNhanVien; }
	int getIdAdmin() { return idAdmin; }
	string getMaNhanVien() { return maNhanVien; };
	string getHoTen() { return hoTen; };
	string getMaChucVu() { return maChucVu; };
	string getGioiTinh() { return gioiTinh; };
	string getDiaChi() { return diaChi; };
	string getHocVan() { return hocVan; };
	int getSoDienThoai() { return soDienThoai; };
	string getSoCMND() { return soCMND; };

	int getLuong() { return luong; };
	int getLuongCoBan() { return luongCoBan; };
	double getHeSoLuong() { return heSoLuong; };
	double getPhuCap() { return phuCap; };

	void setPhuCap();
	void setLuong();
	void setLuongCoBan(int);
	void setHeSoLuong(float);

	void setMaNhanVien(string s);
	void setHoTen(string s);
	void setMaChucVu(string s);
	void setGioiTinh(string s);
	void setDiaChi(string s);
	void setHocVan(string s);
	void setNgaySinh(Date d);
	void setNgayVaoLam(Date d);
	void setSoDienThoai(int n);
	void setSoCMND(string n);
	void setIdNhanVien(int n) { this->idNhanVien = n; }
	void setIdAdmin(int n) { this->idAdmin = n; }

	Employee nhap();

	void xuat();

	void layIDDaDungTuFileH(string tenFile, int& RegisterID)
	{
		fstream f;
		f.open(tenFile);
		f >> RegisterID;
		f.close();
	}

	void ghiIDDaDungVaoFileH(string tenFile, int RegisterID)
	{
		fstream ghiIDDaDung;
		ghiIDDaDung.open(tenFile);
		ghiIDDaDung << RegisterID;
		ghiIDDaDung.close();
	}


};

