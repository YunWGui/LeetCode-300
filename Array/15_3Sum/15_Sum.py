#!/usr/bin/env python 
# -*- coding:utf-8 -*-
"""
Created on Tue Sep 24 20:39:26 2019

@author: SHI YI
"""

"""
Title:
	15. 3Sum
	15. 三数之和
Address:
	https://leetcode-cn.com/problems/3sum/
"""


class Solution:
    def threeSum(self, nums):
        nums = sorted(nums)
        length = len(nums)
        ls = []
        for i in range(0, length - 2):
            for j in range(i + 1, length - 1):
                surplus = nums[i] + nums[j]
                if -surplus in nums[j + 1: ]:
                    ls.append([nums[i], nums[j], -surplus])
        return set(tuple(s) for s in ls)
                
        
#nums1 = [-1, 0, 1, 2, -1, -4]
#nums1 = [-2, 0, 1, 1, 2]
nums1 = [0, 0, 0]
solve = Solution()
x = solve.threeSum(nums1)
print(x)