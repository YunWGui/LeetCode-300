/*
Title:
    144. Binary Tree Preorder Traversal
    144. 二叉树的前序遍历
Address: 
    https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    vector<int> preorderTraversal(TreeNode* root) {
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
                    res.emplace_back( cur->val );
                    cur = cur->left;
                    continue;
                }
                else 
                    mostRight->right = nullptr;
            }
            else 
                res.emplace_back( cur->val );

            cur = cur->right;
        }

        return res;
    }
};


// 方法二：迭代版
// 《数据结构·邓俊辉》 P127
class Solution_2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( root == nullptr )
            return res;
        
        TreeNode* curNode = root;
        stack<TreeNode*> S;
        while ( true ) {
            // visitAlongLeftBranch( res, curNode, S );
            while ( curNode ) {  // 类似于前序遍历的递归版
                res.push_back( curNode->val );
                S.push( curNode->right );
                curNode = curNode->left;
            }

            if ( S.empty() )
                break;
            
            curNode = S.top(); S.pop();
        }

        return res;
    }

    // void visitAlongLeftBranch( vector<int>& res, TreeNode* curNode, stack<TreeNode*>& S ) {
    //     while ( curNode ) {  // 类似于前序遍历的递归版
    //         res.push_back( curNode->val );
    //         S.push( curNode->right );
    //         curNode = curNode->left;
    //     }
    // }
};

int main()
{
    

    return 0;
}