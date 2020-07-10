/*
    154. Find Minimum in Rotated Sorted Array II

    同 《剑指offer》第11题
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) 
                left = mid + 1;
            else if (nums[mid] == nums[right]) 
                 right--; 
            else  // nums[mid] < nums[right]
                right = mid;
        }
        return nums[left];
    }
};

class Solution_2 {
public:
    int findMin(vector<int>& nums) {
        if ( nums.size() == 1 )
            return nums[0];
            
        int left = 0, right = nums.size() - 1;
        int mid = left;
        while ( nums[left] >= nums[right] ) {
            if ( right - left == 1 ) {
                mid = right;
                break;
            }
            mid = ( left + right )>>1;
            // 如果下标 left, right, mid 指向的三个数字相等
            // 则只能顺序查找
            if ( nums[left] == nums[right] && nums[mid] == nums[left] )
                return minInOrder( nums, left, right );

            if ( nums[mid] >= nums[left] )
                left = mid;
            else if ( nums[mid] <= nums[right] )
                right = mid;
        }
        return nums[mid];
    }

    int minInOrder( vector<int>& nums, int left, int right ) {
        int res = nums[0];
        for ( int i = left + 1; i <= right; ++i ) {
            if ( nums[i] < res ) 
                res = nums[i];
        }
        
        return res;
    }
};

int main()
{
    

    return 0;
}