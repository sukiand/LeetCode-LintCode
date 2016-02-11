#include <iostream>
#include <vector>
#include <string>

using namespace std;


class ListNode {
public:
		int val;
		ListNode *next;
		ListNode(int val) {
			this->val = val;
			this->next = NULL;
		}
};

ListNode *deleteDuplicates(ListNode *head) {
	// write your code here
	if (head == nullptr || head->next == nullptr) return head;
	ListNode *new_head = new ListNode(INT_MIN);


	new_head->next = head;
	ListNode *pos = new_head;
	while (pos != nullptr && pos->next != nullptr){
		ListNode *p = pos->next;
		if (p->next == nullptr){
			pos = pos->next;
			continue;
		}
		else if (p->val != p->next->val){
			pos = pos->next;
			continue;
		}
		else{
			while (p != nullptr && p->val == pos->next->val){
				p = p->next;
			}
			pos->next = p;
		}
	}


	return new_head->next;
}

ListNode *VectorToList(vector<int> &k){
	ListNode *head = new ListNode(-1);
	ListNode *p = head;
	for (int i = 0; i < k.size(); i++){
		p->next = new ListNode(k[i]);
		p = p->next;
	}
	return head->next;
}

void printList(ListNode *head){
	ListNode *p = head;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

void main(){
	vector<int> k = { 1, 1 };
	ListNode *head = VectorToList(k);
	printList(head);
	printList(deleteDuplicates(head));
	getchar();
}