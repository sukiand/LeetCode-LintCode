/*	You are given two linked lists representing two non-negative numbers. 
	The digits are stored in reverse order and each of their nodes contain a single digit. 
	Add the two numbers and return it as a linked list.

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
#include <stdlib.h>

class Solution {
private:
	struct ListNode {
		int val;
		ListNode *next;
/*		ListNode(int x) : val(x), next(NULL) {}*/
	};
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		return addTwoNumbers(l1, l2, 0);
	}

	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int flag){
		if (l1 != NULL && l2 != NULL){
			int n = l1->val + l2->val + flag;
			if (n > 9){
				l1->val = n - 10;
				flag = 1;
			}
			else {
				l1->val = n;
				flag = 0;
			}
			l1->next = addTwoNumbers(l1->next, l2->next, flag);
			return l1;
		}
		else if (l1 == NULL){
			return addTwoNumbers(l2, flag);
		}
		else{
			return addTwoNumbers(l1, flag);
		}
	}
	ListNode *addTwoNumbers(ListNode *l1, int flag){
		if (l1 == NULL && flag == 0){
			return NULL;
		}
		else if (l1 == NULL && flag == 1){
			ListNode *p = new ListNode(1);
			return p;
		}
		else{
			l1->val += flag;
			if (l1->val > 9){
				l1->val -= 10;
				flag = 1;
				l1->next = addTwoNumbers(l1->next, flag);          //need to be clear!!!
				return l1;
			}
			else {
				return l1;
			}
		}
	}
};