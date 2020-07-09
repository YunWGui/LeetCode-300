/*
Title:
	28. Implement strStr()
	28. 实现 strStr()
Address:
	https://leetcode-cn.com/problems/implement-strstr/submissions/
*/

#include <iostream>
using namespace std;


// 方法一：KMP 算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if ( needle.empty() )
            return 0;
        
        int* next =  buildNext( needle );
        int N = (int)haystack.size(), i = 0;
        int M = (int)needle.size(), j = 0;

        while ( i < N && j < M ) {
            if ( j < 0 || haystack[i] == needle[j] ) {
                ++i, ++j;
            }
            else 
                j = next[j];
        } 

        return j == M ? i - j : -1;

    }
    
    int* buildNext( string& needle ) {
        int M = (int)needle.size(), j = 0;
        int* next = new int[M];
        int t = next[0] = -1;
        while ( j < M - 1 ) {
            if ( t < 0 || needle[t] == needle[j] ) {
                ++t, ++j;
                next[j] = ( needle[t] != needle[j] ? t : next[t] );
            }
            else 
                t = next[t];
        }

        return next;
    }
};


int main()
{


	return 0;
}
