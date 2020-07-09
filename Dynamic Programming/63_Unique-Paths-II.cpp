/*
    Title:
        63. Unique Paths II
        63. 不同路径 II
    Address:
        https://leetcode-cn.com/problems/unique-paths-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划 - 二维数组
/* 时间复杂度：O( rows*cols ), 空间复杂度：O( rows*cols ) */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 网格为空、左上角网格为障碍物
        if ( obstacleGrid.empty() || obstacleGrid[0][0] == 1 )  
            return 0;

        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<long>> dp( rows, vector<long>( cols ) );

        dp[0][0] = 1;
        for ( int row = 1; row < rows; ++row )  // 初始化「第 1 列」
            if ( obstacleGrid[row][0] == 1 )
                dp[row][0] = 0;
            else  
                dp[row][0] = dp[row - 1][0];
        
        for ( int col = 1; col < cols; ++col )  // 初始化「第 1 行」
            if ( obstacleGrid[0][col] == 1 )
                dp[0][col] = 0;
            else
                dp[0][col] = dp[0][col - 1];
        
        for ( size_t row = 1; row < rows; ++row ) {
            for ( size_t col = 1; col < cols; ++col ) {
                if ( obstacleGrid[row][col] == 1 )
                    dp[row][col] = 0;
                else
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};


int main()
{
    

    return 0;
}