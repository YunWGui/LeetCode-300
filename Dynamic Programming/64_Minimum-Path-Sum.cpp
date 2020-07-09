/*
Title:
    64. Minimum Path Sum
    64. 最小路径和
Address:
    https://leetcode-cn.com/problem s/minimum-path-sum/
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法二：动态规划
class Solution_2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if ( grid.empty() )
            return 0;

        int rows = grid.size(), cols = grid[0].size();
        
        for ( int j = 1; j < cols; ++j )
            grid[0][j] += grid[0][j - 1];
        for ( int i = 1; i < rows; ++i )
            grid[i][0] += grid[i - 1][0];

        for ( int i = 1; i < rows; ++i ) {
            for ( int j = 1; j < cols; ++j ) {
                grid[i][j] += min( grid[i - 1][j], grid[i][j - 1] );
            }
        }

        return grid[rows - 1][cols - 1];
    }
};


// 方法一：动态规划 - 二维数组
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if ( grid.empty() )
            return 0;
            
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp( rows, vector<int>( cols, 0 ) );  // 可省略辅助函数，直接在原函数上进行运算

        dp[0][0] = grid[0][0];
        for ( int i = 1; i < rows; ++i )
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        for ( int j = 1; j < cols; ++j )
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        
        for ( int i = 1; i < rows; ++i ) {
            for ( int j = 1; j < cols; ++j ) {
                dp[i][j] = min( dp[i - 1][j], dp[i][j - 1] ) + grid[i][j];
            }
        }
        
        return dp[rows - 1][cols - 1];
    }
};

int main()
{
    

    return 0;
}