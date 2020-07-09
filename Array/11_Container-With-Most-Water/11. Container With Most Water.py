"""
Title:
	11. Container With Most Water
	11. 盛水最多的容器
Address:
	https://leetcode-cn.com/problems/container-with-most-water/
"""


class Solution:
    def maxArea(self, height):
        if len(height) <= 1:
            return -1
        i, j, res = 0, len(height) - 1, 0
        while i < j:
            if height[i] < height[j]:
                res = max(res, height[i] * (j - i))
                i += 1
            else:
                res = max(res, height[j] * (j - i))
                j -= 1
        return res


nums = [1, 8, 6, 2, 5, 4, 8, 3, 7]
# nums = [1, 1]
solve = Solution()
s = solve.maxArea(nums)
print(s)


