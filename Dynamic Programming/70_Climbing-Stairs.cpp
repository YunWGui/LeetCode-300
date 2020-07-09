/*
    70. Climbing Stairs
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划
// 解法类似于「斐波拉契数列」求值
class Solution {
public:
    int climbStairs(int n) {
        if ( n < 0 )
            return -1;
        if ( n == 0 )
            return 1;
        
        int step1 = 1;
        int step2 = 1;
        int dp = 1;  // 当 n == 1
        for ( int i = 2; i <= n; ++i ) {
            dp = step1 + step2;
            step1 = step2;
            step2 = dp;
        }

        return dp;    
    }
};

int main()
{
    

    return 0;
}