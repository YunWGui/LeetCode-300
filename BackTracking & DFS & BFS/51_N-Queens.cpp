/*
Title:
    51. N-Queens
    52. N 皇后
Address:
    https://leetcode-cn.com/problems/n-queens/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：回溯法
// 参考：https://mp.weixin.qq.com/s/nMUHqvwzG2LmWA9jMIHwQQ
class Solution {
private:
    vector<vector<string>> res;

public: 
    /* 输入棋盘边长 n，返回所有合法的放置 */
    vector<vector<string>> solveNQueens(int n) {
        // '.' : 表示空，'Q' : 表示皇后，初始化为空棋盘
        vector<string> board( n, string( n, '.' ) );
        
        backTrack( board, 0 );

        return res;
    }

    // 路径：board 中小于 row 的那些「行」已经成功放置了皇后
    // 选择列表：第 row 行的所有「列」都是放置皇后的选择
    // 结束条件：row 超过 board 的最后一行
    void backTrack( vector<string>& board, int row ) {
        // 触发「结束条件」
        if ( row == board.size() ) {
            res.push_back( board );
            return;
        }

        int cols = board[0].size();
        for ( int col = 0; col < cols; ++col ) {
            // 排除「不合法」选择
            if ( !isValid( board, row, col ) )
                continue;
            // 做选择
            board[row][col] = 'Q';
            // 进入下一行决策
            backTrack( board, row + 1 );
            // 撤销选择
            board[row][col] = '.';
        }
    }
    /* 是否可以在 board[row][col] 放置皇后？ */
    bool isValid( vector<string>& board, int row, int col ) {
        int cols = board[0].size();
        // 检查「列」是否有皇后互相冲突
        for ( int i = 0; i < row; ++i )
            if ( board[i][col] == 'Q' )
                return false;
        // 检查「右上方」是否有皇后互相冲突
        for ( int i = row - 1, j = col + 1; i >= 0 && j < cols; --i, ++j )
            if ( board[i][j] == 'Q' )
                return false;
        // 检查「左上方」是否有皇后互相冲突
        for ( int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j )
            if ( board[i][j] == 'Q' )
                return false;
        
        return true;
    }
};


int main()
{
	int n { 4 };
 	Solution solve;
	vector<vector<string>> res = solve.solveNQueens( n );

	for ( int i = 0; i < (int)res.size(); ++i ) {
		for ( int j = 0; j < (int)res[0].size(); ++j ) {
			cout << res[i][j] << endl;
		}
		cout << endl;
	}

    return 0;
}