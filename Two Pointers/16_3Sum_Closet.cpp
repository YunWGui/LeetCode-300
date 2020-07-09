/*
Title:
	16. 3Sum Closest
	16. 最接近的三数之和
Description:
	Given an array nums of n integers and an integer target, find three integers
	in nums such that the sum is closest to target. Return the sum of the three integers.
	You may assume that each input would have exactly one solution.
Address:
	https://leetcode-cn.com/problems/3sum-closest/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 解法一：蛮力求解
class Solution{
public:
    int threeSumClosest(vector<int> &nums, int target){
		int radius = 0;  // 半径
        int len = nums.size();

        while ( true ){
            for (int i = 0; i < len - 2; i++)
                for (int j = i + 1; j < len - 1; j++)
                    for (int k = j + 1; k < len; k++)
                        if (nums[i] + nums[j] + nums[k] == target + radius)
                            return target + radius;
            // 向 target 两端扩展，即 target - |radius| <-- target --> target + |radius|
            if (radius < 0)
                radius = -radius;
            else{
                radius++;
                radius = -radius;
            }
        }
    }
};

// 解法二：双指针
class Solution_2{
public:
	int threeSumClosest(vector<int>& nums, int target){
		sort( begin(nums), end(nums) );

		int ans = nums[0] + nums[1] + nums[2];
		for ( int i = 0; i < nums.size(); i++ ) {
			int start = i + 1, end = nums.size() - 1;
			while ( start < end ) {
				int sum = nums[i] + nums[start] + nums[end];
				if ( abs ( sum - target ) < abs ( ans - target ) )
					ans = sum;

				if ( sum > target )
					--end;
				else if ( sum < target )
					++start;
				else  // ans == target ：提前终止
					return ans;
			}
		}
		
		return ans;
	}
};


int main()
{
	vector<int> nums {-1, 2, 1, -4};
	// vector<int> nums{1, 8, 6, 2, 5, 4, 8, 3, 7};
	int target = 1;

	Solution solve;
	cout << solve.threeSumClosest(nums, target) << endl;


	return 0;
}
