/*
    Title:
        62. Unique Paths
        62. 不同路径
    Address:
        https://leetcode-cn.com/problems/unique-paths/
    Tips:
        类似《剑指offer》第47题 —— 礼物的最大价值  P233
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法三：动态规划：一维数组
/* 时间复杂度：O( m*n ), 空间复杂度：O( n ) */
class Solution_3 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp( n, 1 );

        for ( int row = 1; row < m; ++row ) {
            for ( int col = 1; col < n; ++col ) {
                dp[col] = dp[col] + dp[col-1];
            }
        }

        return dp[n - 1];
    }
};

// 方法二：动态规划：二维数组
/* 时间复杂度：O( m*n ), 空间复杂度：O( m*n ) */
class Solution_2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res( m, vector<int>( n, 1 ) );

        for ( int row = 1; row < m; ++row ) {
            for ( int col = 1; col < n; ++col ) {
                res[row][col] = res[row][col-1] + res[row-1][col];
            }
        }

        return res[m-1][n-1];
    }
};

// 方法一：回溯法 + DFS - 超时
class Solution {
public:
    int uniquePaths(int m, int n) {
        int count = 0;

        backTrack( 0, 0, m, n, count );

        return count;
    }

    void backTrack( int row, int col, int m, int n, int& count ) {
        if ( row == m - 1 && col == n - 1 ) {
            ++count;

            return;
        }

        if ( row >= m || col >= n )
            return;
        
        backTrack( row + 1, col, m, n, count );
        backTrack( row, col + 1, m, n, count );
    }
};

int main()
{
    

    return 0;
}