// Given a sorted array and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

#include<iostream>
#include<vector>
using namespace std;

// 本题可理解为：查找一个大于等于 target 的元素，并返回其下标
// mid = (left + right) / 2;  // 如果二分上界超过 int 型数据范围的一半，
// 将会导致该语句溢出，可改为: mid = left + (right - left) / 2;

// 解法一：
// class Solution{
// public:
//     int searchInsert(vector<int>& nums, int target){
// 		int len = nums.size();
// 		if(len == 0)
// 			return 0;
// 		for(int i = 0; i < len; i++){
// 			if(nums[i] >= target)
// 				return i;
// 		}
// 		return len;
// 	}
// };

// 解法二：
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1, mid;
		while(low <= high){
			mid = low + (high - low) / 2;
			if(nums[mid] == target)
				return mid;
			else if(target < nums[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		return low;
	}
};

int main()
{
    vector<int> nums{1, 3, 5, 6};
    int target;

	Solution s;
	target = 7;
	cout << s.searchInsert(nums, target) << endl;

    return 0;
}
