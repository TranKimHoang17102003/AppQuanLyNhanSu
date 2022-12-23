#include "Employee.h"

//---------------

Employee::Employee()
{
	this->maNhanVien = "0";
	this->hoTen = "0";
	this->maChucVu = "0";
	this->gioiTinh = "0";
	this->diaChi = "0";
	this->hocVan = "0";

	//Qua tai toan tu gan
	Date d;
	this->ngaySinh = d;
	this->ngayVaoLam = d;

	this->soDienThoai = -1;
	this->soCMND = "0";

	luongCoBan = -1;
	heSoLuong = 1.0;
}

Employee::Employee(string maNhanVien, string hoTen, string maChucVu, string gioiTinh, string diaChi, string hocVan, Date ngaySinh, Date ngayVaoLam, int soDienThoai, string soCMND, int luongCoBan, double heSoLuong)
{
	this->maNhanVien = maNhanVien;
	this->hoTen = hoTen;
	this->maChucVu = maChucVu;
	this->gioiTinh = gioiTinh;
	this->diaChi = diaChi;
	this->hocVan = hocVan;

	//Qua tai toan tu gan
	this->ngaySinh = ngaySinh;
	this->ngayVaoLam = ngayVaoLam;

	this->soDienThoai = soDienThoai;
	this->soCMND = soCMND;

	this->luongCoBan = luongCoBan;
	this->heSoLuong = heSoLuong;
}

Employee::~Employee(void)
{

}

void Employee::setMaNhanVien(string s)
{
	this->maNhanVien = s;
}
void Employee::setHoTen(string s)
{
	this->hoTen = s;
}
void Employee::setMaChucVu(string s)
{
	this->maChucVu = s;
}
void Employee::setGioiTinh(string s)
{
	this->gioiTinh = s;
}
void Employee::setDiaChi(string s)
{
	this->diaChi = s;
}
void Employee::setHocVan(string s)
{
	this->hocVan = s;
}
void Employee::setNgaySinh(Date d)
{
	this->ngaySinh = d;
}
void Employee::setNgayVaoLam(Date d)
{
	this->ngayVaoLam = d;
}
void Employee::setSoDienThoai(int n)
{
	this->soDienThoai = n;
}
void Employee::setSoCMND(string n)
{
	this->soCMND = n;
}
void Employee::setPhuCap()
{
	time_t t = time(0);
	int yearNow = (localtime(&t)->tm_year + 1900);
	int year = yearNow - this->ngayVaoLam.getY();

	if (year >= 5 && year < 8)
	{
		this->phuCap = 0.05f;
	}
	else if (year >= 8 && year < 10)
	{
		this->phuCap = 0.1f;
	}
	else if (year >= 10)
	{
		this->phuCap = 0.15f;
	}
}
void Employee::setLuong()
{
	double temp = (double)this->luongCoBan * this->heSoLuong;
	this->luong = temp  + this->phuCap*temp;
}
void Employee::setLuongCoBan(int s)
{
	this->luongCoBan = s;
}
void Employee::setHeSoLuong(float s)
{
	this->heSoLuong = s;
}



Employee Employee::nhap()
{
	Employee e;

	string maNhanVien1, hoTen1, maChucVu1, gioiTinh1, diaChi1, hocVan1;
	Date ngaySinh1, ngayVaoLam1;
	int soDienThoai1;
	string soCMND1;
	int luongCoBan1;
	double heSoLuong1;

	int employeeID = 0;
	this->layIDDaDungTuFileH("IDNV_DaDung.txt", employeeID); // lấy id
	++employeeID; // id tăng 1 đơn vị
	this->ghiIDDaDungVaoFileH("IDNV_DaDung.txt", employeeID); // ghi id
	e.setIdNhanVien(employeeID);

	cout << "Nhap maNhanVien = ";
	getline(cin, maNhanVien1);
	if (maNhanVien1 == "") maNhanVien1 = "0";
	cout << "Nhap hoTen = ";
	getline(cin, hoTen1);
	if (hoTen1 == "") hoTen1 = "0";
	cout << "Nhap maChucVu = ";
	getline(cin, maChucVu1);
	if (maChucVu1 == "") maChucVu1 = "0";
	cout << "Nhap gioiTinh = ";
	getline(cin, gioiTinh1);
	if (gioiTinh1 == "") gioiTinh1 = "0";
	cout << "Nhap diaChi = ";
	getline(cin, diaChi1);
	if (diaChi1 == "") diaChi1 = "0";
	cout << "Nhap hocVan = ";
	getline(cin, hocVan1);
	if (hocVan1 == "") hocVan1 = "0";
	//Qua tai toan tu xuat
	cout << "Nhap ngaySinh = ";
	cin >> ngaySinh1;
	cout << "Nhap ngayVaoLam = ";
	cin >> ngayVaoLam1;

	cout << "Nhap soDienThoai = ";
	cin >> soDienThoai1;
	cout << "Nhap soCMND = ";
	cin.ignore();
	getline(cin, soCMND1);
	
	cout << "Nhap luongCoBan = ";
	cin >> luongCoBan1;
	cout << "Nhap heSoLuong = ";
	cin >> heSoLuong1;
	cin.ignore();

	e.setMaNhanVien(maNhanVien1);
	e.setHoTen(hoTen1);
	e.setMaChucVu(maChucVu1);
	e.setGioiTinh(gioiTinh1);
	e.setDiaChi(diaChi1);
	e.setHocVan(hocVan1);
	e.setNgaySinh(ngaySinh1);
	e.setNgayVaoLam(ngayVaoLam1);
	e.setSoDienThoai(soDienThoai1);
	e.setSoCMND(soCMND1);
	//them
	e.setLuongCoBan(luongCoBan1);
	e.setHeSoLuong(heSoLuong1);
	e.setPhuCap();
	e.setLuong();

	return e;
}

void Employee::xuat()
{
	cout << left;

	cout << setw(2);
	cout << "| ";
	cout << setw(14);
	cout << this->maNhanVien;
	cout << setw(2);
	cout << "| ";
	cout << setw(18);
	cout << this->hoTen;
	cout << setw(2);
	cout << "| ";
	cout << setw(12);
	cout << this->maChucVu;
	cout << setw(2);
	cout << "| ";
	cout << setw(12);
	cout << this->gioiTinh;
	cout << setw(2);
	cout << "| ";
	cout << setw(12);
	cout << this->diaChi;
	cout << setw(2);
	cout << "| ";
	cout << setw(10);
	cout << this->hocVan;
	cout << setw(2);
	cout << "| ";

	//Qua tai toan tu xuat
	cout << setw(15);
	cout << this->ngaySinh;
	cout << setw(2);
	cout << "| ";
	cout << setw(15);
	cout << this->ngayVaoLam;
	cout << setw(2);
	cout << "| ";
	cout << setw(15);
	cout << this->soDienThoai;
	cout << setw(2);
	cout << "| ";
	cout << setw(15);
	cout << this->soCMND;
	cout << setw(2);
	cout << "|";
	//them
	cout << setw(10);
	cout << this->luongCoBan;
	cout << setw(2);
	cout << "|";
	cout << setw(10);
	cout << this->heSoLuong;
	cout << setw(2);
	cout << "|";
	cout << setw(4);
	cout << this->phuCap;
	cout << setw(2);
	cout << "|";
	cout << setw(10);
	cout << this->luong;
	cout << setw(2);
	cout << "|";
	//them
	cout << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
