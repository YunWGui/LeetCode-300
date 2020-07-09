// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).

#include<iostream>
#include<vector>
using namespace std;


// 方法一：直觉法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;  // 左闭右闭区间 [low, high]
        if ( high == -1 )
            return -1;

        if ( nums.back() < nums[0] ) {  // 如果数组「翻转」
            while ( low < high ) {  // 则找出最小值所在索引
                int mid = low + ( (high-low)>>1 );
                if ( nums[mid] < nums[high] )
                    high = mid;
                else
                    low = mid + 1;
            }
            // 并划定区间
			if ( nums[0] <= target ) {
	            high = low-1;
	            low = 0;
	        }
	        else {
	            low = low;
	            high = nums.size()-1;
	        }
        }

        while ( low <= high ) {
            int mid = low + ( (high-low)>>1 );
            if ( nums[mid] < target )
                low = mid + 1;
            else if ( target < nums[mid] )
                high = mid -1;
            else
                return mid;
        }

        return -1;
    }
};

int main()
{
	Solution solve;
	vector<int> nums{4, 5, 6, 7, 0, 1, 2};
	int target = 0;

	cout << solve.search(nums, target) << endl;


	return 0;
}
