/*
Title:
    52. N-Queens II
    52. N皇后 II
Address:
    https://leetcode-cn.com/problems/n-queens-ii/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：回溯法
// 参考：https://mp.weixin.qq.com/s/nMUHqvwzG2LmWA9jMIHwQQ

class Solution {
private:
    int count = 0;
public:
    int totalNQueens(int n) {
        vector<string> board( n, string( n, '.' ) );

        backTrack( board, 0 );

        return count;
    }

    void backTrack( vector<string>& board, int row ) {
        if ( row == board.size() ) {
            ++count;
            return;
        }

        int cols = board[0].size();
        for ( int col = 0; col < cols; ++col ) {
            if ( !isValid( board, row, col ) )
                continue;
            
            board[row][col] = 'Q';

            backTrack( board, row + 1 );

            board[row][col] = '.';
        }
    }

    bool isValid( vector<string>& board, int row, int col ) {
        int cols = board[row].size();
        
        for ( int i = 0; i < row; ++i )
            if ( board[i][col] == 'Q' )
                return false;
        
        for ( int i = row - 1, j = col + 1; i >= 0 && j < cols; --i, ++j )
            if ( board[i][j] == 'Q' )
                return false;
        
        for ( int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j )
            if ( board[i][j] == 'Q' )
                return false;
        
        return true;
    }
};


int main()
{
    

    return 0;
}