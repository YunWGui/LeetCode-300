/*
Title:
	100. Same Tree
	100. 相同的树
Address:
	https://leetcode-cn.com/problems/same-tree/
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
			return true;
		if (p == nullptr || q == nullptr || (q->val != p->val))
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};


int main()
{


	return 0;
}
