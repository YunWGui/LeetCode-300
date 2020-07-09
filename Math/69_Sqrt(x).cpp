/*
Title:
	69. Sqrt(x)
	69. x 的平方根
Address:
	https://leetcode-cn.com/problems/sqrtx/
*/

#include <iostream>
#include <cmath>
using namespace std;

// 方法一：
class Solution {
public:
    int mySqrt(int x) {
        long long int i = 0;
    
        for ( i = 0; i < INT_MAX ; ++i ) {
            if ( i * i <= x && x < ( i + 1 ) * ( i + 1 ) )
                break;
        }

        return i;
    }
};

// 方法二：二分查找
class Solution_2 {
public:
	int mySqrt(int x) {
		int left = 0;
		int right = x;
		int mid;

		if(x <= 1)
			return x;
		while(left < right) {  // [left, right)
			mid = (left + right) >> 1;
			if (x < pow(mid, 2))
				right = mid;
			else
				left = mid + 1;
		}
		return --left;
	}
};

// 方法三：牛顿法
class Solution_3 {
public:
	int mySqrt(int x) {
		double pre;
		if ( x == 0 ) {
			return 0;
		}
		double cur = 1;
		while(true) {
			pre = cur;
			cur = (cur + x / cur) / 2;
			if(abs(pre - cur) < 0.0001)
				return (int)cur;
		}
	}
};



int main()
{
	int x;

	printf("Enter x: ");
	scanf("%d", &x);

	Solution solve;

	cout << solve.mySqrt(x) << endl;

	return 0;
}
