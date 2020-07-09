/*
Title:
    260. Single Number III
    260. 只出现一次的数字 III
Address: 
    https://leetcode-cn.com/problems/single-number-iii/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// 方法一：哈希表
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> M;
        vector<int> res;

        if ( nums.size()  < 2 )
            return res;

        for ( int num : nums )
            ++M[num];

        for ( auto iter = M.begin(); iter != M.end(); ++iter )
            if ( iter->second == 1 )
                res.emplace_back( iter->first );
        
        return res;
    }
};


int main()
{
    

    return 0;
}