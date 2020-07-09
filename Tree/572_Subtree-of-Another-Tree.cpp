/*
Title:
    572. Subtree of Another Tree
    572. 另一个树的子树
Description:
    Given two non-empty binary trees s and t, check whether tree t has exactly 
    the same structure and node values with a subtree of s. 
    A subtree of s is a tree consists of a node in s and all of this node's 
    descendants. 
    The tree s could also be considered as a subtree of itself.
Address: 
    https://leetcode-cn.com/problems/subtree-of-another-tree/
Tips:
    类似于《剑指offer》 - 26 树的子结构
    https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
*/


#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode ( int x ): val( x ), left( NULL ), right( NULL ) {  }
};

// 方法一：递归
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool res = false;
        
        if ( s != nullptr && t != nullptr ) {
            if ( s->val == t->val )
                res = treeShaveTreeT( s, t );
            
            if ( !res )
                res = isSubtree( s->left, t );
            if ( !res )
                res = isSubtree( s->right, t );
        }

        return res;
    }

    bool treeShaveTreeT( TreeNode* s, TreeNode* t ) {
        if ( s == nullptr && t == nullptr )  //  s, t 同时为空
            return true;
        if ( s == nullptr || t == nullptr )  // s, t 有一不为空，另一为空
            return false;
        if ( s->val != t->val )
            return false;
        
        return treeShaveTreeT( s->left, t->left )
            && treeShaveTreeT( s->right, t->right );
    }
};

int main()
{
    

    return 0;
}