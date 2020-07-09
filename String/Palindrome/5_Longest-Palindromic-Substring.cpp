/*
Title:
    5. Longest Palindromic Substring
    5. 最长回文子串
Address:
    https://leetcode-cn.com/problems/longest-palindromic-substring/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// 方法三：不懂
class Solution_3 {
  public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;

        int n = s.size(), maxLen = 0, start = 0;

        for (int i = 0; i < n; ) {
            if (n - i <= maxLen / 2)
                break;

            int left = i, right = i;
            while (right < n - 1 && s[right + 1] == s[right])
                ++right;

            i = right + 1;
            while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            
            if (maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};

// 方法一：双指针
// 参考：https://mp.weixin.qq.com/s/ux6VSWAPwgOS32xlScr2kQ
/* 时间复杂度：O(N^2)，空间复杂度：O(1) */
class Solution {
public:
    string palindrome( string& s, int left, int right ) {
        // 防止索引越界
        while ( left >= 0 && right < s.size() && s[left] == s[right] ) {
            --left; ++right;  // 向两边展开
        }
        // 返回以 s[left] and s[right] 为中心的最长回文串
        return s.substr( left + 1, right - left - 1 );
    }

    string longestPalindrome(string s) {
        string res;
        for ( size_t i = 0; i < s.size(); ++i ) {
            // 以 s[i] 为中心的最长回文子串
            string s1 = palindrome( s, i, i );
            // 以 s[i] and s[i+1] 为中心的最长回文子串
            string s2 = palindrome( s, i, i+1 );
            // res = longest( res, s1, s2 );
            // 求出最长的回文子串
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }

        return res;
    }
};

// 方法二：Manacher 
class Solution_2 {
public:
    string longestPalindrome(string s) {
        string str = manacherString( s );

        int R = -1;
        int Center = -1;
        int maxLen = 1;
        int start = 0;
        vector<int> arr( str.size() );

        for ( int i = 0; i < (int)str.size(); ++i ) {
            arr[i] = i < R ? min( arr[2 * Center - i], R - i ) : 1;
            
            while ( -1 < i - arr[i] && i + arr[i] < str.size() ) {
                if ( str[i - arr[i]] == str[i + arr[i]] )
                    ++arr[i];
                else
                    break;
            }

            if ( i + arr[i] > R ) {
                R = i + arr[i];
                Center = i;
            }
            
            if ( maxLen < arr[i] ) {
                maxLen = arr[i];
                start = ( Center + 1 - maxLen ) / 2;
            }
        }

        return s.substr( start, maxLen - 1 );
    }

    string manacherString( string& s ) {
        string res( 2 * s.size() + 1, '#' );
        int index = 0;

        for ( size_t i = 1; i < res.size(); i += 2 )
            res[i] = s[index++];
        
        return res;
    }
};


// 方法四：双指针 ==> 方法二的延申
class Solution_4 {
public:
    string longestPalindrome(string s) {
        // const int n = s.length();
        int len = 0; 
        int start = 0;
        
        for ( int i = 0; i < s.size(); ++i ) {
            int cur = max( getLen( i, i, s ), getLen( i, i + 1, s ) );
            
            if ( cur > len ) { 
                len = cur;
                start = i - ( len - 1 ) / 2;
            }
        }

        return s.substr( start, len );
    }

    int getLen( int left, int right, string& s ) {
        while ( 0 <= left && right < (int)s.size() && s[left] == s[right] ) {
            --left, ++right;
        }

        return right - left - 1;
    }
};

int main()
{
    

    return 0;
}