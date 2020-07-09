/*
Title:
    65. Valid Number
    65. 有效数字
Address:
    https://leetcode-cn.com/problems/valid-number/
Tips:
    同《剑指offer》20 题
    https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 数字的格式可以用 A[.[B]][e|EC] 或者 .B[e|EC] 表示，其中 A 和 C 都是
    // 整数（可以有正负号，也可以没有），而 B 是一个无符号整数
    bool isNumber(string s) {
        if ( s.empty() )
            return 0;
        
        int i = 0;
        while ( s[i] == ' ' )  // 忽略段前空格
            ++i;

        bool isValidNumber = scanInteger( s , i );

        if ( s[i] == '.' ) {
            ++i;
            // 在小数里，可能没有数值的整数部分，因此 A 部分不是必需的
            // 1. 小数可以没有整数部分，如 .123 == 0.123；
            // 2. 小数点后面可以没有数字，如 233. == 233.0；
            // 3. 小数点前面和后面可以都数字，如 233.666
            isValidNumber = scanUnsignedInteger( s, i ) || isValidNumber;
        }

        if ( s[i] == 'e' || s[i] == 'E' ) {
            ++i;
            // 下面一行代码用 && 的原因：
            // 1. 不 e or E 前面没有数字时，整个字符串不能表示数字，如 .e1, e1；
            // 2. 当 e or E 后面没有整数时，整个字符串不能表示数字，如 12e、12e+5.4
            isValidNumber = isValidNumber && scanInteger( s, i );
        }

        while ( s[i] == ' ' )  // 忽略段后空格
            ++i;

        return isValidNumber && i == s.size();
    }

    bool scanInteger( const string& s, int& i ) {
        if ( s[i] == '-' || s[i] == '+' )
            ++i;
        
        return scanUnsignedInteger( s, i );
    }

    bool scanUnsignedInteger( const string& s, int& i ) {
        int temp = i;
        while ( i < s.size() && '0' <= s[i] && s[i] <= '9' )
            ++i;
        
        return i > temp;
    }
};


int main()
{


	return 0;
}
