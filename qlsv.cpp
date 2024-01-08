#include "iostream"
#include "sstream"
#include "fstream"
#include "vector"
using namespace std;
int s;
struct SinhVien {
	int maSV;
	string hoTen;
	int namSinh;
	string diaChi;
	int gioiTinh;
	double diemTB;
	SinhVien() {

	}
	SinhVien(int ma, string ht, int nam, string dc, int gt, double dtb) {
		maSV = ma;
		hoTen = ht;
		namSinh = nam;
		diaChi = dc;
		gioiTinh = gt;
		diemTB = dtb;
	}
};
struct Node {
	SinhVien sv;
	Node* next;
};
Node* node;
void init() {
	node = NULL;
}
vector<SinhVien> v1, v2, v3, v4, v5;
SinhVien makeSinhVien();
Node* makeNode(SinhVien sv);
void insertLast(SinhVien sv);
void inputFromFile();
void outputSinhVien(SinhVien sv);
bool insertIndex(int k, SinhVien sv);
bool deleteSinhVien();
void sort();
void writeToFile(vector<SinhVien> v);
void locTheoDC(string s);
void locTheoNS(int nam);
void locTheoTen(string s);
void locTheoGt();
void locTheoGpa(double gpa);
string getName(string s);
void output();
int count();
int main() {
	init();
	int luachon;
	while (1 != 0) {
		cout << "1.Nhap sinh vien tu ban phim" << endl;
		cout << "2.Nhap sinh vien file" << endl;
		cout << "3.Xuat sinh vien" << endl;
		cout << "4.Loc danh sach sinh vien" << endl;
		cout << "5.Them sinh vien vao vi tri bat ky" << endl;
		cout << "6.Xoa sinh vien bat ky" << endl;
		cout << "7.Sap xep theo tieu chi" << endl;
		cout << "8.Ghi sinh vien" << endl;
		cout << "Lua chon: ";
		cin >> luachon;
		if (luachon == 1) {
			SinhVien sv = makeSinhVien();
			insertLast(sv);
		}
		else if (luachon == 2) {
			inputFromFile();
		}
		else if (luachon == 3) {
			output();
			cout << endl;
		}
		else if (luachon == 4) {
			cout << "1.Loc theo dia chi" << endl;
			cout << "2.Loc theo nam sinh" << endl;
			cout << "3.Loc theo ten" << endl;
			cout << "4.Loc theo gioi tinh" << endl;
			cout << "5.loc theo gpa" << endl;
			int lc1;
			cout << "Lua chon: "; cin >> lc1;
			if (lc1 == 1) {
				cout << "Nhap dia chi can loc ";
				cin.ignore();
				string s1; getline(cin, s1);
				locTheoDC(s1);
			}
			else if (lc1 == 2) {
				cout << "Nhap nam sinh can loc ";
				int s1; cin >> s1;
				locTheoNS(s1);
			}
			else if (lc1 == 3) {
				cout << "Nhap ten can loc ";
				cin.ignore();
				string s1; getline(cin, s1);
				locTheoTen(s1);
			}
			else if (lc1 == 4) {
				locTheoGt();
			}
			else {
				cout << "Nhap gpa can loc " << endl;
				double s1; cin >> s1;
				locTheoGpa(s1);
			}
		}
		else if (luachon == 5) {
			SinhVien sv = makeSinhVien();
			int k;
			cout << "Nhap vi tri: " << endl;
			cin >> k;
			bool check = insertIndex(k, sv);
			if (check == false) {
				cout << "Them that bai!" << endl;
			}
			else {
				cout << "Them thanh cong!" << endl;
			}
		}
		else if (luachon == 6) {
			bool check = deleteSinhVien();
			if (check == false) {
				cout << "Xoa that bai!" << endl;
			}
			else {
				cout << "Xoa thanh cong!" << endl;
			}
		}
		else if (luachon == 7) {
			sort();
		}
		else if (luachon == 8) {
			cout << "1.Ghi theo dia chi" << endl;
			cout << "2.Ghi theo nam sinh" << endl;
			cout << "3.Ghi theo ten" << endl;
			cout << "4.Ghi theo gioi tinh" << endl;
			cout << "5.Ghi theo gpa" << endl;
			cout << "Lua chon: "; int lc; cin >> lc;
			if (lc == 1) {
				writeToFile(v1);
			}
			else if (lc == 2) {
				writeToFile(v2);
			}
			else if (lc == 3) {
				writeToFile(v3);
			}
			else if (lc == 4) {
				writeToFile(v4);
			}
			else {
				writeToFile(v5);
			}
		}
	}
}

SinhVien makeSinhVien() {
	SinhVien sv;
	cout << "Nhap ma sinh vien: " << endl;
	cin >> sv.maSV;
	cin.ignore();
	cout << "Nhap ho ten sinh vien: " << endl;
	getline(cin, sv.hoTen);
	cout << "Nhap nam sinh: " << endl;
	cin >> sv.namSinh;
	cin.ignore();
	cout << "Nhap dia chi: " << endl;
	getline(cin, sv.diaChi);
	cout << "Nhap gioi tinh: " << endl;
	int lc;
	cout << "0.Nam" << endl;
	cout << "1.Nu" << endl;
	cin >> lc;
	sv.gioiTinh = lc;
	cout << "Nhap diem trung binnh: " << endl;
	cin >> sv.diemTB;
	cout << "Them sinh vien thanh cong" << endl;
	return sv;
}
Node* makeNode(SinhVien sv1) {
	Node* newNode = new Node();
	newNode->sv = sv1;
	newNode->next = NULL;
	return newNode;
}
void insertFirst(SinhVien sv) {
	Node* newNode = makeNode(sv);
	if (node == NULL) {
		node = newNode;
		return;
	}
}
void insertLast(SinhVien sv) {
	Node* newNode = makeNode(sv);
	if (node == NULL) {
		node = newNode;
		return;
	}
	Node* tmp = node;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newNode;
}
void outputSinhVien(SinhVien sv) {
	cout << sv.maSV << " " << sv.hoTen << " " << sv.namSinh << " " << sv.diaChi << " ";
	if (sv.gioiTinh == 0) {
		cout << "Nam" << " ";
	}
	else cout << "Nu" << " ";
	cout << sv.diemTB << " " << endl;
}
void output() {
	Node* tmp = node;
	while (tmp != NULL) {
		outputSinhVien(tmp->sv);
		tmp = tmp->next;
	}
}
bool insertIndex(int k, SinhVien sv) {
	if (k < 0 || k>count()) return false;
	if (node == NULL) {
		insertFirst(sv);
		return true;
	}
	Node* newNode = makeNode(sv);
	Node* tmp = node;
	for (int i = 1; i < k; i++) {
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
	return true;
}
bool deleteSinhVien() {
	cout << "Nhap ma sinh vien can xoa: " << endl;
	cin >> s;
	Node* tmp = node;
	if (tmp->sv.maSV == s) {
		node = node->next;
		delete tmp;
		return true;
	}
	int ok = 0;
	while (tmp->next != NULL) {
		if (tmp->next->sv.maSV == s) {
			ok = 1;
			break;
		}
	}
	if (!ok) {
		return false;
	}
	else {
		if (tmp->next == NULL) {
			delete tmp;
		}
		else {
			tmp->next = tmp->next->next;
			delete tmp->next;
		}
	}
	return true;
}
void sort() {
	if (node == NULL) {
		cout << "Khong co sinh vien de sap xep!" << endl;
		return;
	}
	int lc;
	cout << "1.Sap xep theo id" << endl;
	cout << "2.Sap xep theo ten" << endl;
	cout << "3.Sap xep theo nam sinh" << endl;
	cout << "4.Sap xep theo dia chi" << endl;
	cout << "5.Sap xep theo diem trung binh" << endl;
	cout << "Nhap lua chon: " << endl;
	cin >> lc;
	if (lc == 1) {
		for (Node* i = node; i != NULL; i = i->next) {
			Node* tmp = i;
			for (Node* j = i->next; j != NULL; j = j->next) {
				if (tmp->sv.maSV > j->sv.maSV) {
					tmp = j;
				}
			}
			SinhVien data = tmp->sv;
			tmp->sv = i->sv;
			i->sv = data;
		}
		cout << "Sap xep thanh cong!" << endl;
	}
	else if (lc == 2) {
		for (Node* i = node; i != NULL; i = i->next) {
			Node* tmp = i;
			for (Node* j = i->next; j != NULL; j = j->next) {
				if (getName(tmp->sv.hoTen) > getName(j->sv.hoTen)) {
					tmp = j;
				}
			}
			SinhVien data = tmp->sv;
			tmp->sv = i->sv;
			i->sv = data;
		}
		cout << "Sap xep thanh cong!" << endl;
	}
	else if (lc == 3) {
		for (Node* i = node; i != NULL; i = i->next) {
			Node* tmp = i;
			for (Node* j = i->next; j != NULL; j = j->next) {
				if (tmp->sv.namSinh > j->sv.namSinh) {
					tmp = j;
				}
			}
			SinhVien data = tmp->sv;
			tmp->sv = i->sv;
			i->sv = data;
		}
		cout << "Sap xep thanh cong!" << endl;
	}
	else if (lc == 4) {
		for (Node* i = node; i != NULL; i = i->next) {
			Node* tmp = i;
			for (Node* j = i->next; j != NULL; j = j->next) {
				if (tmp->sv.diaChi > j->sv.diaChi) {
					tmp = j;
				}
			}
			SinhVien data = tmp->sv;
			tmp->sv = i->sv;
			i->sv = data;
		}
		cout << "Sap xep thanh cong!" << endl;
	}
	else if (lc == 5) {
		for (Node* i = node; i != NULL; i = i->next) {
			Node* tmp = i;
			for (Node* j = i->next; j != NULL; j = j->next) {
				if (tmp->sv.diemTB > j->sv.diemTB) {
					tmp = j;
				}
			}
			SinhVien data = tmp->sv;
			tmp->sv = i->sv;
			i->sv = data;
		}
		cout << "Sap xep thanh cong!" << endl;
	}
}
string getName(string s) {
	string tmp = "";
	vector<string> v;
	stringstream ss(s);
	while (ss >> tmp) {
		v.push_back(tmp);
	}
	return v[v.size() - 1];
}
void writeToFile(vector<SinhVien> v) {
	if (v.size() == 0) {
		cout << "Khong co du lieu de ghi file" << endl;
		return;
	}
	ofstream fileOut;
	fileOut.open("test1.txt", ios::out);
	if (!fileOut.is_open()) {
		cout << "Ghi file that bai" << endl;
	}
	for (int i = 0; i < v.size(); i++) {
		fileOut << v[i].maSV << endl;
		fileOut << v[i].hoTen << endl;
		fileOut << v[i].namSinh << endl;
		fileOut << v[i].diaChi << endl;
		fileOut << v[i].gioiTinh << endl;
		fileOut << v[i].diemTB << endl;
	}
	cout << "Ghi file thanh cong" << endl;
	fileOut.close();
}
void inputFromFile() {

	ifstream fileIn;
	fileIn.open("test.txt", ios::in);
	if (!fileIn.is_open()) {
		cout << "Doc file that bai" << endl;
		return;
	}
	while (!fileIn.eof()) {
		SinhVien a;
		fileIn >> a.maSV;
		fileIn.ignore();
		getline(fileIn, a.hoTen);
		fileIn >> a.namSinh;
		fileIn.ignore();
		getline(fileIn, a.diaChi);
		fileIn >> a.gioiTinh;
		fileIn >> a.diemTB;
		insertLast(a);
	}
	cout << "Load file thanh cong" << endl;
	fileIn.close();
}
void  locTheoDC(string s) {
	Node* p = node;
	int ok = 0;
	while (p != NULL) {
		if (p->sv.diaChi == s) {
			outputSinhVien(p->sv);
			ok = 1;
			v1.push_back(p->sv);
		}
		p = p->next;
	}
	if (!ok) {
		cout << "Danh sach rong!" << endl;
		return;
	}
}
void locTheoNS(int nam) {
	Node* p = node;
	int ok = 0;
	while (p != NULL) {
		if (p->sv.namSinh == nam) {
			outputSinhVien(p->sv);
			ok = 1;
			v2.push_back(p->sv);
		}
		p = p->next;
	}
	if (!ok) {
		cout << "Danh sach rong!" << endl;
		return;
	}
}
void locTheoTen(string s) {
	Node* p = node;
	int ok = 0;
	while (p != NULL) {
		if (getName(p->sv.hoTen) == s) {
			outputSinhVien(p->sv);
			ok = 1;
			v3.push_back(p->sv);
		}
		p = p->next;
	}
	if (!ok) {
		cout << "Danh sach rong!" << endl;
		return;
	}
}
void locTheoGt() {
	Node* p = node;
	int ok = 0;
	cout << "0.Loc theo nam" << endl;
	cout << "1.Loc theo nu" << endl;
	cout << "Lua chon: "; int lc; cin >> lc;
	if (lc == 0) {
		while (p != NULL) {
			if (p->sv.gioiTinh == 0) {
				outputSinhVien(p->sv);
				ok = 1;
				v4.push_back(p->sv);
			}
			p = p->next;
		}
	}
	else {
		while (p != NULL) {
			if (p->sv.gioiTinh == 1) {
				outputSinhVien(p->sv);
				ok = 1;
			}
			p = p->next;
		}
	}
	if (!ok) cout << "Danh sach rong" << endl;
}
void locTheoGpa(double gpa) {
	Node* p = node;
	int ok = 0;
	while (p != NULL) {
		if (p->sv.diemTB >= gpa) {
			outputSinhVien(p->sv);
			ok = 1;
			v5.push_back(p->sv);
		}
		p = p->next;
	}
	if (!ok) {
		cout << "Danh sach rong" << endl;
	}
}
int count() {
	int dem = 0;
	Node* p = node;
	while (p != NULL) {
		++dem;
		p = p->next;
	}
	return dem;
}