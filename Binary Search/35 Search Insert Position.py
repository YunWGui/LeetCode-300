#!/usr/bin/env python 
# -*- coding:utf-8 -*-
"""
Created on Fri Aug 30 11:34:51 2019

@author: SHI YI
"""
# 35 Search Insert Position
# Given a sorted array and a target value, return the index if the target is found.
# If not, return the index where it would be if it were inserted in order.
#
# You may assume no duplicates in the array.

# 解法一：
# class Solution:
#     def searchInsert(self, nums, target):
#         for i in range(len(nums)):
#             if nums[i] >= target:
#                 if nums[i] == target:
#                     return i
#                 return i
#         if nums[-1] < target:
#             return len(nums)

# 解法二：
class Solution:
    def searchInsert(self, nums, target):
        return len([i for i in nums if i < target])
        
        
nums = [1, 3, 5, 6]
target = 7
search = Solution()
solve = search.searchInsert(nums, target)
print("Ths solve is：", solve)