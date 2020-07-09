/*
    153. Find Minimum in Rotated Sorted Array
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while ( nums[left] > nums[right] ) {
            int mid = left + ( ( right - left )>>1 );
            if ( nums[left] <= nums[mid] )
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};

int main()
{
    

    return 0;
}