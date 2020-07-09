/*
Title:
    118. Pascal's Triangle
    118. 杨辉三角
Address:
    https://leetcode-cn.com/problems/pascals-triangle/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一: 动态规划
// 时间复杂度: O( numRows^2 ), 空间复杂度: O( numRows^2 )
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
        // 分别判断 numRows == 0, 1, 2 三种情况
    	if (numRows == 0)
			return res;

        res.push_back( { 1 } );
        if ( numRows == 1 )
            return res;

        res.push_back( { 1, 1 } );
        if ( numRows == 2 )
            return res;

		for (int i = 2; i < numRows; ++i) {  // i : 表示 res 的行数, i = [0, 1, ... , n - 1]
            vector<int> temp(i + 1, 1);  // 第 i 行有 i + 1 个元素
            for (int j = 1; j < i; ++j) {
                temp[j] = res[i - 1][j - 1] + res[i - 1][j];
		    }
            res.push_back(temp);
	    }

        return res;
    }
};

int main()
{


    return 0;
}
