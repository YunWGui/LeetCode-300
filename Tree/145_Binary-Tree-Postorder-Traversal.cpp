/*
Title:
    145. Binary Tree Postorder Traversal
    145. 二叉树的后序遍历
Address: 
    https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {  }
};

// 方法一：Morris 遍历 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( root == nullptr )
            return res;
        
        TreeNode* cur = root;
        TreeNode* mostRight = nullptr;

        while ( cur ) {
            if ( cur->left ) {
                mostRight = cur->left;
                while ( mostRight->right && mostRight->right != cur ) 
                    mostRight = mostRight->right;
                
                if ( mostRight->right == nullptr ) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }
                else {
                    mostRight->right = nullptr;
                    travRightEdge( cur->left, res );
                }
            }
            cur = cur->right;
        }
        travRightEdge( root, res );

        return res;
    }
    
    void travRightEdge( TreeNode* root, vector<int>& res ) {
        TreeNode* tail = reverseEdge( root );
        TreeNode* cur = tail;
        
        while ( cur ) {
            res.emplace_back( cur->val );
            cur = cur->right;
        }
        reverseEdge( tail );
    }

    TreeNode* reverseEdge( TreeNode* cur ) {
        TreeNode* next = nullptr;
        TreeNode* pre = nullptr;

        while ( cur ) {
            next = cur->right;

            cur->right = pre;
            
            pre = cur;
            cur = next;
        }

        return pre;
    }
};


// 方法二：迭代
class Solution_2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S1, S2;
        vector<int> res;

        if ( root )
            S1.push( root );

        while ( !S1.empty() ) {
            TreeNode* curNode = S1.top(); S1.pop();

            S2.push( curNode );

            if ( curNode->left )
                S1.push( curNode->left );
            if ( curNode->right )
                S1.push( curNode->right );
        }

        while ( !S2.empty() ) {
            res.emplace_back( S2.top()-> val );
            S2.pop();
        }

        return res;
    }
};

// 方法三：迭代 —— 只使用一个栈
class Solution_3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( root == nullptr )
            return res;
        
        stack<TreeNode*> S1;
        S1.push( root );
        while ( !S1.empty() ) {
            root = S1.top();  S1.pop();
            res.push_back( root->val );

            if ( root->left )
                S1.push( root->left );
            if ( root->right )
                S1.push( root->right );
        }

        reverse( res.begin(), res.end() );

        return res;
    }
};


int main()
{
    

    return 0;
}