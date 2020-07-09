/*
    53. Maximum Subarray
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for ( int i = 1; i < nums.size(); ++i ) {
            if ( nums[i-1] > 0 )
                nums[i] += nums[i-1];
            // else  // nums[i-1] <= 0, 此外可省略   
            //     nums[i] = nums[i];
            
            res = max( res, nums[i] );
            // if ( res < nums[i] )
            //     res = nums[i];
        }

        return res;
    }
};

// 方法二：滑动窗口
class Solution_2 {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int greatestSum = nums[0];

        for ( size_t i = 1; i < nums.size(); ++i ) {
            if ( curSum <= 0 )
                curSum = nums[i];
            else
                curSum += nums[i];

            if ( greatestSum < curSum )
                greatestSum = curSum;
        }

        return greatestSum;
    }
};


int main()
{
    

    return 0;
}