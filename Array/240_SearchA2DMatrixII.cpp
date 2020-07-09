/*
Title:
    240. Search a 2D Matrix II
Note:
    同《剑指offer》第 4 题  P44
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty() )
            return false;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0, col = cols - 1;

        bool found = false;
        while ( row < rows && 0 <= col ) {
            if ( matrix[row][col] == target ) {
                found = true;
                break;
            }
            else if ( target < matrix[row][col] )
                --col;
            else 
                ++row;
        }

        return found;
    }
};

int main()
{    


    return 0;
}