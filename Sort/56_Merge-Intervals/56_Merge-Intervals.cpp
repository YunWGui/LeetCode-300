/**
 * Titile:
 *      56. Merge Intervals
 *      56. 合并区间
 * Address:
 *      https://leetcode-cn.com/problems/merge-intervals/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：排序
// https://leetcode-cn.com/problems/merge-intervals/solution/he-bing-qu-jian-by-leetcode-solution/
/**
 * 思路：
 *      1、将列表中的区间按照左端点升序排序。然后将第一个区间加入 res 数组中，并按照
 *         顺序依次考虑之后的每个区间。
 *      2.1、如果当前区间的左端点在数组 res 中最后一个区间的右端点之后，那么它们不会
 *           重合，可以直接将这个区间加入数组 res 末尾
 *      2.2、否则，它们重合，需要用当前区间的右端点更新数组 res 中最后一个区间的右端
 *           点，将其置为二者的较大值。
 * 复杂度分析：
 *      时间复杂度 O(nlogn)，其中 n 为区间的数量。除去排序的开销，只需要一次线性扫描，
 *          所以主要的时间开销是排序 O(nlogn)
 *      空间复杂度 O(nlogn)，其中 n 为区间的数量。这里计算的是存储答案之后，使用的额
 *          外空间。O(nlogn) 即为排序所需要的空间复杂度
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if ( intervals.size() <= 1 )
            return intervals;
        
        sort( intervals.begin(), intervals.end() );

        vector<vector<int>> res;
        for ( int i = 0; i < intervals.size(); ++i ) {
            int curLeftVal = intervals[i][0], curRightVal = intervals[i][1];
            
            if ( res.empty() || res.back()[1] < curLeftVal ) {
                res.push_back( { curLeftVal, curRightVal } );
            }
            else {
                res.back()[1] = max( res.back()[1], curRightVal );
            }
        }

        return res;        
    }
};

int main()
{
    

    return 0;
}