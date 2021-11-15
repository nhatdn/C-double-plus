#pragma once
#include <string>
#include <iostream>
using namespace std;
/*
Sinh viên có các thông tin:
_ Họ Tên
_ Phái
_ Ngày tháng năm sinh
_ Mã sinh viên (phân biệt)
_ bảng điểm (1 Sinh viên sẽ có 1 bảng điểm gồm 3 môn: Mac Lenin, Đai số, C++).
*/
class monHoc
{
	private:
		string _tenMon;
		int _danhSachDiem;
		int * _bangDiem;
		string* _tenDiem;
		int hienTai = 0;
	public:
		monHoc(int danhSachDiem, string tenMon) {
			_tenMon = tenMon;
			_danhSachDiem = danhSachDiem;
			_bangDiem = new int[_danhSachDiem];
			_tenDiem = new string[_danhSachDiem];
			hienTai = 0;
		};
		~monHoc() {
			delete _bangDiem;
			delete _tenDiem;
		}
		string getTenMon() {
			return _tenMon;
		}
		void setTenMon(string tenMon) {
			_tenMon = tenMon;
		}
		int * getBangDiem() {
			return _bangDiem;
		}
		string* getTenDiem() {
			return _tenDiem;
		}
		void nhapThemDiem() {
			if (hienTai >= _danhSachDiem) {
				int* temp = new int[hienTai+1];
				string* tempStr = new string[hienTai+1];
				for (int i = 0; i < _danhSachDiem; i++) {
					temp[i] = _bangDiem[i];
					tempStr[i] = _tenDiem[i];
				}
				_bangDiem = temp;
				_tenDiem = tempStr;
				_danhSachDiem = hienTai + 1;
			}
			cout << "Nhap ten cot diem: ";
			getline(cin, _tenDiem[hienTai]);
			cout << "Nhap diem: ";
			cin >> _bangDiem[hienTai];
			while (getchar() != '\n');
			this->hienTai++;
		}
		void xuatDanhSachDiem() {
			if (hienTai == 0) {
				cout << "Chua co diem, vui long nhap truoc khi xem" << endl;
				return;
			}
			for (int i = 0; i < hienTai; i++) {
				cout << _tenDiem[i] << ": " << _bangDiem[i] << endl;
			}
		}
};