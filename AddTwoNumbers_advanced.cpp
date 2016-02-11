#include <iostream>

using namespace std;

struct Node{
	int var;
	Node * next;
	Node(int x) : var(x), next(nullptr){}
};

Node addTwoNumbers(Node *h1, Node *h2){
	Node re(-1);
	Node *p = &re;
	int carry = -1;
	for (Node *p1 = h1->next, *p2 = h2->next;
		p1 != nullptr || p2 != nullptr;
		p1 = p1 == nullptr ? nullptr : p1->next,
		p2 = p2 == nullptr ? nullptr : p2->next,
		p = p->next)
	{
		const int a = p1 == nullptr ? 0 : p1->var;
		const int b = p2 == nullptr ? 0 : p2->var;
		const int value = (a + b + carry) % 10;
		carry = (a + b + carry) / 10;
		p->next = new Node(value);
		/*cout << a <<" "<< b << " "<< carry << " ";*/
	}
	if (carry > 0){
		p->next = new Node(carry);
	}
	return re;
}

void printNode(Node *h){
	for (Node *p = h->next; p != nullptr; p = p->next){
		cout << p->var << " ";
	}
	cout << endl;
}

int main(int argc, char ** argv){
	Node *head1 = new Node(-1);
	Node *head2 = new Node(-1);
	head1->next = new Node(2);
	head1->next->next = new Node(4);
	head1->next -> next->next = new Node(3);
	head2->next = new Node(5);
	head2->next->next = new Node(6);
	head2->next->next->next = new Node(4);
	printNode(head1);
	printNode(head2);
	printNode(&addTwoNumbers(head1, head2)); //为什么只能传实体， 不能传指针
	getchar();
}