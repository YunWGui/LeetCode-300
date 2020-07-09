/*
Title:
    202. Happy Number
    202. 快乐数
Description:
    Write an algorithm to determine if a number n is "happy".
    A happy number is a number defined by the following process: Starting with 
    any positive integer, replace the number by the sum of the squares of its 
    digits, and repeat the process until the number equals 1 (where it will stay), 
    or it loops endlessly in a cycle which does not include 1. 
    Those numbers for which this process ends in 1 are happy numbers.
    Return True if n is a happy number, and False if not.
Address: 
    https://leetcode-cn.com/problems/happy-number/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// 方法二：双指针 - 快慢指针
class Solution_2 {
public:
    bool isHappy(int n) {
        int fast, slow;
        fast = slow = n;

        fast = nextNum( nextNum( fast ) );
        slow = nextNum( slow );

        while ( fast != slow ) {
            fast = nextNum( nextNum( fast ) );
            slow = nextNum( slow );
        }

        return slow == 1 ? true : false;
    }

    int nextNum( int n ) {
        int res = 0;
        while ( n > 0 ) {
            res += ( n % 10 ) * ( n % 10 );
            n /= 10;
        }

        return res;
    }
};

// 方法一：哈希表
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> M;
        
        int next = nextNum( n );
        ++M[n];

        while ( M[next] != 1 ) {
            ++M[next];
            next = nextNum( next );
        }

        return next == 1 ? true : false;
    }

    int nextNum( int n ) {
        int res = 0;
        while ( n > 0 ) {
            res += ( n % 10 ) * ( n % 10 );
            n /= 10;
        }
        return res;
    }
};

int main()
{
    

    return 0;
}