/*
Title:
    191. Number of 1 Bits
    191. 位1的个数
Address: 
    https://leetcode-cn.com/problems/number-of-1-bits/
*/

#include <iostream>
using namespace std;


// 方法一：位运算
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while ( n > 0 ) {
            if ( n & 1 )
                ++count;
            n >>= 1;
        }

        return count;
    }
};

// 方法二：位运算
class Solution_2 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while ( n ) {
            ++count;
            n = n & ( n - 1 );
        }

        return count;
    }
};


int main()
{
    

    return 0;
}