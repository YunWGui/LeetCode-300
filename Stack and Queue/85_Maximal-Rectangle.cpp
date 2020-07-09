/*
Title:
    85. Maximal Rectangle
    85. 最大矩形
Address:
    https://leetcode-cn.com/problems/maximal-rectangle/
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 方法一：由 LeetCode-84 解法拓展而来
// 同《程序员代码面试指南》9.求最大子矩阵的大小  P30
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if ( matrix.empty() )
            return 0;

        vector<int> heights( matrix[0].size(), 0 );
        int maxArea = 0;

        for ( int row = 0; row < (int)matrix.size(); ++row ) {
            for ( int col = 0; col < (int)matrix[0].size(); ++col )
                heights[col] = ( matrix[row][col] == '0' ) ? 0 : heights[col] + 1;

            maxArea = max( maxArea, largestRectangleArea( heights ) );
        }

        return maxArea;
    }
	// 代码同 LeetCode-84
    int largestRectangleArea( vector<int>& heights ) {
        stack<int> S;  // 单调栈
        int rightIdx;
        int maxArea = 0;

        for ( rightIdx = 0; rightIdx < (int)heights.size(); ++rightIdx ) {
            while ( !S.empty() && heights[ S.top() ] > heights[rightIdx] ) {
                int curIdx = S.top();
                S.pop();
                int leftIdx = S.empty() ? -1 : S.top();
                int curArea = ( rightIdx - leftIdx - 1 ) * heights[curIdx];

                maxArea = max( maxArea, curArea );
            }
            S.push( rightIdx );
        }
        while ( !S.empty() ) {
            int curIdx = S.top();
            S.pop();
            int leftIdx = S.empty() ? -1 : S.top();
            int curArea = ( rightIdx - leftIdx - 1 ) * heights[curIdx];

            maxArea = max( maxArea, curArea );
        }

        return maxArea;
    }
};

int main()
{


	return 0;
}
