/*
Title:
    233. Number of Digit One
    233. 数字 1 的个数
Address:
    https://leetcode-cn.com/problems/number-of-digit-one/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;

        for ( long long i = 1; i <= n; i *= 10 ) {
            long long divider = i * 10;
            count += (n / divider) * i + min( max(n % divider - i + 1, 0LL), i);
        }

        return count;
    }
};

int main()
{
    

    return 0;
}