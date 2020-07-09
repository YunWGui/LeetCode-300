/*
Title:
    466. Count The Repetitions
    466. 统计重复个数
Address:
    https://leetcode-cn.com/problems/count-the-repetitions/
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// 方法一：找「循环节」
// https://leetcode-cn.com/problems/count-the-repetitions/solution/tong-ji-zhong-fu-ge-shu-by-leetcode-solution/s
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if ( n1 == 0 )
            return 0;
        
        int s1Count = 0, index = 0, s2Count = 0;
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while ( true ) {
            ++s1Count;
            for( char ch : s1 ) {
                if ( ch == s2[index] ) {
                    index += 1;
                    if ( index == s2.size() ) {
                        ++s2Count;
                        index = 0;
                    }
                }
            }
            // 还没有找到循环节，所有的 s1 就用完了
            if ( s1Count == n1 )
                return s2Count / n2;

            // 出现子之前的 index，表示找到了循环节
            if ( recall.count( index ) ) {
                auto [s1Count_prime, s2Count_prime] = recall[index];
                pre_loop = { s1Count_prime, s2Count_prime };
                // 以后的每 ( s1Count - s1Count' ) 个 s1 包含了 ( s2Count - s2Count' ) 个 2
                in_loop = { s1Count - s1Count_prime, s2Count - s2Count_prime };
                break;
            }
            else
                recall[index] = { s1Count, s2Count };
        }
        //  ans 存储的是 S1 包含的 s2 的数量，考虑的之间的 pre_loop 和 in_loop
        int ans = pre_loop.second + ( n1 - pre_loop.first ) / in_loop.first * in_loop.second;
        // S1 的末尾还剩下一些 s1，我们暴力进行匹配
        int rest = ( n1 - pre_loop.first ) % in_loop.first;
        for ( int i = 0; i < rest; ++i ) {
            for ( char ch : s1 ) {
                if ( ch == s2[index] ) {
                    ++index;
                    if ( index == s2.size() ) {
                        ++ans;
                        index = 0;
                    }
                }
            }
        }
        // S1 包含 ans 个 s2，那么就包含 ans / n2 个 S2
        return ans / n2;
    }
};


int main()
{
    

    return 0;
}