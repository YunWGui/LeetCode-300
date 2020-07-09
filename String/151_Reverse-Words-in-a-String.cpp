/*
    Title:
	    151. Reverse Words in a String
        151. 翻转字符串里的单词
    Address:
        https://leetcode-cn.com/problems/reverse-words-in-a-string/
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 方法二：「从后往前」遍历字符串 s，将每个单词不断拼接到 res 的尾部。
class Solution_2 {
public:
    string reverseWords(string s) {
        string res = "";
        int low, high = s.size() - 1;

        while ( high >= 0 ) {
            while ( high >= 0 && s[high] == ' ' )  // 过滤空格
                --high;
            if ( high < 0 )
                return res;

            low = high - 1;
            while ( low >= 0 && s[low] != ' ' )  // 遍历字符
                --low;

            if ( res != "" )
                res += " ";
            res += s.substr( low+1, high-low );
            high = low - 1;
        }

        return res;
    }
};

// 方法三：就地修改。
/* 先将整个字符串整个翻转一次，再分别翻转每一个单词。 */
class Solution_3 {
public:
    string reverseWords(string s) {
        reverse( s.begin(), s.end() );
        int len = 0;

        for ( size_t i = 0; i < s.size(); ++i ) {
            if ( s[i] != ' ' ) {  // 字符非空
                if ( len != 0 )
                    s[len++] = ' ';

                size_t j = i;
                while ( j < s.size() && s[j] != ' ' )
                    s[len++] = s[j++];
                reverse( s.begin() + len - (j - i), s.begin() + len );
                i = j;
            }
        }
        s.resize(len);  // 重新调整大小

        return s;
    }
};

// 方法一：栈
class Solution {
public:
    string reverseWords(string s) {
        stack<string> strStack;
        string str = "";

        for ( size_t i = 0; i < s.size(); ++i ) {
            if ( s[i] != ' ' )
                str += s[i];
            else if ( str != "" ) {  // 禁止 "" 入栈
                strStack.push( str );
                str = "";
            }
        }
        if ( str != "" )
            strStack.push( str );

        str = "";
        while ( !strStack.empty() ) {
            str += strStack.top();
            strStack.pop();

            if ( !strStack.empty() )
                str += " ";
        }

        return str;
    }
};

int main()
{


	return 0;
}
