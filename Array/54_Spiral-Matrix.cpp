/*
    54. Spiral Matrix
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法一：
/* 时间复杂度：O(nm)  空间复杂度：O(1) */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) 
            return ans; // 若数组为空，直接返回答案

        // 赋值上下左右边界
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        
        while( true ) {
            for(int i = left; i <= right; ++i) 
                ans.push_back(matrix[top][i]); // 向右移动直到最右
            
            if(++top > bottom) break; // 重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            
            for(int i = top; i <= bottom; ++i) 
                ans.push_back(matrix[i][right]); // 向下
            
            if(--right < left) break; // 重新设定右边界
            
            for(int i = right; i >= left; --i) 
                ans.push_back(matrix[bottom][i]); // 向左
            
            if(--bottom < top) break; // 重新设定下边界
            
            for(int i = bottom; i >= top; --i) 
                ans.push_back(matrix[i][left]); // 向上
            
            if(++left > right) break; // 重新设定左边界
        }
        
        return ans;
    }
};


int main()
{
    

    return 0;
}