/*
Title:
    136. Single Number
    136. 只出现一次的数字
Address:
    https://leetcode-cn.com/problems/single-number/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 方法二：位运算 - 异或
// 两个相同数字，异或结果为 0 
class Solution_2 {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        
        for ( int i = 1; i < nums.size(); ++i ) 
            res ^= nums[i];

        return res;
    }
};

// 方法一：
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if ( nums.size() % 2 == 0 )  // 数组有偶数个元素
            return 0;

        sort( nums.begin(), nums.end() );
        // 排序后，只出现一次的数字，只可能出现在「奇数」下标处
        int i = 0;
        while ( i < nums.size() - 1 ) {
            if ( nums[i] != nums[i + 1] )
                return nums[i];
            i += 2;
        }
        
        return nums[nums.size() - 1];
    }
};

// 方法三：哈希表
class Solution_3 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> M;
        int res = 0;
        
        for ( int num : nums )
            ++M[num];
        
        for ( auto iter = M.begin(); iter != M.end(); ++iter )
            if ( iter->second == 1 ) {
                res = iter->first;
                break;
            }
        
        return res;
    }
};


int main()
{
    

    return 0;
}