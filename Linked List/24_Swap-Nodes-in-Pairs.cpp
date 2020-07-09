/*
Title:
    24. Swap Nodes in Pairs
    24. 两两交换链表中的节点
Address:
    https://leetcode-cn.com/problems/swap-nodes-in-pairs/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法一：作图解答
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

		ListNode* head_node = new ListNode(0);  // 哨兵节点
		head_node->next = head;

		ListNode* pre = head_node, *cur = head, *nxt = head->next;
		while(nxt){
			// swap
			cur->next = nxt->next;
			nxt->next = cur;
			pre->next = nxt;
			// pointer left move, due to swap again
			pre = cur;
			cur = pre->next;
			if(cur == NULL)  // 如果 cur == nullptr，则 nxt = cur->next 会报错
                break;  
			nxt = cur->next;
		}
		return head_node->next;
    }
};

// 方法二
class Solution_2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;
        
        ListNode* pre = nullptr;
        ListNode* newHead = nullptr;  // 翻转后链表的头节点
        for ( ListNode* cur = head; cur && cur->next; cur = cur->next ) {
            ListNode* nxt = cur->next;
            
            cur->next = nxt->next;
            nxt->next = cur;

            if ( pre )
                pre->next = nxt;
            
            pre = cur;

            if ( cur == head )
                newHead = nxt;
        }

        return newHead;
    }
};

// 递归
class Solution_3 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        auto cur = head;
        auto nxt = cur->next;
        cur->next = swapPairs(nxt->next);
        nxt->next = cur;
        return nxt;
    }
};


int main()
{


	return 0;
}
