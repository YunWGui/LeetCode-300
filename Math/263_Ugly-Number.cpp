/*
Title:
    263. Ugly Number
    263. 丑数
Description:
    Write a program to check whether a given number is an ugly number.
    Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
Address:
    https://leetcode-cn.com/problems/ugly-number/
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if ( num <= 0 )
            return false;
            
        bool flag = false;

        while ( num % 2 == 0 )
            num /= 2;
        while ( num % 3 == 0 )
            num /= 3;
        while ( num % 5 == 0 )
            num /= 5;

        return 1 == num ? true : false;        
    }
};

int main()
{
    

    return 0;
}