/*
Title:
    152. Maximum Product Subarray
    152. 乘积最大子数组
Address: 
    https://leetcode-cn.com/problems/maximum-product-subarray/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法一：动态规划
/* 时间复杂度：O(n)  空间复杂度：O(1) */
// https://leetcode-cn.com/problems/maximum-product-subarray/solution/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = INT_MIN;  // 全局最大值
        int curMaxVal = 1;  // 当前最大值
        int curMinVal = 1;  // 当前最小值

        for ( int i = 0; i < (int)nums.size(); ++i ) {
            if ( nums[i] < 0 )  // 出现负数，交换当前最大值与当前最小值
                swap( curMaxVal, curMinVal );
            
            curMinVal = min( curMinVal * nums[i], nums[i] );
            curMaxVal = max( curMaxVal * nums[i], nums[i] );
            
            maxVal = max( maxVal, curMaxVal );
        }

        return maxVal;
    }
};


int main()
{
    

    return 0;
}