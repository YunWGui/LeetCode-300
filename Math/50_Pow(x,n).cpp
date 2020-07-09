/*
Title:
    50. Pow(x, n)
Description:
    Implement pow(x, n), which calculates x raised to the power n (xn).
Address:  
    https://leetcode-cn.com/problems/powx-n/
Tips:
    同《剑指offer》第16题  P110
    https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
*/

#include <iostream>
using namespace std;

// 方法二：快速幂 + 迭代
class Solution_2 {
public:
    double myPow(double x, int n) {
        
        double res = pow_iter( x, long( abs( n ) ) );

        return n > 0 ? res : 1.0 / res;
    }

    double pow_iter( double x, long n ) {
        double ans = 1.0;

        while ( n ) {
            if ( n & 1 ) {
                ans = ans * x;
            }
            x = x * x;
            n >>= 1;
        }

        return ans;
    }
};


// 方法一：快速幂 + 递归
class Solution {
public:
    double myPow(double x, int n) {
        if ( x == double(0.0) )
            return x;
        if ( n == 0 )
            return double(1.0);

        double res = Power( x, abs( long(n) ) );
        
        return n > 0 ? res : 1.0 / res;
    }

    double Power( double x, long long n ) {
        if ( n == 1 )
            return x;
        
        double res = Power( x, n>>1 );

        res *= res;
        if ( (n & 1) == 1 )
            res *= x;
        
        return res;        
    }
};

int main()
{
    

    return 0;
}