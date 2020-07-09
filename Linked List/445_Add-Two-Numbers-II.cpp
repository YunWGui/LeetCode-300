/*
Title:
    445. Add Two Numbers II
    445. 两数相加 II
Address:
    https://leetcode-cn.com/problems/add-two-numbers-ii/
Tips:
    2. Add Two Numbers
    https://leetcode-cn.com/problems/add-two-numbers/
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode( int x ) : val( x ), next( nullptr );
};

// 方法一：栈
/* 
思路：
    1、分别将两个链表的值压入栈 S1, S2 中
    2、将栈 S1、S2 的和压入栈 S 中
    3、栈 S 出栈，组成链表
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> S1, S2, S;
        while ( l1 != nullptr ) {
            S1.push( l1->val );
            l1 = l1->next;
        }
        while ( l2 != nullptr ) {
            S2.push( l2->val );
            l2 = l2->next;
        }

        int carryFlag = 0;  // 进位标志位
        while ( !S1.empty() || !S2.empty() ) {
            int total = 0;
            if ( !S1.empty() ) {
                total += S1.top();
                S1.pop();
            }                
            if ( !S2.empty() ) {
                total += S2.top();
                S2.pop();
            }
            if ( carryFlag )
                ++total;
            
            S.push( total % 10 );

            carryFlag = total >= 10 ? 1 : 0;
        }
        if ( carryFlag )
            S.push( 1 );
        
        ListNode* head = new ListNode( - 1 );
        ListNode* tail = head;
        while ( !S.empty() ) {
            tail->next = new ListNode( S.top() );
            S.pop();
            tail = tail->next;
        }

        return head->next;
    }
};

int main()
{
    

    return 0;
}