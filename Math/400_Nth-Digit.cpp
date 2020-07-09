/*
Title:
	400. Nth Digit
    400. 第N个数字
Description:
    Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
    Note:
        n is positive and will fit within the range of a 32-bit signed integer (n < 231).
Address:
    https://leetcode-cn.com/problems/nth-digit/
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, nums = 9;

        --n;
        while ( true ) {
            if ( n > len*nums )
                n -= len * nums;
            else
                break;

            ++len;
            nums *= 10;
        }
        int val = pow(10, len-1) + n / len;
        string tem = to_string( val );

        return tem[n % len] - '0';
    }
};

int main()
{


	return 0;
}
