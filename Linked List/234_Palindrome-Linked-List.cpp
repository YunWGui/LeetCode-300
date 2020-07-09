/*
Title:
    234. Palindrome Linked List
    234. 回文链表
Address: 
    https://leetcode-cn.com/problems/palindrome-linked-list/
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {  }
};

// 方法二：原地算法 - 双指针 - 快慢指针
class Solution_2 {
public:
    bool isPalindrome(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;

        // 节点数为「奇」，则指向「中点」
        // 节点数为「偶」，则指向「中点偏后的那个节点」
        while ( fast != nullptr && fast->next != nullptr ) {  
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 翻转后半部分链表 -- 参考 LeetCode-206 翻转链表
        ListNode* prevNode = nullptr;
        while ( slow != nullptr ) {
            ListNode* nextNode = slow->next;

            slow->next = prevNode;

            // 移动到下一个节点
            prevNode = slow;
            slow = nextNode;
        }

        // 比较
        while ( head != nullptr && prevNode != nullptr ) {
            if ( head->val != prevNode->val )
                return false;
            
            head = head->next;
            prevNode = prevNode->next;
        }

        return true;

    }
};

// 方法一：双指针 - 左右指针
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        while ( head != nullptr ) {
            nums.push_back( head->val );
            head = head->next;
        }

        int left = 0, right = nums.size() - 1;
        while ( left < right ) {
            if ( nums[left] != nums[right] )
                return false;
            ++left, --right;
        }

        return true;
    }
};


int main()
{


    return 0;
}