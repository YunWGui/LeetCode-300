/*
Title:
    204. Count Primes
    204. 计数质数
Description:
    Count the number of prime numbers less than a non-negative number, n.
Address: 
    https://leetcode-cn.com/problems/count-primes/
*/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// 方法一：埃拉托色尼筛选法 ( Sieve of Eratosthenes )
/*   
思路：
    质数（素数）：大于 1 的自然数中，除了 1 和它本身以外，不能再被其他数整除。
    如果一个数能被其他数「整除」，即：target = x * y，此时 x, y 互为倍数关系

时间复杂度：O( N * loglogN )
*/
class Solution {
public:
    int countPrimes(int n) {
        // vector<bool> isPrimes( n, true );  // 创建一个 bool 数组，速度更「慢」
        bool isPrimes[n + 1];
        for ( int i = 0; i < n; ++i )
            isPrimes[i] = true;
            
        for ( int i = 2; i <= sqrt(n); ++i ) {  // 因子具有「对称性」，故只需遍历 [2, sqrt(n)] 即可
            if ( isPrimes[i] )
                for ( int j = i * i; j < n; j += i )  // i 的倍数不可能是质数
                    isPrimes[j] = false;
        }

        int count = 0;
        for ( int i = 2; i < n; ++i )  // 统计所有「小于」 n 的质数的数量
            if ( isPrimes[i] )
                ++count;
        
        return count;
    }
};


int main()
{
    

    return 0;
}