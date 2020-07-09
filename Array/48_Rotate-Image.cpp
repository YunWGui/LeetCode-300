/*
Title:
    48. Rotate Image
    48. 旋转图像
Address:
    https://leetcode-cn.com/problems/rotate-image/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法三：旋转四个矩阵「改进」
class Solution_3 {
public:
    void rotate(vector<vector<int>>& matrix) {
		int N = matrix.size();
		
		for ( int i = 0; i < N / 2 + N % 2; ++i ) {
			for ( int j = 0; j < N / 2; ++j ) {
				int temp[4];
				int row = i;
				int col = j;
				for ( int k = 0; k < 4; ++k ) {
					temp[k] = matrix[row][col];
					int x = row;
					row = col;
					col = N - 1 - x;
				}
				for ( int k = 0; k < 4; ++k ) {
					matrix[row][col] = temp[(k + 3) % 4];
					int x = row;
					row = col;
					col = N - 1 - x;
				}
			}
		}
    }
};

// 方法二：转置 + 翻转
class Solution_2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        if ( matrix.empty() )
            return;
        
        int N = matrix.size();
        for ( int i = 1; i < N; ++i ) {
            for ( int j = 0; j < i; ++j ) {
                swap( matrix[i][j], matrix[j][i] );
            }
        }
        // 遍历每一行，并反转
        for ( int row = 0; row < N; ++row ) 
            reverse( matrix[row].begin(), matrix[row].end() );
    }
};

// 方法一：旋转四个矩形
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if ( matrix.empty() )
            return;
            
        int N = matrix.size();
        int i = 0, j = 0;
        while ( 2 * i < N ) {
            j = i;
            while ( j < N - 1 - i ) {
                vector<vector<int>> vec {
                    { i, j }, { j, N - 1 - i }, { N - 1 - i, N - 1 - j }, { N - 1 - j, i }
                };
                int previous = matrix[vec[3][0]][vec[3][1]];

                for ( auto v: vec ) {
                    swap( previous, matrix[v[0]][v[1]] );
                    // int temp = matrix[v[0]][v[1]];
                    // matrix[v[0]][v[1]] = previous;
                    // previous = temp;
                }
                ++j;
            }
            ++i;
        }
    }
};


int main()
{


    return 0;
}