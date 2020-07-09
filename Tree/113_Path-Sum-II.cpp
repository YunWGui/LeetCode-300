/*
题目：
	113. Path Sum II
	113. 路径总和 II
地址：
	https://leetcode-cn.com/problems/path-sum-ii/
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

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        int currentSum = 0;

        if ( root != nullptr )
            _pathSum(root, sum, path, currentSum, res);

        return res;
    }

    void _pathSum(TreeNode* root, int sum, vector<int>& path, int currentSum, vector<vector<int>>& res) {
        currentSum += root->val;
        path.push_back(root->val);

        bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
        if ( currentSum == sum && isLeaf )
            res.push_back(path);

        if ( root->left != nullptr )
            _pathSum(root->left, sum, path, currentSum, res);
        if ( root->right != nullptr )
            _pathSum(root->right, sum, path, currentSum, res);

        path.pop_back();
    }
};

int main()
{


	return 0;
}
