/*
Title:
    8. String to Integer (atoi)
    8. 字符串转换整数(atoi)
Address:
    https://leetcode-cn.com/problems/string-to-integer-atoi/
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        int isMinus = false;
        int i =0;
        
        while ( str[i] == ' ' )
            ++i;
        
        if ( str[i] == '-' )
            isMinus = true;
        if ( str[i] == '+' || str[i] == '-' )
            ++i;
        
        while ( i < str.size() && '0' <= str[i] && str[i] <= '9' ) {
            int temp = str[i] - '0';
            if ( num > INT_MAX / 10 || ( num == INT_MAX / 10 && temp > 7 ) ) 
                return isMinus ? INT_MIN : INT_MAX;   
            
            num = num * 10 + temp;
            ++i;
        }

        return isMinus ? -num : num;
    }
};

int main()
{
    

    return 0;
}