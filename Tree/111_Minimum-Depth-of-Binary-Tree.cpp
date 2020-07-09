/*
Title:
	111. Minimum Depth of Binary Tree
    111. 二叉树的最小深度
Address:
	https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
*/


#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};


// 方法三：BFS - 广度优先搜索
class Solution_3 {
public:
    int minDepth(TreeNode* root) {
        if ( root == nullptr )
            return 0;
        
        int depth = 1;
        queue<TreeNode*> Q;
        Q.push( root );

        while ( !Q.empty() ) {
            int size = Q.size();
            for ( int i = 0; i < size; ++i ) {
                TreeNode* temp = Q.front();
                Q.pop();

                if ( temp->left == nullptr && temp->right == nullptr )
                    return depth;
                if ( temp->left )
                    Q.push( temp->left );
                if ( temp->right )
                    Q.push( temp->right );
            }
            ++depth;
        }

        return depth;
    }
};

// 方法一：
class Solution {
public:
    int minDepth(TreeNode* root) {
        if ( root == nullptr )
            return 0;
            
        int nLeft = minDepth( root->left );
        int nRight = minDepth( root->right );

        // 处理只有左、右子树或是叶子点的情况
        if ( root->left == nullptr || root->right == nullptr )
            return nLeft + nRight + 1;

        return 1 + min(nLeft, nRight);
    }
};

// 方法二:
class Solution_2 {
public:
    int minDepth(TreeNode* root) {
        if ( root == NULL )  // 空树
            return 0;
        else if ( root->left == NULL && root->right == NULL)  // 左右子树都为空，叶子节点
            return 1;
        else if ( root->left == NULL )  // 若左子树为空，则最小深度为右子树的最小深度 + 1
            return 1 + minDepth( root->right );
        else if ( root->right == NULL )  // 若右子树为空，则最小深度为左子树的最小深度 + 1
            return 1 + minDepth( root->left );
		// 否则（即左右子树都不为空），最小深度是：min ( 1 + 左子树最小深度，1 + 右子树最小深度)
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};


int main()
{


	return 0;
}
