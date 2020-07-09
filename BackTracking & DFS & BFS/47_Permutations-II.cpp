/*
Title:
    47. Permutations II
    47. 全排列
Description:
    给定一个可包含重复数字的序列，返回所有不重复的全排列。
Address:
    https://leetcode-cn.com/problems/permutations-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
			// [pos, i) 之间有数字等于 nums[i]
			if ( judge( nums, pos, i ) )
                continue;

            swap( nums[pos], nums[i] );
            backTrack( res, nums, pos + 1 );
            swap( nums[pos], nums[i] );
        }
    }

    bool judge( vector<int>& nums, int start, int end ) {
        for ( int i = start; i < end; ++i )
            if ( nums[i] == nums[end] )
                return true;

        return false;
    }
};

int main()
{


	return 0;
}
