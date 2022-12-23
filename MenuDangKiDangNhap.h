#pragma once
#include <conio.h>
#include <cstdlib>
#include "listEmployee.h"

struct TKXoa
{
    int idNV, idAd;
    string data;
};

bool kiemTraNhap(int kyTu)
{
    if (kyTu == 1 || kyTu == 2)
    {
        return true;
    }
    return false;
}

string inputPassword(string& pass)
{
    pass = "";
    char ch = 0;
    bool bShow = false;
    do
    {
        ch = _getch();
        if ((isalpha(ch) || isalnum(ch))) //(pass.size() < length_max) && )) // Chỉ cho phép nhập kí tự và số
        {
            cout << (bShow ? ch : '*');
            pass.push_back(ch);
        }
        else
        {
            if (0x1B == ch) // 0x1B mã ASCII của phím esc.
            {
                bShow = !bShow;

                cout << string(pass.size(), '\b');

                if (bShow)
                    cout << pass;
                else
                    cout << string(pass.size(), '*');
            }
            if ('\b' == ch && !pass.empty())
            {
                cout << "\b \b";
                pass.resize(pass.size() - 1);
            }
        }

    } while ('\r' != ch);
    cout << endl;
    return pass;
}

int menuLuaChonDangNhapHayDangKi()
{
    int opt;

    cout << "---------------QUAN LY NHAN VIEN-----------------" << endl;
    cout << "Dang ki [1]" << endl;
    cout << "Dang nhap [2]" << endl;
    cout << "Thoat chuong trinh [0]" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << ">>> ";
    cin >> opt;

    if (opt == 0) exit(1);

    // lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
    while (kiemTraNhap(opt) == false)
    {
        // system("cls");
        cout << "Nhap lai!!!" << endl;
        cout << "---------------QUAN LY NHAN VIEN-----------------" << endl;
        cout << "Dang ki [1]" << endl;
        cout << "Dang nhap [2]" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << ">>> ";
        cin >> opt;
    }

    return opt;
}

bool kiemTraKhoangTrang(string name)
{
    int x;
    const char* string_to_char = name.c_str();
    x = (int)strlen(string_to_char);
    for (int i = 0; i < x; i++)
    {
        if (string_to_char[i] == ' ' || (name == ""))
        {
            // system("cls");
            cout << "Ten dang nhap khong duoc chua dau cach." << endl;
            return false; // false -> ten sai
        }
    }
    return true; // true -> ten dung
}

void layIDDaDungTuFile(string tenFile, int& RegisterID)
{
    fstream f;
    f.open(tenFile);
    f >> RegisterID;
    f.close();
}

void ghiIDDaDungVaoFile(string tenFile, int RegisterID)
{
    fstream ghiIDDaDung;
    ghiIDDaDung.open(tenFile);
    ghiIDDaDung << RegisterID;
    ghiIDDaDung.close();
}

bool kTraTaiKhoanNhanVienCoTonTai(TaiKhoan t, string pathFile, int& thisIdAdMin, int& thisIdNhanVien)
{
    ifstream f(pathFile);

    if (!f.is_open())
    {
        cout << "File open faild";
        return false;
    }

    string tk, mk;
    int idNV = 0, idAd = 0;
    char hih;

    while (!f.eof())
    {
        f >> idNV;
        if (idNV == NULL)
            break;
        f >> hih;
        f >> idAd;
        f >> hih;

        getline(f, tk, ';');

        getline(f, mk);



        if (t.getTenDangNhap() == tk && t.getMatKhau() == mk)
        {
            thisIdAdMin = idAd;
            thisIdNhanVien = idNV;
            return true;
        }
    }
    f.close();

    return false;
}

bool kTraTaiKhoanNVDaDuocDangKiChua(string tkNhap, string pathFile)
{
    ifstream f(pathFile);

    if (!f.is_open())
    {
        cout << "File open faild";
        return false;
    }

    string tk, mk;
    int idNV = 0, idAd = 0;
    char hih;

    while (!f.eof())
    {
        f >> idNV;
        if (idNV == NULL)
            break;
        f >> hih;
        f >> idAd;
        f >> hih;

        getline(f, tk, ';');

        getline(f, mk);

        cout << tk << " " << tkNhap;

        if (tkNhap == tk)
        {
            return true;
        }
    }
    f.close();

    return false;
}

bool kTraTaiKhoanAdminCoTonTai(TaiKhoan t, string n, int& thisIdAdMin)
{
    ifstream f(n);
    if (!f.is_open())
    {
        cout << "File open faild";
        return false;
    }

    string tk, mk;
    int id;
    char hih;

    while (!f.eof())
    {
        f >> id;
        if (id == NULL)
            break;
        f >> hih;//lay ki tu xuong dong

        getline(f, tk, ';');

        getline(f, mk);


        if (t.getTenDangNhap() == tk && t.getMatKhau() == mk)
        {
            thisIdAdMin = id;
            return true;
        }

    }
    f.close();

    return false;
}

bool kTraIdAdminCoTonTai(int idAdmin, string n)
{
    ifstream f(n);

    while (!f.eof())
    {
        string line;
        int s;
        f >> s;
        getline(f, line);
        if (idAdmin == s)
        {
            return true;
        }
    }
    return false;
}

bool kTraTaiKhoanAdDaDuocDangKiChua(string tkNhap, string pathFile)
{
    ifstream f(pathFile);

    while (!f.eof())
    {
        string line;
        int s;
        f >> s;
        char hih;
        f >> hih;
        getline(f, line, ';');
        if (tkNhap == line)
        {
            return true;
        }
        getline(f, line);
    }
    return false;
}

//----------------------------------------------------------------------------------------
void ghiTaiKhoanVaoFileAdmin(string tenFile, TaiKhoan tk)
{
    ofstream ghi(tenFile, ios::app);

    if (!ghi.is_open())
    {
        cout << "Khong the mo file!";
        exit(1);
    }

    ghi << tk.getID() << ";" << tk.getTenDangNhap() << ";" << tk.getMatKhau() << endl;
    ghi.close();
}
void ghiTaiKhoanVaoFileNhanVien(string tenFile, TaiKhoan tk, int idAdmin)
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
//------------------------------------------------------------------------------------------

//------------------------------------------------
string pathFile(int s)
{
    string n = to_string(s);

    string path = "DanhSachQL\\" + n + ".txt";

    return path;
}

void themNhanVienVaoFileDS(Employee e, int idAdmin)
{
    string path = pathFile(idAdmin);

    ofstream f(path, ios::app);

    if (!f.is_open())
    {
        cout << "File open faild";
        return;
    }

    f << e.idNhanVien << ';' << e.maNhanVien << ';' << e.hoTen << ';' << e.maChucVu << ';' << e.gioiTinh << ';' << e.diaChi << ';' << e.hocVan << ';' << e.ngaySinh << ';' << e.ngayVaoLam << ';' << e.soDienThoai << ';' << e.soCMND << endl;
    f.close();
}

int menuDangKi()
{
    int opt;
    cout << "Dang ki cho nhan vien [1]" << endl;
    cout << "Dang ki cho quan ly [2]" << endl;
    cout << "------------------------------------" << endl;
    cout << ">>> ";
    cin >> opt;

    while (kiemTraNhap(opt) == false)
    {
        cout << "Nhap lai!!!" << endl;
        cout << "Dang ki cho nhan vien [1]" << endl;
        cout << "Dang ki cho quan ly [2]" << endl;
        cout << "------------------------------------" << endl;
        cout << ">>> ";
        cin >> opt;
    }

    return opt;
}

void dangKiNhanVien()
{
    string tenTK = " ", pass, repass;
    int idAdmin = 0;

    while (!kiemTraKhoangTrang(tenTK))
    {
        cout << "---------------DANG KI NHAN VIEN-----------------" << endl;
        cout << "Dien nhung thong tin ben duoi" << endl;
        cin.ignore();
        do
        {
            cout << "Ten dang nhap(phai khong trung voi ten dang nhap co san)    : ";
            getline(cin, tenTK);
        } while (kTraTaiKhoanNVDaDuocDangKiChua(tenTK, "QLTaiKhoanMatKhauNhanVien.txt"));
        cout << "Mat khau         : ";
        inputPassword(pass);
        cout << "Nhap lai mat khau: ";
        inputPassword(repass);
        cout << "Nhap id cong ty ban: ";
        cin >> idAdmin;
    };

    if (repass == pass)
    {
        
        int employeeID;
        layIDDaDungTuFile("IDNV_DaDung.txt", employeeID); // lấy id

        ++employeeID; // id tăng 1 đơn vị
        TaiKhoan tk(tenTK, pass, employeeID);
        ghiIDDaDungVaoFile("IDNV_DaDung.txt", employeeID); // ghi id
        while (true)
        {
            if (kTraIdAdminCoTonTai(idAdmin, "QLTaiKhoanMatKhauAdmin.txt") == true)
            {
                cout << "DANG KI THANH CONG!" << endl;
                Employee e;
                e.setIdNhanVien(employeeID);
                e.setIdAdmin(idAdmin);
                themNhanVienVaoFileDS(e, idAdmin); // dslkd
                ghiTaiKhoanVaoFileNhanVien("QLTaiKhoanMatKhauNhanVien.txt", tk, idAdmin);
                return;
            }
            else {
                cout << "Id admin k dung vui long nhap lai (phim 0 de thoat chuong trinh): ";
                cin >> idAdmin;
                if (idAdmin == 0)
                {
                    exit(1);
                }
            }
        }
            
    }
    else
    {
        cout << "Mat khau khong trung khop! Vui long dang ki lai!" << endl;
    }
}

void dangKiAdmin()
{
    string tenTK = " ";

    cin.ignore();

    string pass, repass;
    while (!kiemTraKhoangTrang(tenTK))
    {
        cout << "------------DANG KI QUAN LY-----------------" << endl;
        cout << "Dien nhung thong tin ben duoi" << endl;
        do
        {
            cout << "Ten dang nhap(phai khong trung voi ten dang nhap co san)    : ";
            getline(cin, tenTK);
        } while (kTraTaiKhoanAdDaDuocDangKiChua(tenTK, "QLTaiKhoanMatKhauAdMin.txt"));
        cout << "Mat khau     :";
        inputPassword(pass);
        cout << "Nhap lai mat khau:";
        inputPassword(repass);
    };

    if (repass == pass)
    {
        cout << "DANG KI THANH CONG!" << endl;
        int managerID;

        layIDDaDungTuFile("IDQL_DaDung.txt", managerID);
        managerID = managerID + 1;
        TaiKhoan tk(tenTK, pass, managerID);
        ghiTaiKhoanVaoFileAdmin("QLTaiKhoanMatKhauAdmin.txt", tk);
        ghiIDDaDungVaoFile("IDQL_DaDung.txt", managerID);

        string path = pathFile(managerID);

        ofstream f(path); //tao file id.txt
        f.close();
    }
    else
    {
        cout << "Mat khau khong trung khop! Vui long dang ki lai!" << endl;
    }
}

int menuDangNhap()
{
    int opt;
    cout << "Dang nhap cho nhan vien [1]" << endl;
    cout << "Dang nhap cho quan ly [2]" << endl;
    cout << "------------------------------------" << endl;
    cout << ">>> ";
    cin >> opt;
    /// lệnh này để phòng trường hợp người nhập nhập vào op là kí tự
    while (kiemTraNhap(opt) == false)
    {
        // system("cls");
        cout << "Nhap lai!!!" << endl;
        cout << "Dang nhap cho nhan vien [1]" << endl;
        cout << "Dang nhap cho quan ly [2]" << endl;
        cout << "------------------------------------" << endl;
        cout << ">>> ";
        cin >> opt;
    }

    return opt;
}

bool dangNhapAdmin(int& thisIdAdMin)
{
    string name1, pass1;

    cout << "-------------DANG NHAP QUAN LY-----------------" << endl;
    cin.ignore();
    cout << "Ten dang nhap  :";
    getline(cin, name1);
    cout << "Mat khau       :";
    inputPassword(pass1);
    cout << endl;

    TaiKhoan tkNhap(name1, pass1, 0);
    // lấy dữ liệu để đăng nhập

    if (kTraTaiKhoanAdminCoTonTai(tkNhap, "QLTaiKhoanMatKhauAdmin.txt", thisIdAdMin) == true)
    {
        return true;
    }
    return false;
}

bool dangNhapNhanVien(int& thisIdAdMin, int& thisIdNhanVien)
{
    string name1, pass1;

    cout << "-------------DANG NHAP NHAN VIEN-----------------" << endl;
    cin.ignore();
    cout << "Ten dang nhap  :";
    getline(cin, name1);
    cout << "Mat khau       :";
    inputPassword(pass1);
    cout << endl;

    TaiKhoan tkNhap(name1, pass1, 0);

    if (kTraTaiKhoanNhanVienCoTonTai(tkNhap, "QLTaiKhoanMatKhauNhanVien.txt", thisIdAdMin, thisIdNhanVien) == true)
    {

        return true;
    }
    return false;
}

void setIdAdminTrongTKNV(int idNV, int idAd)
{
    TKXoa a[1000];

    ifstream f("QLTaiKhoanMatKhauNhanVien.txt");
    
    int i = 0;
    char hih;
    while (!f.eof())
    {
        f >> a[i].idNV;
        f >> hih;
        f >> a[i].idAd;
        getline(f, a[i].data);
        if (a[i].data == "") break;
        i++;
    }

    /*for (int j = 0; j < i; j++)
    {
        cout<< a[j].idNV << ';' << a[j].idAd << a[j].data << endl;
    }*/

    for (int j = 0; j < i; j++)
    {
        if (a[j].idNV == idNV)
        {
            a[j].idAd = idAd;
            break;
        }
    }
    f.close();

    fstream ghi("QLTaiKhoanMatKhauNhanVien.txt");
    for (int j = 0; j < i; j++)
    {
        ghi << a[j].idNV << ';' << a[j].idAd << a[j].data << endl;
    }
    ghi.close();
}