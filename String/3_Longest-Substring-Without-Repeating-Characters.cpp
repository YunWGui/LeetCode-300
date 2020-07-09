/*
Title:
    3. Longest Substring Without Repeating Characters
    3. 无重复字符的最长子串
Address:
    https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 方法一：动态规划
class Solution{
public:
	int lengthOfLongestSubstring(string s){
		if ( s.size() == 0 )
			return 0;

		vector<int> dp( s.size(), 1 );
		int res = 1;

		for ( int i = 1; i < s.size(); ++i ) {
			int tmp = 0;
			for( ; tmp < dp[i - 1]; ++tmp ) {
				if ( s[i] == s[i - 1 - tmp] )
					break;
			}
			dp[i] = dp[i] + tmp;
			res = ( dp[i] > res ? dp[i] : res );
		} 

		return res;
	}
};

// 方法二：哈希表
class Solution_2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> M;  // 存储「字符」及其对应的「下标」
        int maxLen = 0;
        int lastRepeatPos = -1;            
        for ( int i = 0; i < s.size(); ++i ) {
            if ( M.find(s[i]) != M.end() && lastRepeatPos < M[s[i]] )
                lastRepeatPos = M[s[i]];

            if ( maxLen < i - lastRepeatPos )
                maxLen = i - lastRepeatPos;
            
            M[s[i]] = i;  // 更新字符所在「下标」
        }
        
        return maxLen;
    }
};

// 方法三：滑动窗口
// 参考：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
class Solution_3 {
public:
    int lengthOfLongestSubstring(string s) {
        if ( s.empty() )
            return 0;

        unordered_set<char> window;
        int maxStr = 0;
        int left = 0;  // 此处不能取 left = -1，不然 window.erase( s[left] ) 操作会报错
        for ( int i = 0; i < s.size(); ++i ) {
            // 直到将与 s[i] 重复的字符删除后，才能退出循环
            while ( window.find(s[i]) != window.end() ) {  
                window.erase( s[left] );
                ++left;
            }
            maxStr = max( maxStr, i - left + 1 );
            window.insert( s[i] );  // 将字符插入集合
        }

        return maxStr;
    }
};

// 方法四：滑动窗口
// https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ
class Solution_4 {
public:
    int lengthOfLongestSubstring( string s ) {
        int left = 0, right = 0;  // 左、右指针
        unordered_map<char, int> window;
        int res = 0;

        while ( right < s.size() ) {
            char c1 = s[right];
            ++window[c1];
            ++right;
            // 如果 window 中出现重复字符，则移动 left 缩小窗口
            while ( window[c1] > 1 ) {
                char c2 = s[left];
                --window[c2];
                ++left;
            }
            res = max( res, right - left );
        }

        return res;        
    }
};


int main()
{
	// string st {"pwwkew"};
	// string st {"bbbbb"};
	// string st {"abcabcbb"};
	string st {"cbb"};


	Solution solve;

	cout << solve.lengthOfLongestSubstring(st) << endl;


	return 0;
}
