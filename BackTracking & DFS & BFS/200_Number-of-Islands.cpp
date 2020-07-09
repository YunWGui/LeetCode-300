/*
Title:
    200. Number of Islands
    200. 岛屿数量
Address: 
    https://leetcode-cn.com/problems/number-of-islands/
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 方法一: 深度优先搜索 - DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if ( grid.empty() )
            return 0;

        int count = 0;
        int rows = grid.size(), cols = grid[0].size();

        for ( int row = 0; row < rows; ++row ) {
            for ( int col = 0; col < cols; ++col ) {
                if ( grid[row][col] == '1' ) {
                    ++count;
                    dfs( row, col, rows, cols, grid );
                }
            }
        }

        return count;        
    }

    void dfs( int row, int col, int rows, int cols, vector<vector<char>>& grid ) {   
        if ( row < 0 || row == rows || col < 0 || col == cols )
            return;

        if ( grid[row][col] == '0' )
            return;

        grid[row][col] = '0';

        dfs( row - 1, col, rows, cols, grid );  // 上
        dfs( row + 1, col, rows, cols, grid );  // 下
        dfs( row, col - 1, rows, cols, grid );  // 左
        dfs( row, col + 1, rows, cols, grid );  // 右
    }
};

// 方法二: 广度优先搜索 - BFS
class Solution_2 {
public:
    queue<pair<int, int>> neighbours;

    int numIslands(vector<vector<char>>& grid) {
        if ( grid.empty() )
            return 0;

        int count = 0;
        int rows = grid.size(), cols = grid[0].size();

        for ( int r = 0; r < rows; ++r ) {
            for ( int c = 0; c < cols; ++c ) {
                if ( grid[r][c] == '1' ) {
                    ++count;
                    grid[r][c] = '0';
                    bfs ( r, c, rows, cols, grid );
                }
            }
        }

        return count;
    }

    void bfs ( int r, int c, int rows, int cols, vector<vector<char>>& grid ) {
        neighbours.push( { r, c } );

        while ( !neighbours.empty() ) {
            auto temp = neighbours.front();  neighbours.pop();
            int row = temp.first, col = temp.second;

            if ( row - 1 >= 0 && grid[row - 1][col] == '1' ) {  // 左
                neighbours.push( { row - 1, col } );  // 加入「队列」
                grid[row-1][col] = '0';  // 置 0
            }

            if ( row + 1 < rows && grid[row + 1][col] == '1' ) {  // 右
                neighbours.push( { row + 1, col } ); 
                grid[row + 1][col] = '0';
            }

            if ( col - 1 >= 0 && grid[row][col - 1] == '1' ) {  // 上
                neighbours.push( { row, col - 1 } );
                grid[row][col - 1] = '0';
            }

            if ( col + 1 < cols && grid[row][col + 1] == '1' ) {  // 下
                neighbours.push( { row, col + 1 } );
                grid[row][col + 1] = '0';
            }
        }

        return;
    }
};

int main()
{
    

    return 0;
}