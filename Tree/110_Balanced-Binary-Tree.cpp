/*
Title:
	110. Balanced Binary Tree
	110. 平衡二叉树
Address:
	https://leetcode-cn.com/problems/balanced-binary-tree/

备注：
	同《剑指offer》第55_2 题
    https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
    《程序员代码面试指南》
    https://www.nowcoder.com/practice/380d49d7f99242709ab4b91c36bf2acc?tpId=101
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;

        return IsBalanced( root, depth );
    }

    bool IsBalanced( TreeNode* root, int& depth ) {
        if ( root == nullptr ) {
            depth = 0;
            return true;
        }

        int left, right;
        if ( IsBalanced( root->left, left ) && IsBalanced( root->right, right ) ) {
            if ( abs( left - right ) <= 1 ) {
                depth = 1 + max( left, right );
                return true;
            }
        }

        return false;
    }
};

int main()
{


	return 0;
}
