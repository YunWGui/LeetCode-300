/*
Title:
	42. Trapping Rain Water
	42. 接雨水
Address:
	https://leetcode-cn.com/problems/trapping-rain-water/
Reference:
	https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/
	https://mp.weixin.qq.com/s/f9ebzbwymR8jQeUDxjeCDA
*/


/*
    方法一：暴力法 - 超时
    方法二：「改进」暴力法
    方法三：动态规划
    方法四：单调栈
    方法五：双指针
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 方法四：单调栈 - 栈内元素单调
class Solution_4 {
public:
    int trap (vector<int>& height){
        int res = 0, cur = 0;
        stack<int> S;

        while (cur < height.size()) {
            while (!S.empty() && height[cur] > height[S.top()]) {
                int top = S.top();
                S.pop();
                
                if (S.empty())  break;
                
                int distance = cur - S.top() - 1;
                int bounded_height = min( height[cur], height[S.top()]) - height[top];
                res += distance * bounded_height;
            }
            S.push(cur++);
        }
        return res;
    }
};


// 方法五：双指针
/*
思路：
	在「方法三：动态规划」中，我们用二维数组来存储每个柱子左右两侧的最大高度，但当递推
	累加每个柱子的储水高度时，其实只用到了 dp[i][0] 和 dp[i][1] 两个值。因此，我们递推
	的时候只需要用 leftMax 和 rightMax 两个变量就行了。
	即将上述代码中的递推公式：
		res += min( dp[i][0], dp[i][1] ) - height[i];
	优化成：
		res += min( leftMax, rightMax ) - height[i];
video:
	https://www.youtube.com/watch?v=2LjNzbK2cmA
*/
class Solution_5 {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;

        while ( left < right ) {
            if ( height[left] < height[right] ) {
				leftMax = max( leftMax, height[left] );
				// if ( leftMax < height[left] )
                //     leftMax = height[left];
                res += leftMax - height[left];
                ++left;
            } else {
				rightMax = max( rightMax, height[right] );
                // if ( rightMax < height[right] )
                //     rightMax = height[right];
                res += rightMax - height[right];
                --right;
            }
        }

        return res;
    }
};


// 方法三：动态规划
class Solution_3 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if ( n == 0 )
            return 0;

        vector<vector<int>> dp( 2, vector<int>( n ) );
        dp[0][0] = height[0];
        for ( int i = 1; i < n; ++i )
            dp[0][i] = max( dp[0][i-1], height[i] );

        dp[1][n-1] = height[n-1];
        for ( int i = n - 2; i >= 0; --i )
            dp[1][i] = max( dp[1][i+1], height[i] );

        int res = 0;
        for ( int i = 1; i < n - 1; ++i )
            res += min( dp[0][i], dp[1][i] ) - height[i];

        return res;
    }
};

// 方法二：「改进」暴力法
/*
思路：
	1. 找出整个数组中最高柱子的下标
	2. 计算最高柱子「左侧」的储水量
	3. 计算最高柱子「右侧」的储水量
*/
class Solution_2 {
public:
    int trap(vector<int>& height) {
        int res = 0;
		// 1. 找出整个数组中最高柱子的下标
        int highestIdx = 0;
        for ( int i = 0; i < height.size(); ++i )
            if ( height[highestIdx] < height[i] )
                highestIdx = i;
		// 2. 计算最高柱子「左侧」的储水量
        int prevHigh = 0;
        for ( int i = 0; i < highestIdx; ++i ) {
            if ( prevHigh < height[i] )
                prevHigh = height[i];

            res += prevHigh - height[i];
        }
		// 3. 计算最高柱子「右侧」的储水量
        prevHigh = 0;
        for ( int i = height.size() - 1; highestIdx < i; --i ) {
            if ( prevHigh < height[i] )
                prevHigh = height[i];

            res += prevHigh - height[i];
        }

        return res;
    }
};


// 方法一：暴力法 - 超时
/*
	时间复杂度：O(n^2), 空间复杂度：O(1)
	每根柱子顶部可以储水的高度为：该柱子的左右两侧最大高度的较小者减去此柱子的高度
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int length = height.size();
		// 遍历每个柱子
        for ( int i = 0; i < length - 1; ++i ) {
            int leftMax = 0, rightMax = 0;
			// 计算当前柱子左侧的柱子中的最大高度
            for ( int j = 0; j <= i; ++j ) {
                leftMax = max( leftMax, height[j] );
            }
			// 计算当前柱子右侧的柱子中的最大高度
            for ( int j = i; j < length; ++j ) {
                rightMax = max( rightMax, height[j] );
            }
			// 结果中累加当前柱子顶部可以储水的高度
			// 即：当前柱子左右两边最大高度的较小者 - 当前柱子的高度
            res += min( leftMax, rightMax ) - height[i];
        }

        return res;
    }
};



int main()
{


	return 0;
}
