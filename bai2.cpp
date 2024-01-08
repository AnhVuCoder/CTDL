#include "iostream"

using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* createNode(int x) {
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void insertLast(Node* &head, int x) {
	Node* newNode = createNode(x);
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newNode;
}
int find(Node* head, int x) {
	Node* q = head;
	while (q != NULL) {
		if (q->data == x) {
			return x;
		}
		q = q->next;
	}
	return INT_MIN;
}
void display(Node* head) {
	Node* p = head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
Node* timGiao(Node* head1, Node* head2) {
	Node* head3 = NULL;
	Node* p = head1;
	while (p != NULL) {
		if (find(head2, p->data) != INT_MIN) {
			insertLast(head3, p->data);
		}
		p = p->next;
	}
	return head3;
}
Node* timHop(Node* head1, Node* head2) {
	Node* head3 = NULL;
	Node* p = head1;
	while (p != NULL) {
		if (find(head2, p->data) == INT_MIN) {
			insertLast(head3, p->data);
		}
		p = p->next;
	}
	Node* tmp = head3;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = head2;
	return head3;
}
Node* timBuA(Node* head1, Node* head2) {
	Node* head3 = NULL;
	Node* p = head1;
	while (p !=NULL) {
		if (find(head2, p->data) == INT_MIN) {
			insertLast(head3, p->data);
		}
		p = p->next;
	}
	return head3;
}
Node* timBuB(Node* head1, Node* head2) {
	Node* head3 = NULL;
	Node* p = head2;
	while (p != NULL) {
		if (find(head1, p->data) == INT_MIN) {
			insertLast(head3, p->data);
		}
		p = p->next;
	}
	return head3;
}
int main() {
	Node* head1=NULL, * head2=NULL;
	//Insert head1
	insertLast(head1, 1);
	insertLast(head1, 3);
	insertLast(head1, 5);
	insertLast(head1, 8);
	insertLast(head1, 9);
	//Insert head2
	insertLast(head2, 2);
	insertLast(head2, 4);
	insertLast(head2, 6);
	insertLast(head2, 8);
	insertLast(head2, 9);
	//Tim giao
	Node* head3 = timGiao(head1, head2);
	display(head3);
	//Tim hop
	Node* head4 = timHop(head1, head2);
	display(head4);
	//Tim bu A
	Node* head5 = timBuA(head1, head2);
	display(head5);
	//Tim bu B
	Node* head6 = timBuB(head1, head2);
	display(head6);
	system("pause");
}