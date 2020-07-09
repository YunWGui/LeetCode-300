/*
Title:
    79. Word Search
    79. 单词搜索
Address:
    https://leetcode-cn.com/problems/word-search/
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 方法一：回溯法、深度优先搜索
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		if ( board.empty() || word.empty() )
			return false;

        for ( int row = 0; row < (int)board.size(); ++row )
            for ( int col = 0; col < (int)board[0].size(); ++col )
                if ( dfs( board, word, row, col, 0 ) )
                    return true;

        return false;
    }

    bool dfs( vector<vector<char>>& board, string& word, int row, int col, int index ) {
        if ( row < 0 || row >= (int)board.size() || col < 0 || col >= (int)board[0].size() )
            return false;

		if ( board[row][col] != word[index] )
			return false;
		// 由上一个 if 推断出，此时 board[row][col] == word[index]
        if ( index == (int)word.size() - 1 )
            return true;

        char temp = board[row][col];
        board[row][col] = '*';
        bool res = dfs( board, word, row - 1, col, index + 1 )
                || dfs( board, word, row + 1, col, index + 1 )
                || dfs( board, word, row, col - 1, index + 1 )
                || dfs( board, word, row, col + 1, index + 1 );
        board[row][col] = temp;

        return res;
    }
};


int main()
{


	return 0;
}
