/*
Title:
    141. Linked List Cycle
    141. 环形链表
Address:
    https://leetcode-cn.com/problems/linked-list-cycle/
Tips:
    142. Linked List Cycle II
    https://leetcode-cn.com/problems/linked-list-cycle-ii/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode( int x ) : val( x ), next( nullptr ) {  };
};

// 方法一：双指针 - 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( head == nullptr )
            return false;
            
        ListNode* fast = head;
        ListNode* slow = head;
        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;
            if ( fast == slow )
                return true;
        }

        return false;
    }
};

int main()
{
    

    return 0;
}