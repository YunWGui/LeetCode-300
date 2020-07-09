/*
Title:
	239. Sliding Window Maximum
    239. 滑动窗口最大值
Address:
    https://leetcode-cn.com/problems/sliding-window-maximum/submissions/
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 方法一：单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> Q;

        for ( int i = 0; i < nums.size(); ++i ) {
            if ( !Q.empty() && i - Q.front() >= k )
                Q.pop_front();

            while ( !Q.empty() && nums[Q.back()] < nums[i] )
                Q.pop_back();

            Q.push_back( i );

            if ( i >= k-1 )
                res.push_back( nums[Q.front()] );
        }

        return res;
    }
};


// 方法二：单调队列
// https://mp.weixin.qq.com/s/GqehrBu9m7qf5FgFqlV-Uw
class MonotonicQueue {  // 维护一个「单调队列」
private:
    deque<int> data;
public:
    void push( int val ) { 
        while ( !data.empty() && data.back() < val )
            data.pop_back();
        data.push_back( val );
    }

    int max() {
        return data.front();
    }

    void pop( int val ) {
        if ( !data.empty() && data.front() == val )
            data.pop_front();
    }
};

class Solution_2 {
public:
    vector<int> maxSlidingWindow( vector<int>& nums, int k ) {
        MonotonicQueue window;
        vector<int> res;
        for ( size_t i = 0; i < nums.size(); ++i ) {
            if ( i < k - 1 )  // 先填满窗口的前 k - 1
                window.push( nums[i] );
            else {  // 窗口向前滑动
                window.push( nums[i] );
                res.push_back( window.max() );
                window.pop( nums[i - k + 1] );
            }
        }

        return res;
    }
};


int main()
{


	return 0;
}
