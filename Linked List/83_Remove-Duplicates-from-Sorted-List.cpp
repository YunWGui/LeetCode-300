/*
Title:
	83. Remove Duplicates from Sorted List
	83. 删除排序链表中的重复元素
Address:
	https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next() {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( !head || !head->next )
            return head;

        ListNode* tail = head;
        while( (tail != nullptr) && (tail->next != nullptr) ){
            if( tail->val == tail->next->val ){
                tail->next = tail->next->next;
            } else {
                tail = tail->next;
            }
        }
        return head;
    }
};

ListNode* createList(int a[], int n){
	ListNode* head = nullptr, * p = nullptr;
	for(int i = 0; i < n; i++){
		if(head == nullptr){
			head = p = new ListNode(a[i]);
		} else {
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head;
}

void print(ListNode* h){
	while(h != nullptr){
		cout << h->val << " ";
		h = h->next;
	}
	cout << endl;
}


int main()
{
	Solution solve;

	int a[] = {1, 1, 2, 3, 3};
	int b[] = {1, 1, 1};
	int c[] = {1, 2, 3};
	int d[] = {3};

	print(solve.deleteDuplicates(createList(a, sizeof(a) / sizeof(int))));
	print(solve.deleteDuplicates(createList(b, sizeof(b) / sizeof(int))));
	print(solve.deleteDuplicates(createList(c, sizeof(c) / sizeof(int))));
	print(solve.deleteDuplicates(createList(d, sizeof(d) / sizeof(int))));

	return 0;
}
