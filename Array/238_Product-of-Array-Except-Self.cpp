/*
Title:
    238. Product of Array Except Self
    238. 除自身以外数组的乘积
Address: 
    https://leetcode-cn.com/problems/product-of-array-except-self/
Tips:
    同《剑指offer》第 66 题
    https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
/* 时间复杂度：O(n) 
思路：由定义 B[i] = A[0] X A[1] X ... X A[i - 1] X A[i + 1] X ... X[n - 1]
      将上式拆解，有：C[i] = A[0] X A[i] X ... A[i - 1], D[i] = A[i + 1] X A[i + 2] X ... X[n - 1]
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if ( nums.empty() )
            return vector<int>{};
        
        int length = nums.size();
        // 辅助数组
        vector<int> Left( length ), Right( length );
        Left[0] = 1;
        for ( int i = 1; i < length; ++i )
            Left[i] = Left[i - 1] * nums[i - 1];
        
        Right[length - 1] = 1;
        for ( int j = length - 2; j >= 0; --j )
            Right[j] = Right[j + 1] * nums[j + 1];
        
        vector<int> output( length );
        for ( int k = 0; k < length; ++k )
            output[k] = Left[k] * Right[k];
    
        return output;
    }
};

// 方法二：只使用两个数组
class Solution_2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if ( nums.empty() )
            return vector<int>{};
        
        int length = nums.size();
        vector<int> output( length );
        output[0] = 1;

        for ( int i = 1; i < length; ++i )
            output[i] = output[i - 1] * nums[i - 1];
        
        int R = 1;
        for ( int j = length - 1; j >= 0; --j ) {
            output[j] = output[j] * R;
            R *= nums[j];  // 累乘
        }
    
        return output;
    }
};

int main()
{
    

    return 0;
}