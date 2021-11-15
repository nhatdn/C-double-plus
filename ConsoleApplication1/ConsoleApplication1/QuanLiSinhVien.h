#pragma once
#include <string>
#include <fstream>
#include "monHoc.h"
#include "sinhVien.h"
#include <vector>
#include <sstream>
class QuanLiSinhVien
{

public:
	ifstream input;
	int slsv; // so luong sinh vien
	sinhVien* sv;

	vector<string> split(const string& s, char delim) {
		vector<string> result;
		stringstream ss(s);
		string item;

		while (getline(ss, item, delim)) {
			result.push_back(item);
		}

		return result;
	}
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
		else if(splitNgaySinhB[2] == splitNgaySinhA[2]){
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
		
	}
	void HoanViSinhVien(sinhVien * beforeA, sinhVien* a, sinhVien* beforeB,sinhVien *b) {
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
			else if(a->pointer->pointer == NULL){ // gần cuối A và cuối B a=beforeA
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
	bool compareFunction(string s1, string s2) // name
	{
		// comparing both using inbuilt function
		int x = s1.compare(s2);
		if (x != 0) {
			cout << s1 << " is not equal to "
				<< s2 << endl;
			if (x > 0)
				cout << s1 << " is greater than " << s2 << endl;
			else
				cout << s2 << " is greater than " << s1 << endl;
		}
		else {
			cout << s1 << " is equal to " << s2 << endl;
		}
		return true;
	}
	void sapXepTheoNgaySinh() {
		sinhVien * beforeA = NULL, * beforeB; 
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
};