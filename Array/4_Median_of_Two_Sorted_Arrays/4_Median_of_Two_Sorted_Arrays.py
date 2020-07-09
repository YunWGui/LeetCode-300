"""
Title:
	4. Median of Two Sorted Arrays
	4. 寻找两个有序数组的中位数
Address:
	https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
"""


class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        nums = sorted(nums1 + nums2)
        if len(nums) == 1:
            return nums[0]            
        left = 0
        right = len(nums) - 1
        while right - left > 2:
            left += 1
            right -= 1
        if right - left == 1:
            return (nums[right] + nums[left]) / 2
        return nums[left + 1]    


# arr1 = [1, 2]
# arr2 = [3, 4]

arr1 = [3]
arr2 = [-2, -1]
# arr1 = []
# arr2 = [1]
solve = Solution()
result = solve.findMedianSortedArrays(arr1, arr2)
print(result)

