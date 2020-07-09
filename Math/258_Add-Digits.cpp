/*
Title:
    258. Add Digits
    258. 各位相加
Description:
    Given a non-negative integer num, repeatedly add all its digits until the 
    result has only one digit.
Address:
    https://leetcode-cn.com/problems/add-digits/
*/

#include <iostream>
using namespace std;

// 方法三：数学
class Solution_3 {
public:
    int addDigits(int num) {
        return ( num - 1 ) % 9 + 1;
    }
};

// 方法一：
class Solution {
public:
    int addDigits(int num) {
        while ( num > 9 ) {
            int temp = 0;
            while ( num > 0 ) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }

        return num;
    }
};

// 方法二：数学
class Solution_2 {
public:
    int addDigits(int num) {
        if ( num == 0 )
            return 0;

        return num % 9 == 0 ? 9 : num % 9;
    }
};



int main()
{


    return 0;
}
