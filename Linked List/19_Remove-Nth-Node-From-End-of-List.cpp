/*
Title:
    19. Remove Nth Node From End of List
    19. 删除链表的倒数第 N 个节点
Address:
    https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
*/


#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
方案 1 ~ 3 解题思路：

题意就是去掉链表中倒数第n个节点。
涉及到链表中倒数节点的思路都是使用两个指针p1、p2，两个指针初始都是head，p2先走n步，
然后p1、p2再同时走直到p2到达链尾，
此时p1就位于链表倒数第n个节点的前一个节点。
需要注意当要删除的节点就是head时需要特殊处理。
时间复杂度O(N)，空间复杂度O(1)
*/

// 方案一：
class Solution_1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n <= 0)
            return head;
        ListNode *p1 = head, *p2 = head;
        while(n--)
            p2 = p2 -> next;  // p2先走n步
        if(p2 == NULL){ // 此时删掉的应该是head,如 list = [1, 2], n = 2
        // 根据条件 n 始终有效，故当 p2==nullptr 时，要删除的就是首节点
            head = head -> next;
            delete p1;
            return head;
        }
        while(p2 -> next){  // 当 p2->next == nullptr，此时 p2 到达链表尾部
            p1 = p1 -> next;
            p2 = p2 -> next;
        } // 此时p1位于倒数第n个节点的前一个节点
        p2 = p1 -> next;
        p1 -> next = p2 -> next;
        delete p2;
        return head;
    }
};

// 方案二：
class Solution_2 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n <= 0)  // 边界条件
            return NULL;

        ListNode fakeHead(0);
        fakeHead.next = head;
        head          = &fakeHead;

        ListNode *p1, *p2;
        p1 = p2 = head;
       	while(n--)
            p2 = p2->next;

        while (p2->next != NULL) {
            p2 = p2->next;
            p1 = p1->next;
        }

        p1->next = p1->next->next;
        return head->next;
    }
};

// 方案三：
class Solution_3 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(head == NULL || n <= 0)
			return NULL;

		ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* p1 = head, *p2 = head;

        for (int i = 0; i < n; i++) {
            p2 = p2->next;
        }

        if(p2 == NULL)
            return head->next;

        while(p2->next != NULL) {
            p1 = p1->next;
			p2 = p2->next;
        }
        p1->next = p1->next->next;

        return dummyHead->next;
    }
};

// 方案四：使用 vector 容器解题
class Solution_4 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        vector<ListNode*> vec;
        while(head->next != nullptr) {
            vec.push_back(head);    //把链表中的所有节点放到vector中
            head = head->next;
        }
        vec.push_back(head);    //别忘了最后一个节点
        vec.erase(vec.begin()+vec.size()-n);    //删掉要求的那个节点

		if(vec.size() == 0)
			return nullptr;

        for(int i = 0 ; i < vec.size()-1 ; i ++)
            vec[i]->next = vec[i+1];    //将容器内的点前后相连

        vec[vec.size()-1]->next = nullptr;  //最后一个节点确保next为空

		return vec[0];  //返回第一个节点即可
    }
};


int main()
{


	return 0;
}
