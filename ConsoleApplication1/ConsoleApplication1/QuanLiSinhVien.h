#pragma once
#include <string>
#include <fstream>
#include "monHoc.h"
#include "sinhVien.h"
class QuanLiSinhVien
{
	ifstream input;
	int slsv; // so luong sinh vien
	sinhVien* sv;
public:
	QuanLiSinhVien() {
		input.open("QLSV.txt");
		string name;
		string gender;
		string birthday;
		string id;
		getline(input, id);
		getline(input, name);
		getline(input, gender);
		getline(input, birthday);
		sv = new sinhVien(name, gender, birthday, id);
		sinhVien* temp = sv;
		while (!input.eof()) {
			getline(input, id);
			getline(input, name);
			getline(input, gender);
			getline(input, birthday);
			temp->pointer = new sinhVien(name, gender, birthday, id);
			temp = temp->pointer;
		}
		temp->pointer = NULL;
	}
	~QuanLiSinhVien() {
		input.close();
	}
	void xuatSinhVien() {
		for (sinhVien * temp = sv; temp != NULL; temp = temp->pointer) {
			temp->xuatThongTin();
		}
	}
	void xoaSinhVien() {
		cout << "Nhap id can xoa: " << endl;
		string id;
		getline(cin, id);
		sinhVien * del = NULL;
		sinhVien * beforePointer = NULL;
		for (sinhVien* temp = sv; temp != NULL; temp = temp->pointer) {
			if (temp->getId() == id) {
				del = temp;
				break;
			}
			beforePointer = temp;
		}
		if (del == NULL) {
			cout << "ID vua nhap khong ton tai" << endl;
		}
		else {
			if (beforePointer == NULL) {
				sv = sv->pointer;
			} else {
				beforePointer->pointer = del->pointer;
			}
		}
	}
	sinhVien * General() {
		cout << "Nhap id sinh vien: " << endl;
		string id;
		getline(cin, id);
		for (sinhVien* temp = sv; temp != NULL; temp = temp->pointer) {
			if (temp->getId() == id) {
				return temp;
				break;
			}
		}
		return NULL;
	}
	void nhapDiemSinhVien() {
		sinhVien* temp = General();
		if (temp == NULL) {
			cout << "ID sinh vien vua nhap khong ton tai" << endl;
		}
		else {
			temp->nhapDiem();
		}
	}
	void xuatDiemSinhVien() {
		sinhVien* temp = General();
		if (temp == NULL) {
			cout << "ID sinh vien vua nhap khong ton tai" << endl;
		}
		else {
			temp->xuatDiem();
		}
	}
};