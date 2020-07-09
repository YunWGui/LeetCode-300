/*
Title:
	46. Permutations
	46. 全排列
Description:
    给定一个没有重复数字的序列，返回其所有可能的全排列。
Address:
    https://leetcode-cn.com/problems/permutations/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：回溯法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        backTrack( res, nums, 0 );

        return res;
    }

    void backTrack( vector<vector<int>>& res, vector<int>& nums, int pos ) {
        if ( pos == nums.size() ) {
            res.push_back( nums );
            return;
        }

        for ( int i = pos; i < nums.size(); ++i ) {
            swap( nums[pos], nums[i] );
            backTrack( res, nums, pos + 1 );
            swap( nums[pos], nums[i] );
        }
    }
};

int main()
{
    vector<int> vec { 1, 2, 3 };
    Solution solve;
    vector<vector<int>> res = solve.permute( vec );

    for ( auto num : res ) {
        for ( auto e : num )
            cout << e << " ";
        cout << endl;
    }


	return 0;
}
