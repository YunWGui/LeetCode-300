/**
 * Title:
 *      438. Find All Anagrams in a String
 *      438. 找到字符串中所有字母异位词
 * Address:
 *      https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 方法一：滑动窗口
// https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int left = 0, right = 0;
        unordered_map<char, int> needs, window;

        for ( char c : p )
            ++needs[c];
        
        int match = 0;

        while ( right < s.size() ) {
            char c1 = s[right];
            if ( needs.count( c1 ) ) {
                ++window[c1];
                if ( window[c1] == needs[c1] )
                    ++match;
            }
            ++right;
            // needs.sie() != p.size()
            // 比如：p = "aaaa", p.size() == 4, needs.size() == 1
            while ( match == needs.size() ) {
                // 如果 window 的大小合适，就把起始索引 left 加入结果
                if ( right - left == p.size() )
                    res.push_back( left );

                char c2 = s[left];
                if ( needs.count( c2 ) ) {
                    --window[c2];
                    if ( window[c2] < needs[c2] )
                        --match;
                }
                ++left;
            }
        }
        
        return res;
    }
};

int main()
{
    

    return 0;
}