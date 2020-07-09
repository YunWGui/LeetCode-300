// Given an array nums and a value val, remove all instances of that value
// in-place and return the new length.
// Do not allocate extra space for another array, you must do this by modifying
// the input array in-place with O(1) extra memory.
// The order of elements can be changed. It doesn't matter what you leave
// beyond the new length.

#include <iostream>
#include <vector>
#include "../../print.h"
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int i, k = 0;
		int len = nums.size();
		for(i = 0; i < len; ++i){
			if(val != nums[i]){
				nums[k] = nums[i];
				++k;
			}
		}
		return k;
    }
};

int main()
{
	vector<int> arr{0,1,2,2,3,0,4,2};
	int target {2};
	// vector<int> arr{2};
	// int target {2};

	Solution solve;

	cout << solve.removeElement(arr, target) << endl;
	print(arr);


	return 0;
}
