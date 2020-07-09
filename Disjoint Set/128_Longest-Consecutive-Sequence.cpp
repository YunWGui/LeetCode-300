/*
Title:
    128. Longest Consecutive Sequence
    128. 最长连续序列
Description:
    Given an unsorted array of integers, find the length of the longest consecutive
    elements sequence.
    Your algorithm should run in O(n) complexity.
Address: 
    https://leetcode-cn.com/problems/longest-consecutive-sequence/
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 方法一：哈希表
/* 时间复杂度：O(n)  空间复杂度：O(n) */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique_nums;
        
        for ( const int& num : nums )  // 去重
            unique_nums.insert( num );

        int maxLen = 0;  // 最长长度
        for ( const int& num : unique_nums ) {
            if ( !unique_nums.count( num - 1 ) ) {  // 集合中不存在 num - 1，即不存在比 num 小 1 的数
                int curNum = num;
                int curLen = 1;  // 统计从当前数字开始，有多少个数字与它连续

                while ( unique_nums.count( curNum + 1 ) ) {
                    ++curNum;
                    ++curLen;
                }
            
                maxLen = max( maxLen, curLen );
            }
        }

        return maxLen;        
    }
};

// 方法二：并查集
// https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/cbing-cha-ji-xie-fa-dai-ma-ji-duan-by-leck/
class Solution_2 {
public:
    unordered_map<int, int> M;

    int find( int x ) {
        return M.count( x ) ? M[x] = find( M[x] ) : x;
    }

    int longestConsecutive(vector<int>& nums) {
        for ( const int& num : nums ) 
            M[num] = num + 1;
        
        int ans = 0;
        for ( const int& num : nums ) {
            int consLen = find( num + 1 );  // 探索最长连续长度，返回最大连续长度值

            ans = max( ans, consLen - num );
        }

        return ans;
    }
};


int main()
{
    // vector<int> vec { 100, 4, 200, 1, 3, 2 };
    vector<int> vec { 100,4,4, 5, 5,200,1,3,2 };

    Solution solve;
    int res = solve.longestConsecutive( vec );

    printf( "%d", res );
    

    return 0;
}