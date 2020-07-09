/*
Title:
    55. Jump Game
    55. 跳跃游戏
Address:
    https://leetcode-cn.com/problems/jump-game/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：贪心算法
// https://mp.weixin.qq.com/s/hMrwcLn01BpFzBlsvGE2oQ
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 如果某一个作为起跳点的格子可以跳跃的距离是 n，那么表示后面 n 个格子都可以做为下一个起跳点
        // 对每一个能作为起跳点的格子都尝试跳一遍，把能跳到最远的距离不断更新，跳到最后便为成功
        int res = 0;
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( i > res )  // i：不能到达的位置
                return false;

            res = max( res, i + nums[i] );
        }

        return true;
    }
};


// 方法二：贪心算法
/*
思路：
    可理解为：通过题目中的跳跃规则，最多能跳多远？如果能够越过最后一格，返回 true，否
    由返回 false
*/
class Solution_2 {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int farthest = 0;

        for ( int i = 0; i < len - 1; ++i ) {
            // 不断计算能跳到的最远距离
            farthest = max( farthest, i + nums[i] );
            // 可能碰到了 0，卡住跳不动了
            if ( farthest <= i ) {
                return false;
            }    
        }

        return farthest >= len - 1;
    }
};


int main()
{
    

    return 0;
}