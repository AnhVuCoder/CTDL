#include "iostream"
#include "fstream"

using namespace std;
const int MAX = 50;
#define INF INT_MAX;
int n, a[MAX][MAX], check[MAX], bfs[MAX], nbfs = 0;


//------------------------------------Queue-------------------------------------------
struct Node {
	int data;
	Node* next;
};
Node* front, * rear;

void initStatus() {
	for (int i = 0; i < n; i++) {
		check[i] = 1;
	}
}
void init() {
	front = rear = NULL;
}
Node* createNode(int val) {
	Node* node = new Node;
	if (!node) return NULL;
	node->data = val;
	node->next = NULL;
	return node;
}
bool isEmpty() {
	return front == NULL;
}
void push(int val) {
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
void pop(int& val) {
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
//-----------------------------------------------------End queue---------------------------

void inputFromFile();
void output();
void BFS(int x);
bool checkNotDirected();
void tinhSoBac();
void tinhSoDinhVaLietKe(int x, int y);
void outputBFS(int a1[], int n1);
//----------------------------------Prims------------------------------------------------------------------------
int getMinVertex(bool* visited, int* key, int v) {
	int minIndex = -1;
	int min = INF;

	for (int i = 0; i < v; i++) {
		if (visited[i] == false && key[i] < min) {
			min = key[i];
			minIndex = i;
		}
	}
	return minIndex;
}

//--------------------------------------Prims---------------------------------------------------------
void primsMST(int adjMat[][MAX]) {
	int parent[MAX]; 
	int key[MAX];  
	int total = 0;
	bool visited[MAX]; 
	for (int i = 0; i < n; i++) {
		key[i] = INF;
		visited[i] = false;
	}
	key[0] = 0; 
	parent[0] = -1;
	for (int i = 0; i < n - 1; i++) {
		int U = getMinVertex(visited, key, n);
		visited[U] = true;
		for (int j = 0; j < n; j++) {
			if (adjMat[U][j] != 0 && !visited[j]) {     
				if (adjMat[U][j] < key[j]) {
					parent[j] = U;
					key[j] = adjMat[U][j];
				}
			}
		}
	}
	for (int i = 1; i < n; i++)
		total += a[i][parent[i]];
	for (int i = 1; i < n; i++)
		cout << parent[i] << " - " << i << "\n";
	cout << "Total: " << total << endl;
}
//-------------------------------------End prims-----------------------------------------
int nEdge, Mat[MAX][MAX], MST[MAX][MAX], parent[MAX];
struct Edge {
	int u;
	int v;
	int w;
};

struct Edge edgeList[MAX];
int edgeNum;

void addEdge(int u, int v, int w) {
	edgeList[edgeNum].u = u;
	edgeList[edgeNum].v = v;
	edgeList[edgeNum].w = w;
	edgeNum++;
}

int find(int x) {
	while (parent[x] != -1)
		x = parent[x];
	return x;
}

void Union(int x, int y) {
	int xset = find(x);
	int yset = find(y);
	if (xset != yset)
		parent[xset] = yset;
}
void selectionSort() {
	int i, j, min;
	for (i = 0; i < edgeNum - 1; i++) {
		min = i;
		for (j = i + 1; j < edgeNum; j++)
			if (edgeList[j].w < edgeList[min].w)
				min = j;

		struct Edge temp = edgeList[min];
		edgeList[min] = edgeList[i];
		edgeList[i] = temp;
	}
}
void createEdge() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0) {
				edgeList[edgeNum].u = i;
				edgeList[edgeNum].v = j;
				edgeList[edgeNum].w = a[i][j];
				a[i][j] = a[j][i] = 0;
				edgeNum++;
			}
		}
	}
}
void kruskal() {

	int mst_wt = 0;

	for (int i = 0; i < n; i++)
		parent[i] = -1;

	selectionSort();

	printf("Cac canh trong cay khung nho nhat la:\n");

	for (int i = 0; i < edgeNum; i++) {
		int u = find(edgeList[i].u);
		int v = find(edgeList[i].v);

		if (u != v) {
			printf("%d - %d\n", edgeList[i].u, edgeList[i].v);
			mst_wt += edgeList[i].w;
			Union(u, v);
		}
	}

	printf("Tong trong so la: %d", mst_wt);
}
int main() {
	inputFromFile();
	createEdge();
	kruskal();
	cout << endl;
	system("pause");
}



void inputFromFile() {
	ifstream in;
	in.open("data.txt");
	if (!in.is_open()) {
		cout << "Doc file that bai!" << endl;
		return;
	}
	in >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> a[i][j];
		}
	}
	in.close();
	cout << "Doc file thanh cong!" << endl;
}
void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void BFS(int s) {
	initStatus();
	init();
	check[s] = 0;
	push(s);
	int w, p;
	while (front != NULL) {
		pop(p);
		bfs[nbfs++] = p;
		for (w = 0; w < n; w++) {
			if (check[w] == 1 && a[p][w] > 0) {
				push(w);
				check[w] = 0;
			}
		}
	}
}
void outputBFS(int a1[], int n1) {
	cout << "Ket qua duyet BFS: ";
	for (int i = 0; i < n1; i++) {
		cout << a1[i] << " ";
	}
	cout << endl;
}
bool checkNotDirected() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != a[j][i])
				return false;
		}
	}
	return true;
}
void tinhSoBac() {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j]) sum++;
		}
		cout << "So bac cua dinh " << i << " la: " << sum << endl;
	}
}
void tinhSoDinhVaLietKe(int x, int y) {
	initStatus();
	init();
	check[x] = 0;
	push(x);
	int w, p;
	while (front != NULL) {
		pop(p);
		bfs[nbfs++] = p;
		if (p == y) break;
		for (w = 0; w < n; w++) {
			if (check[w] == 1 && a[p][w] > 0) {
				push(w);
				check[w] = 0;
			}
		}
	}
	cout << nbfs << endl;
	outputBFS(bfs, nbfs);
}
