#include "iostream"

using namespace std;

#define MAX 200
struct Node {
	int data;
	Node* next;
};
int n;
char vertex[MAX];
Node* head[MAX];
void init();
Node* createNode(int val);
void insertFirst(Node *&h, int val);
void inputList();
void outputAll();
void outputOne(int n);

int main() {
	inputList();
	outputAll();
	system("pause");
}
void init() {
	for (int i = 0; i < n; i++) {
		head[i] = NULL;
	}
}
Node* createNode(int val) {
	Node* node = new Node;
	if (!node) return NULL;
	node->data = val;
	node->next = NULL;
	return node;
}
void insertFirst(Node *&h, int val) {
	Node* node = createNode(val);
	if (!node) return;
	if (h == NULL) h = node;
	else {
		node->next = h;
		h = node;
	}
}
void inputList() {
	do {
		cout << "Nhap so luong phan tu: "; cin >> n;
	} while (n <= 0 || n > MAX);
	init();
	cout << "Nhap danh sach cac dinh: ";
	for (int i = 0; i < n; i++) {
		cin >> vertex[i]; 
	}
	for (int i = 0; i < n; i++) {
		insertFirst(head[i], i);
		int x;
		cout << "Nhap danh sach cac dinh ke voi dinh " << vertex[i]<<" muon dung thi nhan -1: ";
		while (cin >> x) {
			if (x == -1) break;
			insertFirst(head[i], x);
		}
	}
}
void outputAll() {
	for (int i = 0; i < n; i++) {
		cout << "Danh sach ke voi dinh " << vertex[i] << " :";
		Node* p = head[i];
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}