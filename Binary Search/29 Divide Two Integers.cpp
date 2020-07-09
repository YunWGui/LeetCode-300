// Given two integers dividend and divisor, divide two integers without using
// multiplication, division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero.

// Note:
//
// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers
// within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of
// this problem, assume that your function
// returns 2^31 − 1 when the division result 「overflows」.


#include<iostream>
using namespace std;


// 执行用时：0 ms， 击败 100.00 % 用户
class Solution {
public:
    int divide(int dividend, int divisor){
		if(dividend == 0)  return 0;
		if(dividend == INT_MIN && divisor == -1)  return INT_MAX;
		if(dividend == INT_MIN && divisor == 1)  return INT_MIN;
		int res = 0;
		long long dvd = abs((long long)dividend);
		long long dvs = abs((long long)divisor);
		long long dvs_bk = dvs;

		while(dvd >= dvs){
			int curr = 1;
			dvs <<= 1;
			while(dvd - dvs >= 0){
				curr *= 2;
				dvs <<= 1;
			}
			dvs >>= 1;
			dvd -= dvs;
			dvs = dvs_bk;
			res += curr;
		}
		if(dividend > 0 && divisor < 0)
			res *= -1;
		else if(dividend < 0 && divisor > 0)
			res *= -1;

		return res;
    }
};


int main()
{
	Solution s;
	cout << s.divide(10, 3) << endl;
	cout << s.divide(-7, 3) << endl;
	cout << s.divide(-2147483648, -1) << endl;
	cout << s.divide(-2147483647, -1) << endl;


	return 0;
}
