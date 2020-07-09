/*
Title:
	102. Binary Tree Level Order traversal
	102. 二叉树的层次遍历
Address:
	https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        queue<TreeNode*> Q;
        TreeNode* p = nullptr;

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
            res.push_back(level);
            level.clear();
        }

        return res;
    }
};

class Solution_2 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> Q;
		vector<int> element;

		if ( root != nullptr )  // 根节点非空
			Q.push(root);

		int currentLevel = 1;  // 当前层中还没有打印的节点数
		int nextLevel = 0;  // 下一层节点的数目

		while ( !Q.empty() ) {  // 队列非空
			TreeNode* x = Q.front();
			Q.pop();
			element.push_back(x->val);
			--currentLevel;

			if ( x->left ) {  // 当前节点存在左节点
				Q.push(x->left);
				++nextLevel;
			}
			if ( x->right ) {  // 当前节点存在右节点
				Q.push(x->right);
				++nextLevel;
			}

			if ( currentLevel == 0 ) {
				res.push_back(element);
				element.clear();  // vector 置空
				currentLevel = nextLevel;
				nextLevel = 0;
			}
		}

		return res;
	}
};

int main()
{


	return 0;
}
