/*
Title:
    18. 4Sum
    18. 四数之和
Description:
    Given an array nums of n integers and an integer target,
    are there elements a, b, c, and d in nums such that a + b + c + d = target?
    Find all unique quadruplets in the array which gives the sum of target.
    Note:
    The solution set must not contain duplicate quadruplets.
Address:
    https://leetcode-cn.com/problems/4sum/
*/


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


// 方法二：双指针
/* 时间复杂度：O(n^3)  空间复杂度：O(1) */
class Solution_2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort( nums.begin(), nums.end() );
        if ( nums.size() < 4 )
            return res;
        
        int len = nums.size();
        for ( int i = 0; i < len - 3; ++i ) {
            if ( i > 0 && nums[i - 1] == nums[i] )
                continue;

            for ( int j = i + 1; j < len - 2; ++j ) {
                if ( j > i + 1 && nums[j - 1] == nums[j] )
                    continue;
                
                int left = j + 1, right = len - 1;
                while ( left < right ) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if ( sum < target )
                        ++left;
                    else if ( sum > target ) 
                        --right;
                    else {
                        res.push_back( { nums[i], nums[j], nums[left], nums[right] } );

                        while ( left < right && nums[left] == nums[left + 1] )
                            ++left;
                        while ( left < right && nums[right - 1] == nums[right] )
                            --right;
                        
                        ++left;
                        --right;
                    }
                }
            }
        }

        return res;
    }
};

// 方法一：暴力法
/* 时间复杂度：O(n^4)  空间复杂度：O(n) */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end() );
        
        // vector<int> temp;
        vector<vector<int>> res;
        set<vector<int>> unique;
        
        int len = nums.size(); 
        for ( int i = 0; i < len - 3; ++i ) {
            for ( int j = i + 1; j < len - 2; ++j ) {
                for ( int k = j + 1; k < len - 1; ++k ) {
                    for ( int l = k + 1; l < len; ++l )
                        if ( nums[i] + nums[j] + nums[k] + nums[l] == target ) {
                            vector<int> temp { nums[i], nums[j], nums[k], nums[l] };
                            if ( unique.find( temp ) == unique.end() ) {  // 是否重复
                                unique.insert( temp );
                                res.push_back( temp );
                            }
                        }
                }
            }
        }

        return res;
    }
};


int main()
{
	vector<int> inArr {1, 0, -1, 0, -2, 2};
	int target {0};
	

	return 0;
}
