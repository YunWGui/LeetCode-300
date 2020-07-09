/*
Title:
    14. Longest Common Prefix
    14. 最长公共前缀
Description:
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
Address: 
    https://leetcode-cn.com/problems/longest-common-prefix/
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ( strs.empty() )
            return "";
        
        int length = strs[0].size();

        for ( int i = 0; i < length; ++i ) {
            char ch = strs[0][i];
            for ( int j = 1; j < (int)strs.size(); ++j ) {  // 遍历 vector
                if ( i == strs[j].size() || ch != strs[j][i] )  // 提前终止
                    return strs[0].substr(0, i);
            }
        }

        return strs[0];
    }
};

int main()
{
    

    return 0;
}