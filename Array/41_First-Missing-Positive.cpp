/*
Title:
    41. First Missing Positive
    41. 缺失的第一个正数
Address: 
    https://leetcode-cn.com/problems/first-missing-positive/
Tips:
    同《程序员代码面试指南》
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int left = 0, right = nums.size();

        while ( left < right ) {
            if ( nums[left] == left + 1 )
                left++;
            else if ( nums[left] <= left || nums[left] > right || nums[nums[left] - 1] == nums[left] )
                nums[left] = nums[--right];
            else
                swap( nums[left], nums[nums[left] - 1] );
        }

        return left + 1;
    }
};

int main()
{
    

    return 0;
}