/*
Title:
    53. Maximum Subarray
    53. 最大子序和
Address: 
    https://leetcode-cn.com/problems/maximum-subarray/
Tips:
    同《剑指offer》- 42 题
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];

        for ( int i = 1; i < (int)nums.size(); ++i ) {
            if ( nums[i - 1] > 0 )
                nums[i] += nums[i - 1];
            // else  // nums[i] <= 0
            //     nums[i] = nums[i];

            // maxSum = max( maxSum, nums[i] );
            if ( maxSum < nums[i] )
                maxSum = nums[i];
        }

        return maxSum;
    }
};

// 方法二：滑动窗口
class Solution_2 {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int maxSum = nums[0];

        for ( size_t i = 1; i < nums.size(); ++i ) {
            if ( curSum  < 0 )
                curSum = nums[i];
            else
                curSum += nums[i];

            maxSum = max( maxSum, curSum );
        }

        return maxSum;
    }
};


int main()
{
    

    return 0;
}