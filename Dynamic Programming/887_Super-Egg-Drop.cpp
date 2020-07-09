/*
Title:
    887. Super Egg Drop
    887. 鸡蛋掉落
Address: 
    https://leetcode-cn.com/problems/super-egg-drop/
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法一：
// https://leetcode-cn.com/problems/super-egg-drop/solution/887-by-ikaruga/
class Solution {
public:
    int superEggDrop(int K, int N) {
        int chance = 1;  // 机会

        while ( calaF( chance, K ) < N + 1 )
            ++chance;
        
        return chance;
    }

    int calaF( int chance, int K ) {
        if ( chance == 1 || K == 1 )
            return chance + 1;
        
        return calaF( chance - 1, K - 1 ) + calaF( chance - 1, K );
    }
};

int main()
{
    

    return 0;
}