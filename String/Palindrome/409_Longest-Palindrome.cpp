/*
Title:
    409. Longest Palindrome
    409. 最长回文串
Description:
    Given a string which consists of lowercase or uppercase letters, find the 
    length of the longest palindromes that can be built with those letters.
    This is case sensitive, for example "Aa" is not considered a palindrome here.
    Note: Assume the length of given string will not exceed 1,010.
Address: 
    https://leetcode-cn.com/problems/longest-palindrome/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 方法一：哈希表
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> M;
        bool haveOdd = false;
        int maxLen = 0;

        for ( char ch : s )
            ++M[ch];

        for ( auto iter = M.begin(); iter != M.end(); ++iter ) {
            if ( iter->second % 2 == 0 )  // 偶数个字符
                maxLen += iter->second;
            else {  // 奇数个字符
                haveOdd = true;
                maxLen += iter->second - 1;
            }
        }

        return haveOdd ? maxLen + 1 : maxLen;
    }
};


// 方法二：哈希表
class Solution_2 {
public:
    int longestPalindrome(string s) {
        if ( s.empty() )
            return 0;
        
        int char_map[128] = { 0 };  // 置 0 
        for ( char ch : s )
            ++char_map[ch];
        
        int maxLen = 0;
        int haveOdd = 0;
        for ( int i = 0; i < 128; ++i ) {
            if ( char_map[i] % 2 == 0 )
                maxLen += char_map[i];
            else {
                haveOdd = 1;
                maxLen += char_map[i] - 1;
            }
        }

        return maxLen + haveOdd;
    }
};

int main()
{
    

    return 0;
}