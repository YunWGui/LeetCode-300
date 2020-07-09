/*
Title:
    289. Game of Life
    289. 生命游戏
Address:
    https://leetcode-cn.com/problems/game-of-life/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法二：位运算
/*
思路：
    一个 int 有 32 bit，而 board 只用了一个 bit（只有 0 和 1），
    所以，可以利用其他空闲的 bit 位进行「原地修改」
*/
class Solution_2 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0 ; j < board[0].size(); j++) {
                int liveCellNums = 0;  // 统计八个相邻位置的「活」细胞数量
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) 
                        liveCellNums += ( board[nx][ny] & 1 ); // 只累加最低位，统计活细胞的数目
                }
                if(board[i][j] == 1) {  // 当前位置为「活」细胞
                    if(liveCellNums == 2 || liveCellNums == 3) 
                        board[i][j] |= 2;  // 使用第二个bit标记是否存活
                } else {  // 当前位置为「死」细胞
                    if(liveCellNums == 3) 
                        board[i][j] |= 2; // 使用第二个bit标记是否存活
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1; //右移一位，用第二bit覆盖第一个bit。
            }
        }
    }
};

// 方法一：复制原数组进行模拟
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> nums( board );

        for ( int row = 0; row < nums.size(); ++row ) 
            for ( int col = 0; col < nums[0].size(); ++col ) 
                    board[row][col] = isLive( nums, row, col );
        
    }

    int isLive( vector<vector<int>>& nums, int row, int col ) {
        int flag = 0;  // 默认该位置细胞状态「失活」

        if ( nums[row][col] == 0 ) {  // 该位置是「死」细胞
            int liveCellNums = cellNumbers( nums, row, col );
            
            if ( liveCellNums == 3 )  // 不需要考虑 != 3 的情况
                flag = 1;            
        }
        else {  // 该位置是「活」细胞
            int liveCellNums = cellNumbers( nums, row, col );
            
            if ( liveCellNums == 2 || liveCellNums == 3 )
                flag = 1;
        }
        
        return flag;
    }
    // 统计「活」细胞的数量
    int cellNumbers( vector<vector<int>>& nums, int row, int col ) {
        int liveCellNums = 0;
        int rows = nums.size(), cols = nums[0].size();

        if ( col - 1 >= 0 && nums[row][col - 1] == 1 )  // 左
            ++liveCellNums;
        if ( col + 1 < cols && nums[row][col + 1] == 1 )  // 右
            ++liveCellNums;
        if ( row - 1 >= 0 && nums[row - 1][col] == 1 )  // 上
            ++liveCellNums;
        if ( row + 1 < rows && nums[row + 1][col] == 1 )  // 下
            ++liveCellNums;
        if ( row - 1 >= 0 && col - 1 >= 0 && nums[row - 1][col - 1] == 1 )
            ++liveCellNums;
        if ( row + 1 < rows && col + 1 < cols && nums[row + 1][col + 1] == 1 )
            ++liveCellNums;
        if ( row - 1 >= 0 && col + 1 < cols && nums[row - 1][col + 1] == 1 )
            ++liveCellNums;
        if ( row + 1 < rows && col - 1 >= 0 && nums[row + 1][col - 1] == 1 )
            ++liveCellNums;
        
        return liveCellNums;       
    }    
};

int main()
{
    


    return 0;
}