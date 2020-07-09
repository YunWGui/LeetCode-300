/*
Address:
	https://leetcode-cn.com/problems/ugly-number-ii
Title:
	264. Ugly Number II
Description:
	Write a program to find the n-th ugly number.
	Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
	Example:
		Input: n = 10
		Output: 12
		Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first
					10 ugly numbers.
	Note:  
		1 is typically treated as an ugly number.
		n does not exceed 1690.
备注：
    同《剑指offer》49题  P240
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if ( n <= 0 )
            return 0;

        int M2 = 0, M3 = 0, M5 = 0;
        vector<int> nums(n, 1);
        for ( int i = 1; i < n; ++i ) {
            int next2 = nums[M2] * 2;
            int next3 = nums[M3] * 3;
            int next5 = nums[M5] * 5;

            nums[i] = std::min( next2, std::min(next3, next5) );

            if ( nums[i] == next2 )
                ++M2;
            if ( nums[i] == next3 )
                ++M3;
            if ( nums[i] == next5 )
                ++M5;
        }

        return nums[n-1];
    }
};

int main()
{


	return 0;
}
