#pragma once
#include "nodeEmployee.h"

class listEmployee : public nodeEmployee
{
private:
	NodeEmployee head;
	NodeEmployee tail;
	int size;
	int idAdmin;

public:
	listEmployee();

	int getSize();
	int getIdAdmin();

	/*void docFile(ifstream& f, Employee& e);*/
	void nhapDanhSachNhanVien(int); //ok

	void layDanhSachTuFile(string); //ok
	void ghiFile(string); //ok

	void xuatTrenXuong(); //ok
	void xuatDuoiLen();

	void themPhanTu(NodeEmployee); //ok

	void xoaDau(); //ok
	void xoaCuoi(); //ok
	void xoaNhanVienIndex(int pos, int& idNVXoa); //ok
	void suaNhanVienIndex(int pos); //ok

	//not
	void sapXepTheoMaNhanVien();
	void sapXepTheoTen(); //oke

	string tachTenNguoi(string ht); //ok
	void timPhanTuTheoTen(string); //ok
	void timPhanTuTheoIdNhanVien(int idNhanVien); //ok
	void suaNhanVienTheoId(int); //ok

	bool kiemTraTrungID(string ID);

	void ghiTaiKhoanVaoFileNhanVienH(string tenFile, TaiKhoan tk, int idAdmin)
	{
		ofstream ghi(tenFile, ios::app);

		if (!ghi.is_open())
		{
			cout << "Khong the mo file!";
			exit(1);
		}

		ghi << tk.getID() << ";" << idAdmin << ';' << tk.getTenDangNhap() << ";" << tk.getMatKhau() << endl;
		ghi.close();
	}
};