/*
Title:
    84. Largest Rectangle in Histogram
    84. 柱状图中最大的矩形
Address:
    https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


// 方法一：单调栈 - 栈顶(大) --> 栈底(小)
/* 时间复杂度：O(n)，空间复杂度：O(n) */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		if ( heights.empty() )
			return 0;
			
        stack<int> S;  // 构造一个「单调栈」，存放「下标」，栈顶(大) --> 栈底(小)
        int maxArea = 0;
        int rightIdx;  // 右边界

        for ( rightIdx = 0; rightIdx < (int)heights.size(); ++rightIdx ) {
            while ( !S.empty() && heights[ S.top() ] > heights[rightIdx] ) {
                int curIdx = S.top();  // 当前所求的值的「下标」
                S.pop();
                int leftIdx = S.empty() ? -1 : S.top();  // 左边界
                int curArea = ( rightIdx - leftIdx - 1 ) * heights[curIdx];

                maxArea = max( maxArea, curArea );
            }
            S.push( rightIdx );  // 下标入栈
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
    // vector<int> vec { 0, 9 };
    // vector<int> vec { 2, 1, 5, 6, 2, 3};
    vector<int> vec { 3, 2, 1, 1, 1, 1, 2, 3 };
    Solution solve;
    cout << solve.largestRectangleArea( vec );


    return 0;
}
