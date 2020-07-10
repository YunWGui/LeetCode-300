/*
Title:
    169. Majority Element
    169. 多数元素
Description:
    给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
    你可以假设数组是非空的，并且给定的数组总是存在多数元素。
Address:
    https://leetcode-cn.com/problems/majority-element/
Tips:
    同《剑指offer》39 题 -- 数组中出现次数超过一半的数字  P205
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// 方法二：哈希表
class Solution_2 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;

        for ( int e : nums ) {
            ++hashMap[e];
            if ( hashMap[e] == ( ( nums.size() + 1 ) >> 1 ) ) 
                return e;
        }

        return -1;
    }
};

// 方法一：排序
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort( nums.begin(), nums.end() );

        return nums[nums.size() >> 1];
    }
};

int main()
{
    

    return 0;
}