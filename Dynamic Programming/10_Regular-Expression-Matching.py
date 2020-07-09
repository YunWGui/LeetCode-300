"""
Title:
	10. Regular Expression Matching
	10. 正则表达式匹配
Address:
	https://leetcode-cn.com/problems/regular-expression-matching/
Tips:
	同《剑指Offer》- 19
"""

# https://mp.weixin.qq.com/s/TAiIIxoDXx67MNGXea6gfQ
def isMatch(text, pattern) -> bool:
    memo = dict()  # 备忘录
    def dp(i, j):
        if (i, j) in memo:
            return memo[(i, j)]
        if j == len(pattern):
            return i == len(text)

        first = i < len(text) and pattern[j] in {text[i], '.'}

        if j <= len(pattern) - 2 and pattern[j + 1] == '*':
            res = dp(i, j + 2) or first and dp(i + 1, j)
        else:
            res = first and dp(i + 1, j + 1)

        memo[(i, j)] = res

        return res

    return dp(0, 0)


if __name__ == '__main__':
    text = "aab"
    pattern = "c*a*b"
    print(isMatch(text, pattern))
