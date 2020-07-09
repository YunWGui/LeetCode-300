/*
Title:
    37. Sudoku Solver
	37. 解数独
Address:
	https://leetcode-cn.com/problems/sudoku-solver/
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法一：回溯法
// 参考：https://mp.weixin.qq.com/s/VCirGskFGPln-S2LGFTgKg
class Solution {
public:
	void solveSudoku( vector<vector<char>>& board ) {
		backTrack( board, 0, 0 );  
	}

	bool backTrack( vector<vector<char>>& board, int row, int col ) {
		int rows = 9, cols = 9;
		if ( col == cols ) {
			// 穷举到最后一列，则换到下一行重新开始
			return backTrack( board, row + 1, 0 );
		}

		if ( row == rows ) {
			// 找到一个可行解，触发 base case
			return true;
		}

		// 对棋盘的「每个位置」进行穷举
		for ( int i = row; i < rows; ++i ) {
			for ( int j = col; j < cols; ++j ) {
				// 如果该位置是预设的数字，则跳过
				if ( board[i][j] != '.' ) {
					return backTrack( board, i, j + 1 );
				}

				for ( char ch = '1'; ch <= '9'; ++ch ) {
					// 如果遇到「不合法」的数字，就跳过
					if ( !isValid( board, i, j, ch ) )
						continue;

					// 做选择
					board[i][j] = ch;
					// 继续穷举下一个
					if ( backTrack( board, i, j + 1 ) )
						return true;
					// 撤销选择
					board[i][j] = '.';
				}
				// 穷举完 1 ~ 9，依然没有找到可行解，此路不通
				return false;
			}
		}
		return false;
	}

	/* 判断 board[i][j] 是否可以填入 cols */
	bool isValid( vector<vector<char>> board, int row, int col, char n ) {
		for ( int i = 0; i < 9; ++i ) {
			// 判断在 row 「行」中，是否存在「重复」
			if ( board[row][i] == n )
				return false;
			// 判断在 col 「列」中，是否存在「重复」
			if ( board[i][col] == n )
				return false;
			// 判断「 3 X 3 方框」是否存在「重复」
			if ( board[ ( row / 3 ) * 3 + i / 3 ][ ( col / 3 ) * 3 + i % 3 ] == n )
				return false;
		}

		return true;
	}
};


int main()
{
    

    return 0;
}