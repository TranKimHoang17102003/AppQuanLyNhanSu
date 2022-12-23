//https://github.com/TranKimHoang17102003/AppQuanLyNhanSu.git
//testpush

#include "MenuDangKiDangNhap.h"

void menuAdmin(int idAdmin)
{
	listEmployee l;
	string path = pathFile(idAdmin);
	l.layDanhSachTuFile(path);

	int lc = -1;

	do
	{
		cout << endl << "______________Menu Danh Cho Admin______________" << endl;
		cout << "1. Xem danh sach nhan vien" << endl;
		cout << "2. Them nhan vien" << endl; //tu dong tao 1 tai khoan cho nhan vien vao file do lu�n: tk: id Nhan Vien, mk: id cong ty
		cout << "3. Sua mot nhan vien theo vi tri pos" << endl;
		cout << "4. Xoa nhan vien theo vi tri pos" << endl;
		cout << "5. Xem so luong danh sach" << endl;
		cout << "6. Xem phan tu thu n trong danh sach" << endl;
		cout << "7. Tim nhan vien theo IdNhanVien" << endl;
		cout << "8. Tim nhan vien theo ten" << endl;
		cout << "9. Sap xep nhan vien theo ten" << endl;
		cout << "10. Sap xep nhan vien theo ma nhan vien"<<endl;
		cout << "-1. Dang xuat" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "" << endl;

		cout << "Nhap lua chon: ";
		cin >> lc;

		if (lc == 0)
		{
			l.ghiFile(path);
			exit(1);
		}
		else if (lc == 1)
		{
			cout << left;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << setw(2);
			cout << "| ";
			cout << setw(14);
			cout << "Ma nhan vien";
			cout << setw(2);
			cout << "| ";
			cout << setw(18);
			cout << "Ho ten";
			cout << setw(2);
			cout << "| ";
			cout << setw(12);
			cout << "Ma chuc vu";
			cout << setw(2);
			cout << "| ";
			cout << setw(12);
			cout << "Gioi tinh";
			cout << setw(2);
			cout << "| ";
			cout << setw(12);
			cout << "Dia chi";
			cout << setw(2);
			cout << "| ";
			cout << setw(10);
			cout << "Hoc van";
			cout << setw(2);
			cout << "| ";

			//Qua tai toan tu xuat
			cout << setw(15);
			cout << "Ngay sinh";
			cout << setw(2);
			cout << "| ";
			cout << setw(15);
			cout << "Ngay vao lam";
			cout << setw(2);
			cout << "| ";
			cout << setw(15);
			cout << "So dien thoai";
			cout << setw(2);
			cout << "| ";
			cout << setw(15);
			cout << "So CMND";
			cout << setw(2);
			cout << "|";
			cout << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			l.xuatTrenXuong();
		}
		else if (lc == 2)
		{
			l.nhapDanhSachNhanVien(idAdmin);
		}
		else if (lc == 3)
		{
			int pos;
			cout << "Nhap vi tri muon sua: ";
			cin >> pos;
			l.suaNhanVienIndex(pos);
		}
		else if (lc == 4)
		{
			int pos;
			cout << "Nhap vi tri muon xoa: ";
			cin >> pos;
			int idNVXoa;
			l.xoaNhanVienIndex(pos, idNVXoa);
			cout << "Id nhan vien da bi xoa la: " << idNVXoa<<endl;
			setIdAdminTrongTKNV(idNVXoa, 0);
		}
		else if (lc == 5)
		{
			cout << "So luong nhan vien: " << l.getSize();
		}
		else if (lc == 6)
		{

		}
		else if (lc == -1)
		{
			l.ghiFile(path);
			return;
		}
		else if (lc == 7)
		{
			int n;
			cout << "Nhap Id nhan vien: ";
			cin >> n;
			l.timPhanTuTheoIdNhanVien(n);
		}
		else if (lc == 8)
		{
			string s;
			cout << "Nhap ten nhan vien: ";
			cin >> s;
			l.timPhanTuTheoTen(s);
		}
		else if (lc == 9)
		{
			l.sapXepTheoTen();
		}
		else if (lc == 10) 
		{
			l.sapXepTheoMaNhanVien();
		}

	} while (lc != 0);
}

void menuNhanVien(int idAdmin, int idNhanVien)
{
	while (idAdmin == 0)
	{
		cout << "Ban chua co cong ty xin moi nhap id cong ty cua ban(0 de thoat ct): ";
		cin >> idAdmin;

		if (idAdmin == 0) exit(1);
		if (kTraIdAdminCoTonTai(idAdmin, "QLTaiKhoanMatKhauAdmin.txt") == true)
		{
			cout << "Nhap ID cong ty thanh cong!" << endl;
			Employee e;
			e.setIdNhanVien(idNhanVien);
			e.setIdAdmin(idAdmin);
			themNhanVienVaoFileDS(e, idAdmin); // dslkd
			setIdAdminTrongTKNV(idNhanVien, idAdmin);
			break;
		}
		cout << "Id khong dung!" << endl;
		idAdmin = 0;
	}


	listEmployee l;
	string path = pathFile(idAdmin);
	l.layDanhSachTuFile(path);

	int lc = -1;
	do
	{
		cout << endl << "______________Menu Danh Cho Nhan Vien______________" << endl;
		cout << "1. Xem thong tin cua minh" << endl;
		cout << "2. Sua thong tin ban than" << endl;
		cout << "3. Xem ID cong ty" << endl;
		cout << "4. Xem ID cua minh" << endl;
		cout << "-1. Dang xuat" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "" << endl;

		cout << "Nhap lua chon: ";
		cin >> lc;

		if (lc == 0)
		{
			l.ghiFile(path);
			exit(1);
		}
		else if (lc == -1)
		{
			l.ghiFile(path);
			return;
		}
		else if (lc == 1)
		{
			cout << left;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << setw(2);
			cout << "| ";
			cout << setw(14);
			cout << "Ma nhan vien";
			cout << setw(2);
			cout << "| ";
			cout << setw(18);
			cout << "Ho ten";
			cout << setw(2);
			cout << "| ";
			cout << setw(12);
			cout << "Ma chuc vu";
			cout << setw(2);
			cout << "| ";
			cout << setw(12);
			cout << "Gioi tinh";
			cout << setw(2);
			cout << "| ";
			cout << setw(12);
			cout << "Dia chi";
			cout << setw(2);
			cout << "| ";
			cout << setw(10);
			cout << "Hoc van";
			cout << setw(2);
			cout << "| ";

			//Qua tai toan tu xuat
			cout << setw(15);
			cout << "Ngay sinh";
			cout << setw(2);
			cout << "| ";
			cout << setw(15);
			cout << "Ngay vao lam";
			cout << setw(2);
			cout << "| ";
			cout << setw(15);
			cout << "So dien thoai";
			cout << setw(2);
			cout << "| ";
			cout << setw(15);
			cout << "So CMND";
			cout << setw(2);
			cout << "|";
			cout << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			l.timPhanTuTheoIdNhanVien(idNhanVien);
		}
		else if (lc == 2)
		{
			l.suaNhanVienTheoId(idNhanVien);
		}
		else if (lc == 3)
		{
			cout << "Id cong ty: " << idAdmin;
		}
		else if (lc == 4)
		{
			cout << "Id cua toi: " << idNhanVien;
		}
		else if (lc == 5)
		{

		}
	} while (lc != 0);
}

int main()
{
	manHinhDangNhap:
		int lc = menuLuaChonDangNhapHayDangKi();

		if (lc == 1) {
			lc = menuDangKi();
			if (lc == 1)
			{
				dangKiNhanVien();
				goto manHinhDangNhap;
			}
			else {
				dangKiAdmin();
				goto manHinhDangNhap;
			}
		}
		else
		{
			lc = menuDangNhap();
			if (lc == 1)
			{
				int thisIdAdMin=0, thisIdNhanVien=0;

				if (dangNhapNhanVien(thisIdAdMin, thisIdNhanVien))
				{
					cout << "Dang nhap thanh cong"<<endl;

					menuNhanVien(thisIdAdMin, thisIdNhanVien);
					goto manHinhDangNhap;
				}
				else {
					cout << "Dang nhap that bai" << endl;
					goto manHinhDangNhap;
				}
			}
			else
			{
				//okii r
				int thisIdAdMin = 0;

				if (dangNhapAdmin(thisIdAdMin))
				{
					cout << "Dang nhap thanh cong" << endl;
					menuAdmin(thisIdAdMin);
					goto manHinhDangNhap;
				}
				else
				{
					cout << "Dang nhap that bai" << endl;
					goto manHinhDangNhap;
				}
			}
		}

	return 0;
}
