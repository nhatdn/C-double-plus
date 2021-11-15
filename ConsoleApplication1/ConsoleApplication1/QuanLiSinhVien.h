#pragma once
#include <string>
#include <fstream>
#include "monHoc.h"
#include "sinhVien.h"
#include <vector>
#include <sstream>
class QuanLiSinhVien
{
private:
	ifstream input;
	int slsv; // so luong sinh vien
	sinhVien* sv;
	sinhVien* endPoint;
	sinhVien* sinhVienTonTai() {
		cout << "Nhap id sinh vien: " << endl;
		string id;
		getline(cin, id);
		for (sinhVien* temp = sv; temp != NULL; temp = temp->pointer) {
			if (temp->getId() == id) {
				return temp;
			}
		}
		return NULL;
	}
	bool soSanhNgaySinh(string a, string b) {
		string splitNgaySinhA[3], splitNgaySinhB[3];
		for (int i = 0; i < 3; i++) {
			splitNgaySinhA[i] = a.substr(0, a.find("/"));
			a.erase(0, a.find("/") + 1);
			splitNgaySinhB[i] = b.substr(0, b.find("/"));
			b.erase(0, b.find("/") + 1);
		}
		if (splitNgaySinhB[2] > splitNgaySinhA[2]) {
			return false;
		}
		else if (splitNgaySinhB[2] == splitNgaySinhA[2]) {
			if (splitNgaySinhB[1] > splitNgaySinhA[1]) {
				return false;
			}
			else if (splitNgaySinhB[1] == splitNgaySinhA[1]) {
				if (splitNgaySinhB[0] > splitNgaySinhA[0]) {
					return false;
				}
				else {
					return true;
				}
			}
			else {
				return true;
			}
		}
		else {
			return true;
		}
	}
	bool soSanhTen(string a, string b) {
		int lenA = a.length();
		int lenB = b.length();
		while (lenA > 0 && a[--lenA] != ' ');
		while (lenB > 0 && b[--lenB] != ' ');
		string nameA = lenA == 0 ? a.substr(lenA, a.length()) : a.substr(lenA + 1, a.length());
		string nameB = lenB == 0 ? b.substr(lenB, b.length()) : b.substr(lenB + 1, b.length());
		if (nameA.compare(nameB) > 0) {
			return true;
		}
		else if (nameA.compare(nameB) == 0) {

			while (lenA < a.length() && a[++lenA] != ' ');
			while (lenB < b.length() && b[++lenB] != ' ');
			nameA = lenA == 0 ? a.substr(0, lenA) : a.substr(0, lenA + 1);
			nameB = lenB == 0 ? b.substr(0, lenB) : b.substr(0, lenB + 1);
			return nameA.compare(nameB) > 0;
		}
		return false;
	}

	void HoanViSinhVien(sinhVien* beforeA, sinhVien* a, sinhVien* beforeB, sinhVien* b) {
		sinhVien* temp;
		if (beforeA == NULL) { // A dau, B cuoi
			if (b->pointer == NULL) { // đầu đổi cho cuối
				b->pointer = a->pointer;
				a->pointer = NULL;
				beforeB->pointer = a;
			}
			else { // đầu đổi cho giữa // A dau, B giua
				temp = b->pointer;
				beforeB->pointer = a;
				b->pointer = a->pointer;
				a->pointer = temp;
			}
			this->sv = b;
		}
		else if (b->pointer == NULL) { // giữa đổi cho cuối // A giua, B cuoi
			if (a == beforeB) { // a cách b 1 điểm
				temp = beforeA->pointer;
				beforeA->pointer = b;
				b->pointer = a;
				a->pointer = NULL;
			}
			else if (a->pointer->pointer == NULL) { // gần cuối A và cuối B a=beforeA
				temp = b->pointer;
				b->pointer = a;
				beforeA->pointer = b;
				a->pointer = temp;
			}
			else { // a cách b nhiều hơn 1 điểm
				beforeA->pointer = b;
				b->pointer = a->pointer;
				beforeB->pointer = a;
				a->pointer = NULL;
			}

		}
		else { // giữa đổi cho giữa 
			if (a == beforeB) { // giua giua lien ke
				temp = b->pointer;
				b->pointer = a;
				beforeA->pointer = b;
				a->pointer = temp;
			}
			else { // giua giua xa nhau
				temp = a->pointer;
				a->pointer = b->pointer;
				b->pointer = temp;
				beforeB->pointer = a;
				beforeA->pointer = b;
			}
		}
	}
public:
	void ThemSinhVien() {
		string name;
		string gender;
		string birthday;
		string id;
		cout << "Nhap id cho sinh vien moi: ";
		getline(cin, id);
		bool checking = false;
		for (sinhVien* temp = sv; temp != NULL; temp = temp->pointer) {
			if (temp->getId() == id) {
				cout << "ID nay da ton tai" << endl;
				checking = true;
				break;
			}
		}
		if (checking) {
			return;
		}
		cout << "Nhap ten cho sinh vien moi: ";
		getline(cin, name);
		cout << "Nhap ngay sinh cho sinh vien moi: ";
		getline(cin, birthday);
		cout << "Nhap gioi tinh cho sinh vien moi: ";
		getline(cin, gender);
		endPoint->pointer = new sinhVien(name, gender, birthday, id);
		endPoint = endPoint->pointer;
	}
	QuanLiSinhVien(string filename) {
		input.open(filename);
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
		endPoint = temp;
		temp->pointer = NULL;
	}
	~QuanLiSinhVien() {
		delete sv;
		input.close();
	}
	void xuatSinhVien() {
		for (sinhVien * temp = sv; temp != NULL; temp = temp->pointer) {
			temp->xuatThongTin();
		}
	}
	void xoaSinhVien() {
		cout << "Nhap id can xoa: ";
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
			cout << "Xoa thanh cong" << endl;
		}
	}
	
	void nhapDiemSinhVien() {
		sinhVien* temp = sinhVienTonTai();
		if (temp == NULL) {
			cout << "ID sinh vien vua nhap khong ton tai" << endl;
		}
		else {
			temp->nhapDiem();
		}
	}
	void xuatDiemSinhVien() {
		sinhVien* temp = sinhVienTonTai();
		if (temp == NULL) {
			cout << "ID sinh vien vua nhap khong ton tai" << endl;
		}
		else {
			temp->xuatDiem();
		}
	}
	
	void sapXepTheoTen() {
		sinhVien * beforeA = NULL, * beforeB; 
		for (sinhVien* temp = sv; temp != NULL; temp = temp->pointer) {
			beforeB = temp;
			for (sinhVien* tam = temp->pointer; tam != NULL; tam = tam->pointer) {
				if (soSanhTen(temp->getTen(), tam->getTen()) && tam != temp) {
					HoanViSinhVien(beforeA, temp, beforeB, tam);
					temp = beforeA == NULL ? sv : beforeA;
				}
				beforeB = tam;
			}
			beforeA = temp;
		}
	}
	void sapXepNgaySinh() {
		sinhVien* beforeA = NULL, * beforeB;
		for (sinhVien* temp = sv; temp != NULL; temp = temp->pointer) {
			beforeB = temp;
			for (sinhVien* tam = temp->pointer; tam != NULL; tam = tam->pointer) {
				if (soSanhNgaySinh(temp->getNgaySinh(), tam->getNgaySinh()) && tam != temp) {
					HoanViSinhVien(beforeA, temp, beforeB, tam);
					temp = beforeA == NULL ? sv : beforeA;
				}
				beforeB = tam;
			}
			beforeA = temp;
		}
	}
	int Option() {
		cout << "1. Xem danh sach sinh vien sap xep theo ten." << endl;
		cout << "2. Xem danh sach sinh vien sap xep theo ngay sinh." << endl;
		cout << "3. Xoa 1 sinh vien bang ID." << endl;
		cout << "4. Xem diem sinh vien." << endl;
		cout << "5. Nhap diem sinh vien." << endl;
		cout << "6. Them sinh vien." << endl;
		cout << "7. Thoat" << endl;
		cout << "Nhap lua chon: ";
		int n;
		cin >> n;
		while (getchar() != '\n');
		return n;
	}
	void Menu() {
		while (true)
		{
			switch (Option())
			{
				case 1: {
					sapXepTheoTen();
					xuatSinhVien();
					break;
				}
				case 2: {
					sapXepNgaySinh();
					xuatSinhVien();
					break;
				}
				case 3: {
					xoaSinhVien();
					break;
				}
				case 4: {
					xuatDiemSinhVien();
					break;
				}
				case 5: {
					nhapDiemSinhVien();
					break;
				}
				case 6: {
					
					ThemSinhVien();
					break;
				}
				default: {
					exit(0);
					break;
				}	
			}
			system("pause");
			system("cls");
		}
	}
};