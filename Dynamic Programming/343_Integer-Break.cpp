/*
    343. Integer Break

Note:
    同《剑指offer》第 14 题，P96
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int integerBreak(int n) {
        if ( n < 2 )
            return 0;
        if ( n == 2 )
            return 1;
        if ( n == 3 )
            return 2;
        
        vector<int> res( n+1, 0 );
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;
        res[3] = 3;

        for ( int i = 4; i < n+1; ++i ) {
            int maxVal = 0;
            for ( int j = 1; j <= i/2; ++j ) {
                int val = res[j] * res[i-j];
                if ( maxVal < val )
                    maxVal = val;
            }
            res[i] = maxVal;
        }

        return res[n];        
    }
};

// 方法二：贪心
// 思路：当 n >= 5 时，尽可能多地剪长度为 3 的绳子。
class Solution_2 {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        if (n==3) return 2;
        int ans = 1;
        while(n>4){
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};

int main()
{
    

    return 0;
}