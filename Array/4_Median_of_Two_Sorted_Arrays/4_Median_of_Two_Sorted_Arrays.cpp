/*
Title:
	4. Median of Two Sorted Arrays
	4. 寻找两个有序数组的中位数
Description:
	There are two sorted arrays nums1 and nums2 of size m and n respectively.
	Find the median of the two sorted arrays. The overall run time complexity 
	should be O(log (m+n)).
	You may assume nums1 and nums2 cannot be both empty.
Address:
	https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法一：合并 + 二分查找
/*
思路：
	1. 将 nums1 扩容
	2. 将 nums1, nums2 合并到 nums1
	3. 二分查找 num1
时间复杂度：max( O(n), O(m) ), 空间复杂度：O(n + m)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Left = nums1.size(), nums2Left = nums2.size();  // nums1, nums2 的「左」边界
        int newLeft = nums1Left + nums2Left - 1;  // 新合并的数组的「左」边界
        int start = 0, end =  newLeft ;  // 二分查找标志位
        nums1.resize( nums1Left + nums2Left );  // 扩容
        
        --nums1Left; --nums2Left;

        while ( nums1Left != -1 && nums2Left != -1 ) {
            if ( nums1[nums1Left] < nums2[nums2Left] ) 
                nums1[newLeft--] = nums2[nums2Left--];
            else 
                nums1[newLeft--] = nums1[nums1Left--];
        }

        while ( nums2Left != -1 ) 
            nums1[newLeft--] = nums2[nums2Left--];
        
        while ( start + 1 < end ) {
            ++start; --end;
        }
        
        if ( start + 1 == end )  // 长度为「偶数」
            return ( nums1[start] + nums1[end] ) / 2.0;
        
        return nums1[start];  // start == end; 即长度为「奇数」
    }
};


// 方法二：方法一的简写版
class Solution_2 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
		sort(nums1.begin(), nums1.end());
		int left = 0, right = nums1.size() - 1;

		if(0 == right)
			return nums1[0];
		while(right - left > 2){
			++left;
			--right;
		}
		if(2 == right - left)
			return nums1[++left];
			
		return (nums1[left] + nums1[right]) / 2.0;
	}
};

int main()
{
	// vector<int> nums1 {0};
	// vector<int> nums2 {1};
	vector<int> nums1 {1, 2};
	vector<int> nums2 {3, 4};

	Solution solve;

	cout << solve.findMedianSortedArrays(nums1, nums2) << endl;
	// print(nums1);

	return 0;
}
