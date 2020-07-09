/*
Title:
    130. Surrounded Regions
    130. 被围绕的区域
Address:
    https://leetcode-cn.com/problems/surrounded-regions/
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// 方法三：并查集
class Union_Find {  // 定义并查集
private:
    int cnt;
    vector<int> parent;
    vector<int> rank;
public:
    Union_Find( int n ) : parent( vector<int> ( n ) ), rank( vector<int>( n , 1 ) ) {
        cnt = n;
        for ( int i = 0; i < n; ++i ) 
            parent[i] = i;
    }

    void to_union( int p, int q ) {
        int rootP = find( p );
        int rootQ = find( q );

        if ( rootP == rootQ )
            return;
        
        if ( rank[rootP] > rank[rootQ] ) {
            parent[rootQ] = rootP;
            rank[rootP] += rank[rootQ];
        } else {
            parent[rootP] = rootQ;
            rank[rootQ] += rank[rootP];
        }

        --cnt;
    }

    bool connected( int p, int q ) {
        int rootP = find( p );
        int rootQ = find( q );

        return rootP == rootQ;
    }

    int find( int x ) {
        while ( parent[x] != x ) {
            parent[x] = parent[ parent[x] ];  // 路径压缩
            x = parent[x];
        }

        return x;
    }

    int count() {
        return cnt;
    }    
};

class Solution_3 {
public:
    void solve(vector<vector<char>>& board) {
        if ( board.empty() )
            return;
        
        int rows = board.size(), cols = board[0].size();

        Union_Find uf( rows * cols + 1 );
        for ( int row = 0; row < rows; ++row ) {
            for ( int col = 0; col < cols; ++col ) {
                if ( row == 0 || row == rows - 1 || col == 0 || col == cols - 1 ) {
                    // 为 parent[ rows * cols ] 为所有边界节点的「父节点」
                    uf.to_union( row * cols + col, rows * cols );
                    continue;
                }

                char ch = board[row][col];  // ch 在数组内部
                // 将 ch 四周与它相同的字符连接起来
                if ( board[row - 1][col] == ch )  // 左
                    uf.to_union( (row - 1) * cols + col, row * cols + col );
                if ( board[row + 1][col] == ch )  // 右
                    uf.to_union( (row + 1) * cols + col, row * cols + col );
                if ( board[row][col - 1] == ch )  // 上
                    uf.to_union( row * cols + (col - 1), row * cols + col );
                if ( board[row][col + 1] == ch )  // 下
                    uf.to_union( row * cols + (col + 1), row * cols + col );
            }
        }

        for ( int row = 0; row < rows; ++row ) {
            for ( int col = 0; col < cols; ++col ) {
                // 当该节点没有与「所有边界节点的父节点」相连接，
                // 表明其内的 'O' 构成了一个封闭区间
                if ( board[row][col] == 'O' 
                     && !uf.connected( row * cols + col, rows * cols ) )
                    board[row][col] = 'X';
            }
        }
    }
};

// 方法一：深度优先搜索
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if ( board.empty() )
            return;

        int rows = board.size(), cols = board[0].size();

        // 左、右边界
        for ( int row = 0; row < rows; ++row ) {
            if ( board[row][0] == 'O' )  // 左边界
                markOpen( row, 0, rows, cols, board );
            if ( board[row][cols - 1] == 'O' )  // 右边界
                markOpen( row, cols - 1, rows, cols, board );
        }
        // 上、下边界
        for ( int col = 1; col < cols - 1; ++col ) {
            if ( board[0][col] == 'O' )  // 上边界
                markOpen( 0, col, rows, cols, board );
            if ( board[rows - 1][col] == 'O' )  // 下边界
                markOpen( rows - 1, col, rows, cols, board );
        }

        for ( int row = 0; row < rows; ++ row ) {
            for ( int col = 0; col < cols; ++col ) {
                if ( board[row][col] == 'O' )
                    board[row][col] = 'X';
                else if ( board[row][col] == 'N' )  // 此处不能用 if ，因为会与上一条 if 语句「冲突」
                    board[row][col] = 'O';
            }
        }
    }
    // 将与边界连通的 'O' 标记为 'N'
    void markOpen( int row, int col, int rows, int cols, vector<vector<char>>& board ) {
        if ( row < 0 || row >= rows || col < 0 || col >= cols )  // 越界
            return;
        if ( board[row][col] != 'O' )  // 非 'O'，因为此时 board 内存在 'O', 'X', 'N' 三种字符
            return;

        board[row][col] = 'N';

        markOpen( row - 1, col, rows, cols, board );  // 左
        markOpen( row + 1, col, rows, cols, board );  // 右
        markOpen( row , col - 1, rows, cols, board );  // 上
        markOpen( row , col + 1, rows, cols, board );  // 下
    }
};


// 方法二：广度优先搜索
struct position {
    int row, col;
    void set( int r, int ch ) { row = r; col = ch; }
    position( int r, int ch ) : row ( r ), col ( ch ) {   }
};

class Solution_2 {
public:
    void solve(vector<vector<char>>& board) {
        if ( board.empty() )
            return;
        
        int rows = board.size(), cols = board[0].size();

        queue<position> Q;
        position p( 0, 0 );

        // 左、右边界
        for ( int row = 0; row < rows; ++row ) {
            if ( board[row][0] == 'O' ) {  // 左
                board[row][0] = 'N';
                p.set( row, 0 );
                Q.push( p );
            }
            if ( board[row][cols - 1] == 'O' ) {
                board[row][cols - 1] = 'N';
                p.set( row, cols - 1 );
                Q.push( p );
            }
        }

        // 上、下边界
        for ( int col = 1; col < cols; ++col ) {
            if ( board[0][col] == 'O' ) {
                board[0][col] = 'N';
                p.set( 0, col );
                Q.push( p );
            }
            if ( board[rows - 1][col] == 'O' ) {
                board[rows - 1][col] = 'N';
                p.set( rows - 1, col );
                Q.push( p );
            }
        }

        while ( !Q.empty() ) {
            p = Q.front();
            Q.pop();
            int row = p.row;
            int col = p.col;

            if ( row < rows - 1 && board[row + 1][col] == 'O' ) {
                board[row + 1][col] = 'N';
                p.set( row + 1, col );
                Q.push( p );
            }
            if ( row > 0 && board[row - 1][col] == 'O' ) {
                board[row - 1][col] = 'N';
                p.set( row - 1, col );
                Q.push( p );
            }
            if ( col < cols - 1 && board[row][col + 1] == 'O' ) {
                board[row][col + 1] = 'N';
                p.set( row, col + 1 );
                Q.push( p );
            }
            if ( col > 0 && board[row][col - 1] == 'O' ) {
                board[row][col - 1] = 'N';
                p.set( row, col - 1 );
                Q.push( p );
            }
        }

        for ( int row = 0; row < rows; ++row ) {
            for ( int col = 0; col < cols; ++col ) {
                if ( board[row][col] == 'O' )
                    board[row][col] = 'X';
                else if ( board[row][col] == 'N' )
                    board[row][col] = 'O';
            }
        }
    }
};


int main()
{


	return 0;
}
