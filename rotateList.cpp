#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){};
};

ListNode *rotateList(ListNode *A, int pos){
	ListNode *p;
	int length = 0;
	for (p = A; p->next!=nullptr; p = p->next){
		length++;
	}
	length++;
	p->next = A;
	int k = pos % length;
	k = length - k;
	p = A;
	for (int i = 0; i < k -1; i++){
		p = p->next;
	}
	A = p->next;
	p->next = nullptr;
	return A;
}

void printList(ListNode *A){
	for (ListNode *p = A; p; p = p->next){
		cout << p->val;
	}
	cout << endl;
}

int main(int argc, char ** argv){
	ListNode k1(1);
	ListNode k2(2);
	ListNode k3(3);
	ListNode k4(4);
	ListNode k5(5);
	ListNode k6(6);
	ListNode *head = &k1;
	k1.next = &k2;
	k2.next = &k3;
	k3.next = &k4;
	k4.next = &k5;
	k5.next = &k6;

	printList(head);
	printList(rotateList(head,5));
	getchar();
}