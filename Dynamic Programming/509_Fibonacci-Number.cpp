/*
    509. Fibonacci Number
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int fib(int N) {
        if ( N == 0 )        
            return 0;
        if ( N== 1 )
            return 1;

        vector<int> res( N+1, 0 );
        res[0] = 0;
        res[1] = 1;
        
        for ( int i = 2; i <= N; ++i ) 
            res[i] = res[i-1] + res[i-2];

        return res[N];
    }
};

// 方法二：动态规划，基于「方法一」的改进
class Solution_2 {
public:
    int fib(int N) {
        vector<int> res { 0, 1 };
        if ( N < 2 )
            return res[N];
        
        int fibOne = 0;
        int fibTwo = 1;
        int ans = 0;
        for ( int i = 2; i <= N; ++i ) {
            ans = fibOne + fibTwo;
            fibOne = fibTwo;
            fibTwo = ans;
        }

        return ans;
    }
};




int main()
{
    

    return 0;
}