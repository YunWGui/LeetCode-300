# !/usr/bin/env python 
# -*- coding:utf-8 -*-
"""
Created on Fri Nov  1 16:38:58 2019

@author: SHI YI
"""

class Solution:
    def isValid(self, s: str) -> bool:
        left = "({["
        right = ")}]"
        stack = []  # empty list, used as stack

        for c in s:
            if c in left:     # add c to ls, if c in 'left'
                stack.append(c)
            elif c in right:  # skip c, if c in 'right' 
                if len(stack) == 0:
                    return False
                elif right.index(c) != left.index(stack.pop()):
                    return False
        return len(stack) == 0


s = "("

solve = Solution()

if solve.isValid(s):
    print("True")
else:
    print("False")
    