/*
Title:
    104. Maximum Depth of Binary Tree
    104. 二叉树的最大深度
Address:
    https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
备注：
	同《剑指offer》- 55 题
*/

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if ( !root )
            return 0;

		int left = maxDepth( root->left );
		int right = maxDepth( root->right );

        return 1 + ( left > right ? left : right );
    }
};

int main()
{

    return 0;
}
