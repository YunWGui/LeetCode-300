/*
Title:
    138. Copy List with Random Pointer
    138. 复制带随机指针的链表
Address: 
    https://leetcode-cn.com/problems/copy-list-with-random-pointer/
Tips:
    同《剑指 Offer·35》 

    参考《程序员代码面试指南·第 2 版》 2.9 复制含有随机指针节点的链表  P63     
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// 方法一：哈希表
/* 时间复杂度：O(n)  额外空间复杂度：O(n) */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( head == nullptr )
            return head;

        unordered_map<Node*, Node*> hashMap;
        Node* curNode = head;

        // 将节点放入哈希表
        while ( curNode != nullptr ) {
            hashMap.insert( make_pair( curNode, new Node( curNode->val ) ) );
            curNode = curNode->next;
        }

        // 连接存储在哈希表中的节点，next 指针与 random 指针
        curNode = head;
        while ( curNode != nullptr ) {
            hashMap[curNode]->next = hashMap[curNode->next];
            hashMap[curNode]->random = hashMap[curNode->random];
            curNode = curNode->next;
        }

        return hashMap[head];
    }
};


// 方法二：原地解法，不使用额外空间
/* 时间复杂度：O(n)  额外空间复杂度：O(1) 
思路：
    1. 从左到右遍历链表，对每个节点 curNode 都复制生成相应的副本节点 curDupNode，
       然后把 curDupNode 放在 curNode 和下一个要遍历节点的中间
       例：1->2->3->NULL ==> 1->1'->2->2'->3->3'->NULL
    2. 再次从左到右遍历链表，在遍历时设置每一个副本节点的 random 指针。
    3. 分离「原节点」与「副本节点」
参考：
    《程序员面试指南·第2版》 P65
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( head == nullptr )
            return nullptr;
        
        Node* curNode = head;
        Node* nextNode = nullptr;

        while ( curNode ) {
            nextNode = curNode->next;
            curNode->next = new Node( curNode->val );
            curNode->next->next = nextNode;
            curNode = nextNode;
        }

        curNode = head;
        Node* curDupNode = nullptr;  // 当前节点的重复节点
        // 设置复制节点的 random 指针
        while ( curNode ) {
            nextNode = curNode->next->next;
            curDupNode = curNode->next;
            if ( curNode->random ) {
                curDupNode->random = curNode->random->next;
            }
            curNode = nextNode;
        }

        Node* newHead = head->next;
        curNode = head;
        // 拆分链表
        while ( curNode ) {
            nextNode = curNode->next->next;
            curDupNode = curNode->next;
            curNode->next = nextNode;

            // 一定要判断：当 nextNode == nullptr, nextNode->next 无意义，会报错
            curDupNode->next = ( nextNode != nullptr ) ? nextNode->next : nullptr; 

            curNode = nextNode;
        }

        return newHead;
    }
};


int main()
{
    

    return 0;
}