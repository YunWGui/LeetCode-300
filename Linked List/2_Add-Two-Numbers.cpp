/*
Title:
    2. Add Two Numbers
    2. 两数相加
Address:
    https://leetcode-cn.com/problems/add-two-numbers/
*/


#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) { }
};

// BUG -- 方案一：刚开始能通过，后来又通不过
class Solution_1{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        int temp = 0;
        while(l1 || l2){  // 后面简化为 if(l1) , if(l2)
            int n1 = 11 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int total = n1 + n2 + temp;

            // temp = total / 10;
            // cur->next = new ListNode(total % 10);

            if( total < 10){
                cur->next = new ListNode(total);
                temp = 0;
            } else{
                cur->next = new ListNode(total - 10);
                temp = 1;
            }

            cur = cur->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(temp)
            cur->next = new ListNode(1);

        return res->next;
    }
};


// 方案二：更快
class Solution_2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode( -1 );
        ListNode* tail = head;
        bool carryFlag = false;  // 进位标志位

        while ( l1 || l2 ) {
            int total = 0;
            if ( l1 ) {
                total += l1->val;
                l1 = l1->next;
            }
            if ( l2 ) {
                total += l2->val;
                l2 = l2->next;
            }
            if ( carryFlag ) 
                ++total;
            
            tail->next = new ListNode( total % 10 );
            tail = tail->next;
            carryFlag = total >= 10 ? true : false;
        }
        
        if ( carryFlag )
            tail->next = new ListNode( 1 );

        return head->next;
    }
};

// 方案三：
class Solution_3 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if ( l1 == nullptr )    return l2;
        if ( l2 == nullptr )    return l1;

        ListNode dummy( -1 );  // 哨兵节点
        ListNode* p = &dummy;
        int carryFlag = 0;  // 进位标志位

        for ( ; l1 || l2; p = p->next ) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carryFlag;

            p->next = new ListNode( sum % 10 );
            carryFlag = sum / 10;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if ( carryFlag )
            p->next = new ListNode( carryFlag );

        return dummy.next;
    }
};


int main()
{


    return 0;
}
