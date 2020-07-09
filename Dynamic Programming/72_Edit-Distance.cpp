/*
Title:
	72. Edit Distance
	72. 编辑距离

	又称：Levenshtein Distance - 莱文斯坦距离
Address:
	https://leetcode-cn.com/problems/edit-distance/
Tips:
	vidio : https://www.youtube.com/watch?v=MiqoA-yF-0M
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：动态规划
/*
时间复杂度 ：O(mn)， m = word1.length(), n = word2.length();
空间复杂度 ：O(mn)，我们需要大小为 O(mn) 的 dp 数组来记录状态值。
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int rows = word1.length();
        int cols = word2.length();

        // 有一个字符串为空串
        if (rows * cols == 0)   return rows + cols;

        // DP 数组
        int dp[rows + 1][cols + 1];

        // 边界状态初始化
        for (int i = 0; i < rows + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < cols + 1; j++) {
            dp[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < rows + 1; i++) {
            for (int j = 1; j < cols + 1; j++) {
                int left = dp[i - 1][j] + 1;
                int up = dp[i][j - 1] + 1;
                int left_up = dp[i - 1][j - 1];

                if (word1[i - 1] != word2[j - 1])  left_up += 1;

                dp[i][j] = min(left, min(up, left_up));

            }
        }
        return dp[rows][cols];
    }
};

// 方法二：动态规划
class Solution_2 {
public:
    int minDistance(string word1, string word2) {
        int rows = word1.size(), cols = word2.size();

		// 至少有一个字符串为空
		if ( rows * cols == 0 )  return rows + cols;

        vector<vector<int>> dp( rows, vector<int>( cols, 0 ) );

        for ( int j = 0; j < cols; ++j ) {  // 初始化第 0 行的编辑距离
            if ( word1[0] == word2[j] )
                dp[0][j] = j;
            else if ( j != 0 )
                dp[0][j] = dp[0][j-1] + 1;
            else  // j == 0 && word1[0] != word2[0]
                dp[0][j] = 1;
        }

        for ( int i = 0; i < rows; ++i ) {  // 初始化第 0 列的编辑距离
            if ( word1[i] == word2[0] )
                dp[i][0] = i;
            else if ( i != 0 )
                dp[i][0] = dp[i-1][0] + 1;
            else
                dp[i][0] = 1;
        }

        for ( int i = 1; i < rows; ++i ) {
            for ( int j = 1; j < cols; ++j ) {
                if ( word1[i] == word2[j] )
                    dp[i][j] = min( dp[i-1][j-1], min( dp[i-1][j] + 1, dp[i][j-1] + 1 ) );
                else
                    dp[i][j] = min( dp[i-1][j-1] + 1, min( dp[i-1][j] + 1, dp[i][j-1] + 1 ) );
            }
        }

        return dp[rows-1][cols-1];

    }
};

// 方法三：递归 - 超时
class Solution_3 {
public:
    int minDistance( string s1, string s2 ) {
        return dp( s1, s2, s1.length() - 1, s2.size() - 1 );
    }

    int dp( string& s1, string& s2, int i, int j ) {
        // base case
        // 从 i 走完 s1 或 j 走完 s2，可以直接返回另一个字符串剩下的长度
        if ( i == -1 )  return j + 1;
        if ( j == -1 )  return i + 1;

        if ( s1[i] == s2[j] )
            return dp( s1, s2, i - 1, j - 1 );
        else {  // s1[i] != s2[j]
            return MIN(
                dp( s1, s2, i, j - 1 ) + 1,  // 插入
                dp( s1, s2, i - 1, j ) + 1,  // 删除
                dp( s1, s2, i - 1, j - 1 ) + 1  // 替换
            );
        }
    }

    int MIN( int a, int b, int c ) {
        return min( a, min( b, c ) );
    }
};


int main()
{


	return 0;
}
