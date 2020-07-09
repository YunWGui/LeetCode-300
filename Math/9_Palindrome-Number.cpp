/*
Title:
    9. Palindrome Number
    9. 回文数
Description:
    Determine whether an integer is a palindrome. An integer is a palindrome when
    it reads the same backward as forward.
Address:
    https://leetcode-cn.com/problems/palindrome-number/
*/ 

#include <iostream>
#include <string>
using namespace std;

// 方法一：字符串 + 双指针
class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;

        string str = to_string( x );
        
        int left = 0, right = str.size() - 1;
        while ( left < right ) {
            if ( str[left] == str[right] ) {
                ++left;
                --right;
            }
            else 
                return false;
        }

        return true;
    }
};

// 方法二：
class Solution_2 {
public:
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;
        
        int temp = x;
        long rotateNum = 0;  // 避免溢出：如 x = 2147483647
        while ( temp > 0 ) {
            rotateNum = rotateNum * 10 + temp % 10;
            temp /= 10;
        }

        return x == rotateNum;
    }
};


int main()
{
    

    return 0;
}