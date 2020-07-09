/**
 * Title:
 *      76. Minimum Window Substring
 *      76. 最小覆盖子串
 * Address:
 *      https://leetcode-cn.com/problems/minimum-window-substring/
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 方法一：滑动窗口 - 双指针
/* 时间复杂度：O( s.size() + t.size() )  */
// https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ

/**
 * 思路：
 *      1、在字符串 S 中使用双指针中的「左右指针」技巧，初始化 left = right = 0，把
 *         索引闭区间 [left, right] 称为一个「窗口」
 *      2、先不断增加 right 指针，扩大窗口 [left, right]，直到窗口中的字符串符合要
 *         求（包含了 target 中的所有字符）。
 *      3、停止增加 right，转而不断增加 left 指针，缩小 [left, right]，直到窗口中的
 *         字符串不再符合要求（不包含 target 中的所有字符了）。同时，每次增加 left，
 *         都要更新一轮结果。
 *      4、重复第 2、3 步，直到 right 到达字符串 S 的心头
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;

        // 相当于两个计数器
        unordered_map<char, int> window, needs;

        for ( char c : t )
            ++needs[c];
        
        int match = 0;  // 记录 window 中已经有多少字符符合要求

        while ( right < s.size() ) {
            char c1 = s[right];
            if ( needs.count( c1 ) ) {
                ++window[c1];  // 加入 window
                if ( window[c1] == needs[c1] )  // 字符 c1 的出现次数符合要求
                    ++match;
            }
            ++right;

            // window 中的字符串已经符合 needs 的要求
            while ( match == needs.size() ) {
                if ( right - left < minLen ) {
                    // 更新最小子串的位置和长度
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if ( needs.count( c2 ) ) {
                    --window[c2];  // 移出 window
                    if ( window[c2] < needs[c2] )  // 字符 c2 出现次数不再符合要求
                        --match;
                }
                ++left;
            }
        }

        return minLen == INT_MAX ? "" : s.substr( start, minLen );
    }
};


// 方法二：双指针
// https://leetcode-cn.com/problems/minimum-window-substring/solution/zui-xiao-fu-gai-zi-chuan-shuang-zhi-zhen-ha-xi-bia/
/*
思路：
    j 在左，i 在右，统计 t 内字母出现的次数，每次出现的字母次数都要 -1
    如果 t 中的字母次数小于 0，说明出现了再次，那么 j 就需右移
*/
class Solution_2 {
  public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for (auto c : t)    hash[c]++;
        
        int cnt = hash.size();
        string res;
        
        for (int i = 0, j = 0, c = 0; i < s.size(); i++) {
            if (hash[s[i]] == 1)
                c++;
        
            hash[s[i]]--;
        
            while (hash[s[j]] < 0)
                hash[s[j++]]++;
        
            if (c == cnt) {
                if (res.empty() || res.size() > i - j + 1)
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};

int main()
{
    

    return 0;
}