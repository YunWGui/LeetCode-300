/*
Title:
	21. Merge Two Sorted Lists
	21. 合并两个有序链表
Address:
	https://leetcode-cn.com/problems/merge-two-sorted-lists/

Tips:
	同《剑指offer》第25题
*/

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

// 解法一：递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( l1 == nullptr )
            return l2;
        if ( l2 == nullptr )
            return l1;

        // recursion
        ListNode* pMergedHead = nullptr;
        if ( l1->val < l2->val ) {
            pMergedHead = l1;
            pMergedHead->next = mergeTwoLists( l1->next, l2 );
        } else {
            pMergedHead = l2;
            pMergedHead->next = mergeTwoLists( l1, l2->next );
        }

        return pMergedHead;
    }
};

// 方法二：迭代
class Solution_2 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
		ListNode* head = new ListNode(0);  // 哨兵节点
		ListNode* tail = head;  // 尾节点

		while( l1 && l2 ){
			if(l1->val >= l2->val){
				tail->next = l2;
				l2 = l2->next;
			} else {
				tail->next = l1;
				l1 = l1->next;
			}
			tail = tail->next;
		}
		if( l1 ){
			tail->next = l1;
		}
		if( l2 ){
			tail->next = l2;
		}

		// delete head node
		ListNode* res = head;
		res = head->next;
		head->next = NULL;
		delete head;

		return res;
	}
};

int main()
{
	Solution solve;
	ListNode* list1 = new ListNode(1);
	ListNode* list2 = new ListNode(2);
	ListNode* cur;
	ListNode* head;

	cur = list1;
	for(int i = 3; i <= 10; ){
		cur->next = new ListNode(i);
		cur = cur->next;
		i += 2;
	}

	cur = list2;
	for(int i = 4; i <= 10; ){
		cur->next = new ListNode(i);
		cur = cur->next;
		i += 2;
	}

	head = solve.mergeTwoLists(list1, list2);

	while(head != NULL){
		cout << head->val << " ";
		cur = cur->next;
	}
	cout << endl;


	// print list1
	// cur = list1;
	// while(cur != NULL){
	// 	cout << cur->val << " ";
	// 	cur = cur->next;
	// }
	// cout << endl;

	// print list2
	// cur = list2;
	// while(cur != NULL){
	// 	cout << cur->val << " ";
	// 	cur = cur->next;
	// }
	// cout << endl;

	return 0;
}
