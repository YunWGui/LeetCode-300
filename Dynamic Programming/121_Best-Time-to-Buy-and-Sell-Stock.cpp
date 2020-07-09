/**
 * Title:
 *      121. Best Time to Buy and Sell Stock
 *      121. 买卖股票的最佳时机
 * Address:
 *      https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * Tips:
 *      同 《剑指offer》63 题
 *      https://www.acwing.com/problem/content/79/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.empty() )
            return 0;
            
        int res = 0;
        int curMin = prices[0];
        for ( size_t cell = 1; cell < prices.size(); ++cell ) {
            curMin = min( curMin, prices[cell] );
            res = max( res, prices[cell] - curMin );
        }

        return res;
    }
};

// 方法二：动态规划
class Solution_2 {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() <= 1 )
            return 0;
        
        int minPrice = prices[0];
        int maxPrice = prices[1] - minPrice;

        for ( size_t cell = 2; cell < prices.size(); ++cell ) {
            if ( prices[cell - 1] < minPrice )
                minPrice = prices[cell - 1];
            
            int curPrice = prices[cell] - minPrice;
            if ( maxPrice < curPrice )
                maxPrice = curPrice;
        }

        return maxPrice > 0 ? maxPrice : 0;
    }
};


int main()
{
    

    return 0;
}