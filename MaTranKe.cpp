#include "iostream"
#include  "fstream"
using namespace std;
#define MAX 20
int A[MAX][MAX], check[MAX], dfs[MAX], ndfs=0, n, bfs[MAX], nbfs=0;
char vertex[MAX];
void input();
void output();
void inputFromFile();
//Stack
struct Node {
	int data;
	Node* next;
};
Node* st;
void init() {
	st = NULL;
}
bool isEmpty() {
	return st == NULL;
}
void push(int val);
void pop(int& val);
void progressStack();
void DFS(int s);
void outputDFS() {
	cout << "Ket qua duyet DFS: ";
	for (int i = 0; i < n; i++) {
		cout << vertex[dfs[i]] << " ";
	}
	cout << endl;
}
void initStatus() {
	for (int i = 0; i < n; i++) {
		check[i] = 1;
	}
}
//end Stack
//Queue
Node* front, * rear;
void initQ();
bool isEmptyQ();
void pushQ(int val);
void popQ(int& val);
void progressQueue();
void BFS(int s);
void outputBFS();
void BFS(int s);
int main() {
	inputFromFile();
	output();
	BFS(0);
	outputBFS();
	system("pause");
}
void input() {
	do {
		cout << "Nhap so luong dinh cua do thi: ";
		cin >> n;
	} while (n<=0 || n > MAX);
	cout << "Nhap " << n << " ten cac dinh cua do thi theo thu tu: ";
	//Nhap ma tran ke
	for (int i = 0; i < n; i++) {
		cin >> vertex[i];
	}
	for (int i = 0; i < n; i++) {
		cout << "Nhap tinh chat ke(1/0) cua dinh " << vertex[i] << ": ";
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
}
void output() {
	cout << "\t";
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << "\t";
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl; 
	}
}
void inputFromFile() {
	ifstream inFile;
	inFile.open("data.txt");
	if (!inFile.is_open()) {
		cout << "Doc file khong thanh cong!" << endl;
	}
	inFile >> n;
	for (int i = 0; i < n; i++) inFile >> vertex[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			inFile >> A[i][j];
		}
	}
	inFile.close();
	cout << "Doc file thanh cong!" << endl;
}
Node* createNode(int val) {
	Node* node = new Node;
	if (!node) return NULL;
	node->data = val;
	node->next = NULL;
	return node;
}
void push(int val) {
	Node* p = createNode(val);
	if (!p) return;
	if (st == NULL) st = p;
	else {
		p->next = st;
		st = p;
	}
}
void pop(int& val) {
	Node* p = st;
	val = p->data;
	st = st->next;
	delete p;
}
void progressStack() {
	Node* p = st;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void DFS(int s) {
	init();
	initStatus();
	dfs[ndfs++] = s;
	push(s);
	check[s] = 0;
	int u=s, v=-1;
	while (!isEmpty()) {
		if (v == n) pop(u);
		for (v = 0; v < n; v++) {
			if (A[u][v] != 0 && check[v] == 1) {
				push(u);
				push(v);
				dfs[ndfs++] = v;
				check[v] = 0;
				u = v;
				break;
			}
		}
	}
}
void initQ() {
	front = rear = NULL;
}
bool isEmptyQ() {
	return front == NULL;
}
void pushQ(int val) {
	Node* p = createNode(val);
	if (!p) return;
	if (rear == NULL) {
		front = p;
		rear = p;
	}
	else {
		rear->next = p;
		rear = p;
	}
}
void popQ(int& val) {
	if (front != NULL) {
		Node* p = front;
		val = p->data;
		front = front->next;
		if (front == NULL) rear = NULL;
		delete p;
	}
}
void progressQueue() {
	cout << "Duyet hang doi: " << endl;
	Node* p = front;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void BFS(int s) {
	initStatus();
	initQ();
	check[s] = 0;
	pushQ(s);
	int w, p;
	while (front!=NULL) {
		popQ(p);
		bfs[nbfs++] = p;
		for (w = 0; w < n; w++) {
			if (check[w] == 1 && A[p][w] == 1) {
				pushQ(w);
				check[w] = 0;
			}
		}
	}
}
void outputBFS() {
	cout << "Ket qua duyet BFS: ";
	for (int i = 0; i < n; i++) {
		cout << vertex[bfs[i]] << " ";
	}
	cout << endl;
}