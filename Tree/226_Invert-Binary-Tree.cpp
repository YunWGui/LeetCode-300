/*
    Title:
        226. Invert Binary Tree
        226. 翻转二叉树
    Address:
        https://leetcode-cn.com/problems/invert-binary-tree/
    备注：
        同《剑指offer》27题
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};

// 方法一：递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if ( root == nullptr )
            return nullptr;
        
        // 「前序」遍历
        swap( root->left, root->right );
        invertTree( root->left );
        invertTree( root->right );

        return root;
    }
};


// 方法二：迭代版
class Solution_2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if ( !root )
            return nullptr;
        
        queue<TreeNode*> Q;
        Q.push( root );
        while ( !Q.empty() ) {
            TreeNode* temp = Q.front();
            Q.pop();
            
            swap( temp->left, temp->right );

            if ( temp->left )
                Q.push( temp->left );
            if ( temp->right )
                Q.push( temp->right );
        }

        return root;
    }
};

int main()
{
    

    return 0;
}
