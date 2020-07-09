/*
Title:
    125. Valid Palindrome
    125. 验证回文串
Address: 
    https://leetcode-cn.com/problems/valid-palindrome/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 方法一：直觉
class Solution {
public:
    bool isPalindrome(string s) {
        // 将大写转换为小写
        transform( s.begin(), s.end(), s.begin(), ::tolower );

        // 只保留「字母」和「数字」字符
        int j = 0;
        for ( int i = 0; i < s.size(); ++i ) {
            if ( ( 'a' <= s[i] && s[i] <= 'z' ) || ( ( '0' <= s[i] ) && ( s[i] <= '9' ) ) )
                s[j++] = s[i];
        }
        
        s = s.substr( 0, j ); 

        // 判断回文
        int left = 0, right = j - 1;
        while ( left < right ) 
            if ( s[left++] != s[right--] )
                return false;
        
        return true;
    }
};

int main()
{
    

    return 0;
}