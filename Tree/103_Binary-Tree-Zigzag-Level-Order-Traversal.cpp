/*
题目：
	103. Binary Tree Zigzag Level Order traversal
    103. 二叉树的锯齿形层次遍历
地址：
	https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
*/


#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        queue<TreeNode*> Q;
        TreeNode* p = nullptr;
        bool left_to_right = true;

        if ( root )
            Q.push(root);

        while ( !Q.empty() ) {
            for ( size_t i = Q.size(); i > 0; --i ) {
                p = Q.front();
                Q.pop();
                level.push_back(p->val);

                if ( p->left )
                    Q.push(p->left);
                if ( p->right )
                    Q.push(p->right);
            }
            if ( !left_to_right)
                reverse(level.begin(), level.end());
            left_to_right = !left_to_right;
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};


int main()
{


	return 0;
}
