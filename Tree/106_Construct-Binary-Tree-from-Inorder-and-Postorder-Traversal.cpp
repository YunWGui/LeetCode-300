/*
Title:
	106. Construct Binary Tree from Inorder and Postorder Traversal
	106. 从中序与后序遍历序列构造二叉树
Address:
	https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if ( inorder.size() == 0 || postorder.size() == 0 )
			return nullptr;

		TreeNode* root = new TreeNode(postorder.back());
		vector<int> in_left, in_right;
		vector<int> post_left, post_right;

		size_t count_left = 0;
		for (size_t i = 0; i < inorder.size(); ++i) {
			if (inorder[i] == postorder.back())
				break;
			++count_left;
		}
		// 拆分「后序」遍历
		for (size_t i = 0; i < postorder.size() - 1; ++i ) {
			if (i < count_left)
				post_left.push_back(postorder[i]);
			else
				post_right.push_back(postorder[i]);
		}
		// 拆分「中序」遍历
		for (size_t i = 0; i < inorder.size(); ++i) {
			if (i < count_left)
				in_left.push_back(inorder[i]);
			else if (count_left < i)
				in_right.push_back(inorder[i]);
		}
		// 递归
		root->left = buildTree(in_left, post_left);
		root->right = buildTree(in_right, post_right);

		return root;
	}

	// 用「后序遍历」的方式打印二叉树
	void PrintBinaryTreePostOrder (TreeNode* root){
	    if (root == NULL)
	        return;
		// postOrder
	    PrintBinaryTreePostOrder(root->left);
	    PrintBinaryTreePostOrder(root->right);
	    cout << root->val << " ";
	}
};


int main ()
{
	Solution savle;
    vector<int> in { 9, 3, 15, 20, 7 };
    vector<int> post { 9, 15, 7, 20, 3 };



    TreeNode* root = savle.buildTree(in, post);

    savle.PrintBinaryTreePostOrder(root);
    cout << endl;

    return 0;
}
