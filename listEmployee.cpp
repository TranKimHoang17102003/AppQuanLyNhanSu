#include "listEmployee.h"


listEmployee::listEmployee()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

int listEmployee::getSize()
{
	return size;
}

void listEmployee::nhapDanhSachNhanVien(int idAdmin)
{
	cout << "Nhap so nhan vien ban muon them:";
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		Employee e = this->data.nhap();
		string temp=e.getMaNhanVien();
		while (kiemTraTrungID(temp))
		{
			cout << "Nhap lai ma nhan vien(bi trung ma!): ";
			
			getline(cin, temp);
		}
		e.setMaNhanVien(temp);

		e.setIdAdmin(idAdmin);
		NodeEmployee nE = new nodeEmployee(e);
		this->themPhanTu(nE);

		string tenTK = to_string(e.getIdNhanVien());
		string pass = to_string(e.getIdAdmin());
		TaiKhoan tk(tenTK, pass, e.getIdNhanVien());

		this->ghiTaiKhoanVaoFileNhanVienH("QLTaiKhoanMatKhauNhanVien.txt", tk, e.getIdAdmin());
	}
}

void listEmployee::ghiFile(string tenFile)
{
	fstream f;
	f.open(tenFile, ios::out);

	if (!f.is_open()) {
		cout << "File open faild";
		exit(1);
	}

	NodeEmployee p = head;
	while (p != NULL)
	{
		//idNhanVien, maNhanVien, hoTen, maChucVu, gioiTinh, diaChi, hocVan, ngaySinh, ngayVaoLam, sdt, soCMND.
		f << p->data.idNhanVien << ';' << p->data.maNhanVien << ';' << p->data.hoTen << ';' << p->data.maChucVu << ';' << p->data.gioiTinh << ';' << p->data.diaChi << ';' << p->data.hocVan << ';' << p->data.ngaySinh << ';' << p->data.ngayVaoLam << ';' << p->data.soDienThoai << ';' << p->data.soCMND << ';' << p->data.luongCoBan << ';' << p->data.heSoLuong << ';' << p->data.phuCap << ';' << p->data.luong << '\n';
		p = p->next;
	}
	f.close();
}

//doc du lieu tu file qua dslk
void listEmployee::layDanhSachTuFile(string tenFile)
{
	ifstream f(tenFile);

	if (!f.is_open())
	{
		cout << "Faild open file";
		exit(1);
	}

	while (!f.eof())
	{
		int idNV;
		char hih;
		string line;
		Employee e;

		f >> idNV; //idNhanVien
		f >> hih; //lay day ;
		e.setIdNhanVien(idNV);

		getline(f, line, ';');
		if (line == "") break;
		e.setMaNhanVien(line);
		getline(f, line, ';');
		e.setHoTen(line);
		getline(f, line, ';');
		e.setMaChucVu(line);
		getline(f, line, ';');
		e.setGioiTinh(line);
		getline(f, line, ';');
		e.setDiaChi(line);
		getline(f, line, ';');
		e.setHocVan(line);

		char s;
		int d1, m1, y1;
		f >> d1;
		f >> s;
		f >> m1;
		f >> s;
		f >> y1;
		Date day1(d1, m1, y1);
		e.setNgaySinh(day1);

		f >> s;

		int d, m, y;
		f >> d;
		f >> s;
		f >> m;
		f >> s;
		f >> y;
		Date day(d, m, y);
		e.setNgayVaoLam(day);

		int sdt;
		string cmnd;
		f >> s;
		f >> sdt;
		e.setSoDienThoai(sdt);
		f >> s;
		//them
		getline(f, line, ';');
		e.setSoCMND(line);
		float luongCoBan1, heSoLuong1, phuCap1, luong1;
		f >> luongCoBan1;
		f >> s;
		f >> heSoLuong1;
		f >> s;
		f >> phuCap1;
		f >> s;
		f >> luong1;
		f >> s;
		e.setLuongCoBan(luongCoBan1);
		e.setHeSoLuong(heSoLuong1);
		e.setPhuCap();
		e.setLuong();

		NodeEmployee nE = new nodeEmployee(e);

		this->themPhanTu(nE);
	}

	f.close();
}

void listEmployee::xuatTrenXuong()
{
	NodeEmployee p = head;
	for (int i = 0; i < size; i++)
	{
		p->data.xuat();
		p = p->next;
	}
}

void listEmployee::themPhanTu(NodeEmployee x)
{
	if (this->head == NULL)
	{
		this->head = x;
		this->tail = x;
		++size;
	}
	else
	{
		x->prev = this->tail;
		this->tail->next = x;
		this->tail = x;
		++size;
	}
}

void listEmployee::xoaDau()
{
	if (head != NULL) {
		NodeEmployee p = head;
		if (p->next == NULL) {
			head = NULL;
			head = NULL;
			--size;
		}
		else {
			head = p->next;
			p->next->prev = NULL;
			p->next = NULL;
			--size;
		}
		delete(p);
	}
}
void listEmployee::xoaCuoi()
{
	if (tail != NULL) {
		NodeEmployee p = tail;
		if (p->prev == NULL) {
			head = NULL;
			tail = NULL;
			--size;
		}
		else {
			tail = p->prev;
			p->prev->next = NULL;
			p->prev = NULL;
			--size;
		}
		delete(p);
	}
}

// vidu: ds={2,4,2,6} xoa vi tri pos=2 -> ds={2,2,6}
void listEmployee::xoaNhanVienIndex(int pos, int& idNVXoa)
{
	if (this == NULL)
	{
		cout << "Danh sach rong.";
		return;
	}

	if (pos < 1 || pos > size) return;

	if (pos == 1)
	{
		idNVXoa = head->data.getIdNhanVien();
		xoaDau();
		return;
	}
	//neu p->next == NULL thuc hien xoa cuoi
	if (pos == size)
	{
		idNVXoa = tail->data.getIdNhanVien();
		xoaCuoi();
		return;
	}
	--size;
	//tim kiem theo du lieu x va gan vao node p
	NodeEmployee p;
	//gan p bang phan tu dau danh sach
	p = head;
	//su dung vong lap
	int dem = 1;
	while (dem < pos)
	{
		p = p->next;
		dem += 1;
	}

	idNVXoa = p->data.getIdNhanVien();

	//thay doi lai lien ket cua phan tu co khoa K can xoa
	p->prev->next = p->next;
	p->next->prev = p->prev;
	//gan con tro prev va next cua phan tu co khoa K can xoa ve null
	p->prev = NULL;
	p->next = NULL;
	//xoa node p co phan tu la khoa k
	delete p;
}

bool listEmployee::kiemTraTrungID(string ID) {

	NodeEmployee p = this->head;

	for (int i = 0; i < this->size; i++)
	{
		string temp = p->data.getMaNhanVien();
		if (temp.compare(ID) == 0)
		{
			cout << "Trung ID" << endl;
			return true;
			break;
		}
		p = p->next;
	}

	return false;
}

void listEmployee::suaNhanVienIndex(int pos)
{
	if (this == NULL)
	{
		cout << "Danh sach rong.";
		return;
	}

	if (pos < 1 || pos > size)
	{
		cout << "Pos khong hop le.";
		return;
	}

	NodeEmployee p = head;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}

	int lc = -1;
	while (lc != 0)
	{
		cout << "Ban muon sua thong tin gi: " << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		p->data.xuat();
		cout << "1. Sua ma nhan vien." << endl;
		cout << "2. Sua ho ten" << endl;
		cout << "3. Sua ma nhan vien" << endl;
		cout << "4. Sua gioi tinh" << endl;
		cout << "5. Sua dia chi" << endl;
		cout << "6. Sua hoc van" << endl;
		cout << "7. Sua ngay sinh" << endl;
		cout << "8. Sua ngay vao lam" << endl;
		cout << "9. Sau sdt" << endl;
		cout << "10. Sua so CMND" << endl;
		cout << "0. Thoat ra Menu chinh" << endl;
		cout << "Nhap lua chon cua ban: ";

		cin >> lc;

		if (lc == 1)
		{
			string maNhanVien1;
			cout << "Nhap maNhanVien = ";
			cin.ignore();
			getline(cin, maNhanVien1);
			if (kiemTraTrungID(maNhanVien1))
			{

			}
			else
			{
				p->data.setMaNhanVien(maNhanVien1);
			}
		}
		else if (lc == 2)
		{
			string hoTen1;
			cout << "Nhap hoTen = ";
			cin.ignore();
			getline(cin, hoTen1);
			p->data.setHoTen(hoTen1);
		}
		else if (lc == 3)
		{
			string maChucVu1;
			cout << "Nhap maChucVu = ";
			cin >> maChucVu1;
			p->data.setMaChucVu(maChucVu1);
		}
		else if (lc == 4)
		{
			string gioiTinh1;
			cout << "Nhap gioiTinh = ";
			cin.ignore();
			getline(cin, gioiTinh1);
			p->data.setGioiTinh(gioiTinh1);
		}
		else if (lc == 5)
		{
			string diaChi1;
			cout << "Nhap diaChi = ";
			cin.ignore();
			getline(cin, diaChi1);
			p->data.setDiaChi(diaChi1);
		}
		else if (lc == 6)
		{
			string hocVan1;
			cout << "Nhap hocVan = ";
			cin.ignore();
			getline(cin, hocVan1);
			p->data.setHocVan(hocVan1);
		}
		else if (lc == 7)
		{
			Date ngaySinh1;
			cout << "Nhap ngaySinh = ";
			cin >> ngaySinh1;
			p->data.setNgaySinh(ngaySinh1);
		}
		else if (lc == 8)
		{
			Date ngayVaoLam1;
			cout << "Nhap ngayVaoLam = ";
			cin >> ngayVaoLam1;
			p->data.setNgayVaoLam(ngayVaoLam1);
		}
		else if (lc == 9)
		{
			int soDienThoai1;
			cout << "Nhap soDienThoai = ";
			cin >> soDienThoai1;
			p->data.setSoDienThoai(soDienThoai1);
		}
		else if (lc == 10)
		{
			string soCMND1;
			cout << "Nhap soCMND = ";
			cin >> soCMND1;
			p->data.setSoCMND(soCMND1);
		}
	}
}

void listEmployee::sapXepTheoTen()
{
	if (this->head == NULL || this->head->next == NULL) return;

	NodeEmployee p, q;
	p = this->head;
	while (p != tail) {
		q = p->next;
		while (q != NULL) {
			if (tachTenNguoi(p->data.getHoTen()) > tachTenNguoi(q->data.getHoTen())) {
				swap(p->data, q->data);
			}
			q = q->next;
		}
		p = p->next;
	}
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	this->xuatTrenXuong();
}

void listEmployee::sapXepTheoMaNhanVien()
{
	if (this->head == NULL || this->head->next == NULL) return;

	NodeEmployee p, q;
	p = this->head;
	while (p != tail) {
		q = p->next;
		while (q != NULL) {
			if (p->data.getMaNhanVien() > q->data.getMaNhanVien()) {
				swap(p->data, q->data);
			}
			q = q->next;
		}
		p = p->next;
	}
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	this->xuatTrenXuong();
}

string listEmployee::tachTenNguoi(string ht)
{
	string ten;

	int i = ht.find_last_of(' ');
	int n = ht.length();

	ten = ht.substr(i+1, n - i);

	return ten;
}

void listEmployee::timPhanTuTheoTen(string s)
{
	if (this->head == NULL) return;

	NodeEmployee p = this->head;

	for (int i = 0; i < this->size; i++)
	{
		string temp = tachTenNguoi(p->data.getHoTen());
		if (temp == s)
		{
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			p->data.xuat();
			break;
			return;
		}
		p = p->next;
	}

	cout << "Khong tim thay nhan vien co ten nay." << endl;
}

void listEmployee::timPhanTuTheoIdNhanVien(int idNhanVien)
{
	NodeEmployee p = this->head;

	for (int i = 0; i < size; i++)
	{
		if (p->data.getIdNhanVien() == idNhanVien)
		{
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			p->data.xuat();
			return;
		}
		p = p->next;
	}
	cout << "Khong tim thay nhan vien co ID nay." << endl;
}

void listEmployee::suaNhanVienTheoId(int idNhanVien)
{
	NodeEmployee p = head;

	for (int i = 0; i < size; i++)
	{
		if (p->data.getIdNhanVien() == idNhanVien)
		{
			this->suaNhanVienIndex(i + 1);
			return;
		}
		p = p->next;
	}
}