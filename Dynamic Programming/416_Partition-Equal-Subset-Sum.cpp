/*
Title:
    416. Partition Equal Subset Sum
Address:
	https://leetcode-cn.com/problems/partition-equal-subset-sum/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划 - 背包问题的变种
// https://mp.weixin.qq.com/s/OzdkF30p5BHelCi6inAnNg
/*
思路：
    先对集合求和，得出 sum ，然后把问题转化为「背包问题」，即：
        给一个可装载重量为 sum / 2 的背包和 N 个物品，每个物品的重量为 nums[i]。
        现在装物品，是否存在一种装法，能够恰好将背包装满？
*/
class Solution {
    // 输入一个集合，返回是否能够分割成和相等的两个子集
    bool canPartition( vector<int>& nums ) {
        int sum = 0;
        for ( int num : nums ) sum += num;
        // 和为「奇数」时，不可能划分成两个和相等的集合
        if ( sum % 2 != 0 )  return false;

        int n = nums.size();
        sum >>= 1;
        vector<vector<bool>> dp( n + 1, vector<bool>( sum + 1, false ) );
        // base case
        for ( int i = 0; i <= n; ++i )
            dp[i][0] = true;

        for ( int i = 1; i <= n; ++i ) {
            for ( int j = 1; j <= sum; ++j ) {
                if ( j - nums[i - 1] < 0 )
                    // 背包容量不足，不能装入第 i 个物品
                    dp[i][j] = dp[i-1][j];
                else
                    // 装入或不装入背包
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
            }
        }

        return dp[n][sum];
    }

    bool canPartition_2( vector<int>& nums ) {
        int sum = 0, n = nums.size();

        for ( int num : nums )  sum += num;
        if ( sum % 2 != 0 )  return false;

        sum >>= 1;
        vector<bool> dp(sum + 1, false );
        // base case
        dp[0] = true;

        for ( int i = 0; i < n; ++i )
            for ( int j = sum; j >= 0; --j )
                if ( j - nums[i] >= 0 )
                    dp[j] = dp[j] || dp[j - nums[i]];

        return dp[sum];
    }
};


int main()
{


    return 0;
}
