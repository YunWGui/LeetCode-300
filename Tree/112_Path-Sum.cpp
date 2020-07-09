/*
题目：
	112. Path Sum
    112. 路径总和
地址：
	https://leetcode-cn.com/problems/path-sum/
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

class Solution_1 {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        return _hasPathSum(root, sum, 0);
    }

    bool _hasPathSum(TreeNode* root, int sum, int currentSum) {
        if ( root == nullptr )  // 当前节点为「空节点」
            return false;
        currentSum += root->val;
        if ( !root->left && !root->right )  // 当前节点为「叶节点」
            return currentSum == sum;

        return _hasPathSum(root->left, sum, currentSum)
			|| _hasPathSum(root->right, sum, currentSum);
    }
};

class Solution_2 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if ( root == nullptr )  // 空节点
            return false;
        if ( root->left == nullptr && root->right == nullptr && sum == (root->val))
            return true;

        return hasPathSum(root->left, sum - (root->val))
            || hasPathSum(root->right, sum - (root->val));
    }
};

class Solution_3 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        vector<int> path;
        int currentSum = 0;
        bool isSum = false;

        if ( root != nullptr )
            _hasPathSum(root, sum, path, currentSum, isSum);

        return isSum;
    }

    void _hasPathSum(TreeNode* root, int sum, vector<int>& path, int currentSum, bool& isSum) {
        currentSum += root->val;
        path.push_back(root->val);

        bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
        if ( currentSum == sum && isLeaf )
            isSum = true;

        if ( root->left != nullptr )
            _hasPathSum(root->left, sum, path, currentSum, isSum);
        if ( root->right != nullptr )
            _hasPathSum(root->right, sum, path, currentSum, isSum);

        path.pop_back();
    }
};

int main()
{


	return 0;
}
