/*
Title:
    137. Single Number II
    137. 只出现一次的数字 II
Address: 
    https://leetcode-cn.com/problems/single-number-ii/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 方法三：位运算 - 不懂
class Solution_3 {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for ( int num : nums ) {
            once = ( once ^ num ) & ( ~twice );
            twice = ( twice ^ num ) & ( ~once );
        }
        
        return once;
    }
};

// 方法二：位运算
class Solution_2 {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for ( int i = 0; i < 32; ++i ) {
            int count = 0;
            for( int num : nums ) 
                count += ( num >> i ) & 1;
            
            if ( count % 3 == 1 )
                res |= 1 << i;             
        }
       
        return res;
    }
};

// 方法一：哈希表
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> M;
        int res = 0;

        if ( nums.size() == 1 )
            return nums[0];
        
        for ( int num : nums )
            ++M[num];
        
        for ( auto iter = M.begin(); iter != M.end(); ++iter )
            if ( iter->second == 1 ) {
                res = iter->first;
                break;
            }

        return res;
    }
};

int main()
{
    

    return 0;
}