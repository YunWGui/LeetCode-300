/*
Title:
    67. Add Binary
    67. 二进制求和
Description:
    Given two binary strings, return their sum (also a binary string).
    The input strings are both non-empty and contains only characters 1 or 0.
Address: 
    https://leetcode-cn.com/problems/add-binary/
*/

#include <iostream>
#include <string>
using namespace std;

// 方法一：
class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size();

        // 补位，使两个字符串一样长
        while ( aLen > bLen ) {
            b = '0' + b;  // str += "123"  <==> str = str + "123";
            ++bLen;
        }
        while ( bLen > aLen ) {
            a = '0' + a;
            ++aLen;
        }

        int carry = 0;  // 进位标志位
        for ( int i = aLen - 1; i >= 0; --i ) {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = sum % 2 + '0';  // 本位数值
            carry = sum / 2;  // 进位更新
        }

        if ( carry > 0 )  // 有溢出
            a = '1' + a;
        
        return a;

    }
};

// 方法二：
class Solution_2 {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size();
        
        string temp( abs( aLen - bLen ), '0' );
        // str += "123"  <==> str = str + "123";
        ( aLen > bLen ) ? ( b = temp + b ) : ( a = temp + a );
        
        int carry = 0;  // 进位标志位
        for ( int i = a.size() - 1; i >= 0; --i ) {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = sum % 2 + '0';
            carry = sum / 2;
        }

        if ( carry > 0 )  // 有溢出
            a = '1' + a;
        
        return a;

    }
};

int main()
{

    string a = "1", b = "111";
    Solution solve;
    cout << solve.addBinary( a, b );
    

    return 0;
}