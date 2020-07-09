/*
Title :
	98. Validate Binary Search Tree
	98. 验证二叉搜索树
Address:
	https://leetcode-cn.com/problems/validate-binary-search-tree/
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};

// 蛮力
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if ( root == nullptr)
            return true;

        vector<int> test;
        InOrder(root, test);

        for ( size_t i = 0; i < test.size() - 1; ++i )
            if ( test[i] >= test[i + 1])
				return false;
        return true;
    }
	void InOrder(TreeNode* x, vector<int>& test) {
		if ( x == nullptr )
			return;

		InOrder(x->left, test);
		test.push_back(x->val);
		InOrder(x->right, test);
	}
};

int main()
{


	return 0;
}
