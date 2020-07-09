/*
Title
	160. Intersection of Two Linked Lists
    160. 相交链表
Address:
    https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next() {}
};

#include <iostream>
using namespace std;

// 解法一：双指针
class Solution_3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ( !headA || !headB )
            return nullptr;

        ListNode* curA = headA;
        ListNode* curB = headB;

        while ( curA != curB ) {
            if ( !curA )
                curA = headB;
            else
                curA = curA->next;

            if ( !curB )
                curB = headA;
            else
                curB = curB->next;
        }

        return curA;
    }
};
int main()
{


	return 0;
}
