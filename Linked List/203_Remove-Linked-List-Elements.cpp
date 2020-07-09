/*
Title:
    203. Remove Linked List Elements
    203. 移除链表元素
Address:
    https://leetcode-cn.com/problems/remove-linked-list-elements/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法一：直觉法
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* list_head = new ListNode( -1 );
        list_head->next = head;
        ListNode* preNode = list_head, *pNode = head, *target;

        while ( pNode ) {
            if ( pNode->val == val ) {
                target = pNode;
                preNode->next = pNode->next;
                target->next = nullptr;
                delete target;
            }
                
            else
                preNode = pNode;
                
            pNode = preNode->next;
        }

        return list_head->next;
    }
};

int main()
{
    

    return 0;
}