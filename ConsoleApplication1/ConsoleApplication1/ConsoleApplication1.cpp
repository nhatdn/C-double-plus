/*
3(4đ). ------------------ QLDS Sinh Viên ------------
Sinh viên có các thông tin:
_ Họ Tên
_ Phái
_ Ngày tháng năm sinh
_ Mã sinh viên (phân biệt)
_ bảng điểm (1 Sinh viên sẽ có 1 bảng điểm gồm 3 môn: Mac Lenin, Đai số, C++).

Quản lý danh sách sinh viên. Thực hiện các chức năng sau:

0. Đọc ghi file sv(Bắt buộc).
1(1đ). Nhập, xuất sinh viên trong danh sách.(Sử dụng nạp chồng toán tử + Không nhập điểm)
2(1đ). Xóa sinh viên có mã sinh viên nhập từ bàn phím.
3(0,5đ). Sắp xếp danh sách sinh viên tăng dần theo tên (nếu trùng thì theo họ).
4(1đ). Nhập điểm 3 môn cho sinh viên có mã sv nhập từ bàn phím.
5(0,5đ). Xuất ds sinh viên tăng dần theo ngày tháng năm sinh.

Lưu ý: Chuẩn hóa dữ liệu gồm: họ tên, ngày tháng năm sinh, mã sinh viên(phân biệt).

monHoc* x = new monHoc(3, "Van");
	cout << x->getTenMon() << endl;
	for (int i = 0; i < 3; i++) {
		x->nhapThemDiem();
	}
	x->xuatDanhSachDiem();
	for (int i = 0; i < 3; i++) {
		x->nhapThemDiem();
	}
	x->xuatDanhSachDiem();
*/
#include <iostream>
#include "QuanLiSinhVien.h"
using namespace std;
int main() {
	QuanLiSinhVien* qlsv = new QuanLiSinhVien();
	qlsv->xuatSinhVien(); // xuất sinh viên
	qlsv->nhapDiemSinhVien(); // nhập điểm cho sinh viên
	qlsv->xuatDiemSinhVien(); // xuất điểm cho sinh viên
	//qlsv->xoaSinhVien(); // xóa sinh viên
	// sắp xếp sinh viên theo họ tên
	// sắp xếp sinh viên theo ngày tháng năm sinh
	system("pause");
	return 0;
}