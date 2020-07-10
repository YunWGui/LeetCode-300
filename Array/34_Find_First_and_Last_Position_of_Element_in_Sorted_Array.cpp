/*
Title:
	34. Find First and Last Position of Element in Sorted Array
Description:
	Given an array of integers nums sorted in ascending order, find the starting
	and ending position of a given target value.
	Your algorithm's runtime complexity must be in the order of O(log n).
	If the target is not found in the array, return [-1, -1].

	Example 1:
	Input: nums = [5,7,7,8,8,10], target = 8
	Output: [3,4]

	Example 2:
	Input: nums = [5,7,7,8,8,10], target = 6
	Output: [-1,-1]
*/


#include <iostream>
#include <vector>
using namespace std;


// 方法三：二分查找


// 方法一：
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if ( nums.empty() )
            return vector<int> { -1, -1 };

        int count = 0, j = 0;
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( target == nums[i] ) {
                ++count;
                j = i;
            }

            if ( target < nums[i] )
                break;
        }

        if ( count == 0 )
            return vector<int> { -1, -1 };
        else if ( count == 1 )
            return vector<int> { j, j };
        else
            return vector<int> { j-count+1, j };
    }
};

// 方法二：
class Solution_2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        vector<int> res;

        for ( int i = 0; i < nums.size(); ++i ) {
            if ( start == -1 && nums[i] == target )
                start = i;
            if ( nums[i] == target )
                end = i;
        }
        res.emplace_back( start );
        res.emplace_back( end );

        return res;
    }
};


int main()
{


	return 0;
}
