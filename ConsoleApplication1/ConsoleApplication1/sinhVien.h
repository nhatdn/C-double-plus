#pragma once
#include <string>
#include "monHoc.h"
using namespace std;
class sinhVien
{
private:
		string _name;
		string _gender;
		string _birthday;
		string _id;
		monHoc * _toan;
		monHoc * _mac;
		monHoc * _cPlus;
public:
		sinhVien* pointer;
		sinhVien(string name, string gender, string birthday, string id) {
			pointer = NULL;
			_name = name;
			_gender = gender;
			_birthday = birthday;
			_id = id;
			_toan = new monHoc(1, "Toan");
			_mac = new monHoc(1, "Mac Lenin");
			_cPlus = new monHoc(1, "C++");
		}
		~sinhVien() {
			delete _toan;
			delete _mac;
			delete _cPlus;
		}
		string getId() {
			return _id;
		}
		void xuatThongTin() {
			cout << "Id: " << _id << endl;
			cout << "Gioi tinh: " << _gender << endl;
			cout << "Ngay Sinh: " << _birthday << endl;
			cout << "Ten: " << _name << endl;
		}
		void xuatDiem() {
			cout << "1. Xuat diem mon toan" << endl;
			cout << "2. Xuat diem mon Mac" << endl;
			cout << "3. Xuat diem mon CPlus" << endl;
			cout << "Vui long chon: ";
			int i;
			cin >> i;
			while (getchar() != '\n');
			if (i < 0 || i > 4) {
				cout << "Lua chon khong phu hop" << endl;
			}
			else {
				switch (i)
				{
					case 1: {
						_toan->xuatDanhSachDiem();
							break;
					}
					case 2: {
						_mac->xuatDanhSachDiem();
							break;
					}
					case 3: {
						_cPlus->xuatDanhSachDiem();
							break;
					}
				}
			}
		}
		void nhapDiem() {
			cout << "1. Nhap diem mon toan" << endl;
			cout << "2. Nhap diem mon Mac" << endl;
			cout << "3. Nhap diem mon CPlus" << endl;
			cout << "Vui long chon: ";
			int i;
			cin >> i;
			while (getchar() != '\n');
			if (i < 1 || i > 4) {
				cout << "Lua chon khong phu hop" << endl;
			}
			else {
				switch (i)
				{
					case 1: {
						_toan->nhapThemDiem();
						break;
					}
					case 2: {
						_mac->nhapThemDiem();
						break;
					}
					case 3: {
						_cPlus->nhapThemDiem();
						break;
					}
				}
			}
		}
		string getNgaySinh() {
			return _birthday;
		}
		string getTen() {
			return _name;
		}
		/*friend istream& operator>>(istream& is, sinhVien& obj) // error when it runs code
		{
			cout << "Nhap id: " << endl;
			getline(is, obj._id);
			cout << "Nhap ten: " << endl;
			getline(is, obj._name);
			cout << "Nhap gioi tinh: " << endl;
			getline(is, obj._gender);
			cout << "Nhap ngay sinh: " << endl;
			getline(is, obj._birthday);
			return is;
		}
		friend ostream& operator<<(ostream& os, sinhVien obj)
		{
			os << "Id: " << obj._id << endl;
			os << "Gioi tinh: " << obj._gender << endl;
			os << "Ngay Sinh: " << obj._birthday << endl;
			os << "Ten: " << obj._name << endl;
			return os;
		}*/
};