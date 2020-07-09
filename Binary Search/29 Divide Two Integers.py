#!/usr/bin/env python 
# -*- coding:utf-8 -*-
"""
Created on Sat Aug 31 16:39:50 2019

@author: SHI YI
"""

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        di = abs(dividend)
        ds = abs(divisor)
        solve = 0
        while ds <= di:
            di -= ds
            solve += 1
        if dividend > 0 and divisor > 0:
            return solve
        if dividend < 0 and divisor < 0:
            return solve
        return -solve
        
            
            
        
        
        
s = Solution()
#y = s.divide(10, 3)
#y = s.divide(7, -3)
y = s.divide(-2147483648, -1)

print(y)