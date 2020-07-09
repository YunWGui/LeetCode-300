/*
	94. Binary Tree Inorder Traversal
    94. 二叉树的中序遍历
Address:
    https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
*/


#include <iostream>
#include <vector>
#include <stack>
// #include <mypkg/print.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};


// 方法三： Morris 遍历
class Solution_3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    cur = cur->left;
                    continue;
                }
                else 
                    mostRight->right = nullptr;
            }
            res.emplace_back( cur->val );
            cur = cur->right;
        }

        return res; 
    }
};

// 方法一：递归
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> temp;

		InOrder(root, temp);

		return temp;
	}
	void InOrder(TreeNode* root, vector<int>& temp) {
		if (root == nullptr)
		// if( !root )
			return;
		InOrder(root->left, temp);
		temp.push_back(root->val);
		InOrder(root->right, temp);
	}
};

// 方法二：迭代
class Solution_2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        TreeNode* curNode = root;
        vector<int> res;

        while ( true ) {  // 从当前节点出发，沿左分支不断深入，直至没有左分支的节点
            while ( curNode ) {
                S.push( curNode );
                curNode = curNode->left;
            }

            if ( S.empty() )  // 所有节点访问完毕
                break;
            
            curNode = S.top(); S.pop();
            
            res.push_back( curNode->val );  // 访问

            curNode = curNode->right;  // 转向右子树
        }

        return res;
    }
};

class Solution_3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> temp;
        vector<int> res;

        while( true ) {
            if ( root ) {
                temp.push(root);
                root = root->left;
            } else if ( !temp.empty() ) {
                root = temp.top();
                temp.pop();
                res.push_back(root->val);
                root = root->right;
            } else 
                break;
        }        
        return res;
    }
};


int main()
{
	// PreOrder : 5, 3, 2, 4, 8, 7, 6, 10, 9, 11
	// InOrder : 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
	// PostOrder : 2, 4, 3, 6, 7, 9, 11, 10, 8, 5
    TreeNode* head = new TreeNode(5);
    head->left = new TreeNode(3);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(2);
    head->left->right = new TreeNode(4);
    head->right->left = new TreeNode(7);
    head->right->right = new TreeNode(10);
    head->right->left->left = new TreeNode(6);
    head->right->right->left = new TreeNode(9);
    head->right->right->right = new TreeNode(11);

	Solution solve;

	// print(solve.inorderTraversal(head));
	

	Solution_2 solve_2;

	// print(solve_2.inorderTraversal(head));


	return 0;
}
