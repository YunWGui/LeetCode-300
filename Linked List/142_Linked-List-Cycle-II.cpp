/*
Title:
    142. Linked List Cycle II
    142. 环形链表 II
Address:
    https://leetcode-cn.com/problems/linked-list-cycle-ii/
Tips:
    141. Linked List Cycle
        https://leetcode-cn.com/problems/linked-list-cycle/
    同《剑指 Offer》第 23 题
*/

#include <iostream>
using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {  }
};

// 方法一：双指针 - 快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if ( head == nullptr || head->next == nullptr )
            return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;

        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;

            if ( slow == fast )
                break;
        }

        if ( fast == nullptr || fast->next == nullptr )
            return nullptr;
        
        slow = head;
        while ( slow != fast ) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// 方法二：双指针 - 快慢指针 - 另一个写法
class Solution_2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if ( head == nullptr || head->next == nullptr )
            return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;

        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next;

            if ( fast != nullptr )
                fast = fast->next;
            else
                return nullptr;
            
            if ( fast == slow ) {
                slow = head;
                while ( fast != slow ) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        

        }

        return nullptr;
    }
};

int main()
{
    

    return 0;
}