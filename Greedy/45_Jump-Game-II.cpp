/*
Title:
    45. Jump Game II
    45. 跳跃游戏 II
Address:
    https://leetcode-cn.com/problems/jump-game-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：贪心算法
// https://mp.weixin.qq.com/s/hMrwcLn01BpFzBlsvGE2oQ
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int end = 0;
        int farthest = 0;  // 标记所有可选择的跳跃步数中 [i...end] 中能够跳到的最远距离
        int jumps = 0;  // 跳跃次数
        for ( int i = 0; i < len - 1; ++i ) {
            farthest = max( farthest, i + nums[i] );
            if ( end == i ) {  // i, end : 标记可以选择的跳跃步数
                ++jumps;
                end = farthest;
            }
        }

        return jumps;
    }
};


// 方法二: 贪心 - 《代码面试指南》  P247
class Solution_2 {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int farthest = 0;
        int jumps = 0;
        
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( end < i ) {
                ++jumps;
                end = farthest;
            }
            // 忽略 else ( end >= i ) ：此时什么也不做
            farthest = max( farthest, i + nums[i] );
        }

        return jumps;
    }
};


int main()
{
    

    return 0;
}