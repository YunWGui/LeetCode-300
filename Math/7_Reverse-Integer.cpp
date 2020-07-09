/*
Title:  
    7. Reverse Integer
    7. 整数反转
Description:
    Given a 32-bit signed integer, reverse digits of an integer.
Address:
    https://leetcode-cn.com/problems/reverse-integer/
*/

#include <iostream>
using namespace std;

// 方法二：
class Solution_2 {
public:
    int reverse(int x) {
        int num = 0;
        
        while ( x != 0 ) {
            int mod = x % 10;
            x /= 10;
            if ( num > INT_MAX / 10 || ( num == INT_MAX / 10 && mod > 7 ) ) 
                return 0;
            if ( num < INT_MIN / 10 || ( num == INT_MIN / 10 && mod > 8 ) ) 
                return 0;
            num = num * 10 + mod;
        }

        return num;
    }
};

// 方法一：借鉴 LeetCode-8
class Solution {
public:
    int reverse(int x) {
        int num = 0;
        bool isMinus = false;
        if ( x < 0 ) {
            isMinus = true;
            if ( x == INT_MIN )
                return 0;
            x *= -1;
        }

        while ( x > 0 ) {
            int temp = x % 10;
            if ( num > INT_MAX / 10 || ( num == INT_MAX / 10 && temp > 7 ) ) {
                num = 0;
                break;
            }
            num = num * 10 + temp;
            x = x / 10;
        }

        return isMinus ? -num : num;
    }
};

int main()
{
    

    return 0;
}