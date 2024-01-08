#include "iostream"
#include "conio.h"
using namespace std;
const int MAX = 100;
int np;
void init(int a[], int& sp);
int Push(int a[], int& sp, int x);
int Pop(int a[], int& sp, int &x);
int isFull(int a[], int sp);
int isEmpty(int a[], int sp);
int Convert10To2(int a[], int &sp, int tp);
int main() {
	int a[MAX];
	int sp;
	int luachon, x ,in = 0;
	do {
		system("cls");
		cout << "Menu" << endl;
		cout << "1.Khao tao stack" << endl;
		cout << "2.Them" << endl;
		cout << "3.Lay" << endl;
		cout << "4.Kiem tra day" << endl;
		cout << "5.Kiem tra rong" << endl;
		cout << "6.Chuyen he 10 sang he 2" << endl;
		cout << "7.Thoat" << endl;
		cout << "Moi nhap lua chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
			init(a, sp);
			in = 1;
			cout << "Khao tao thanh cong!" << endl;
			break;
		case 2:
			if (in) {
				cout << "Nhap gia tri can them: " << endl;
				cin >> x;
				if (Push(a, sp, x)) {
					cout << "Them thanh cong" << endl;
				}
				else cout << "Them that bai" << endl;
			}
			else {
				cout << "Vui long khoi tao stack!" << endl;
			}
			break;
		case 3:
			if (in) {
				if (Pop(a, sp, x)) {
					cout << "Phan tu vua lay ra khoi stack la " << x << endl;
				}
				else {
					cout << "Khong lay duoc phan tu dinh stack" << endl;
				}
			}
			else {
				cout << "Vui long khoi tao stack!" << endl;
			}
			break;
		case 4:
			if (in) {
				if (isFull(a, sp)) {
					cout << "Stack day" << endl;
				}
				else {
					cout << "Stack chua day" << endl;
				}
			}
			else {
				cout << "Vui long khoi tao stack!" << endl;
			}
			break;
		case 5:
			if (in) {
				if (isEmpty(a, sp)) {
					cout << "Stack rong" << endl;
				}
				else {
					cout << "Stack khong rong" << endl;
				}
			}
			else {
				cout << "Vui long khoi tao stack!" << endl;
			}
		case 6:
			cout << "Nhap so can tinh: " << endl;
			int y; cin >> y;
			np = Convert10To2(a, sp, y);
			if (np) {
				cout << np;
			}
			else {
				cout << "Chuyen khong thanh cong!" << endl;
			}
		default:
			break;
		}
		_getch();
	} while (luachon >= 1 && luachon <= 6);
}
void init(int a[], int& sp) {
	sp = -1;
}
int Push(int a[], int& sp, int x) {
	if (sp < MAX - 1) {
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int& sp, int& x) {
	if (sp != -1) {
		x = a[sp--];
		return 1;
	}
	return 0;
}
int isFull(int a[], int sp) {
	if (sp == MAX - 1) return 1;
	return 0;
}
int isEmpty(int a[], int sp) {
	if (sp == -1) return 1;
	return 0;
}
int Convert10To2(int a[], int &sp, int tp) {
	init(a, sp);
	while (tp != 0) {
		int du = tp % 2;
		if (!Push(a, sp, du)) return INT_MIN;
		tp = tp / 2;
	}
	int np = 0;
	while (!isEmpty(a, sp)) {
		int so;
		if (!Pop(a, sp, so)) return INT_MIN;
		np = np * 10 + so;
	}
	return np;
}