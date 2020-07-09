/*
Title:
    912. Sort an Array
    912. 排序数组
Address:
    https://leetcode-cn.com/problems/sort-an-array/
*/  

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法二：计数排序
// https://mp.weixin.qq.com/s/QGXaSJY_-MkFN53mXnnmQQ
class Solution_2 {
private:
    int hashCount[100001] = {0};
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res;
        res.reserve( nums.size() );
        for ( auto v: nums ) {
            ++hashCount[v+50000];
        }
        for ( int i = 0; i <= 100000; ++i ) {
            while ( hashCount[i] > 0 ) {
                hashCount[i] -= 1;
                res.push_back( i - 50000 );
            }
        }

        return res;
    }
};

// 方法三：基数排序
class Solution_3 {
  public:
    vector<int> sortArray(vector<int> &nums) {
        for (int i = 0, n = nums.size(); i < n; ++i)
            nums[i] += 50000;

        vector<int> data[2][10];
        for (auto v : nums)
            data[0][v % 10].push_back(v);

        int pre = 1, now = 0;
        for (int i = 1, d = 8, div = 10; i <= d; ++i, div *= 10) {
            swap(pre, now);
            for (int j = 0; j < 10; ++j)
                data[now][j].resize(0);

            for (int j = 0; j < 10; ++j)
                for (auto v : data[pre][j])
                    data[now][v / div % 10].push_back(v);
        }

        int top = 0;
        for (int i = 0; i < 10; ++i)
            for (auto v : data[now][i])
                nums[top++] = v - 50000;

        return nums;
    }
};

// 方法一：快速排序
/*
    平均时间复杂度：O(nlogn)，最好情况：O(nlogn)，最坏情况：O(nlogn)
    空间复杂度：O(logn)
    In-place 排序，不稳定
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        quickSort( nums, low, high );

        return nums;
    }

    void quickSort( vector<int>& nums, int low, int high ) {
        if ( low < high ) {
            int pivotIndex = partition( nums, low, high );

            quickSort( nums, low, pivotIndex - 1 );
            quickSort( nums, pivotIndex + 1, high );
        }
    }

    int partition( vector<int>& nums, int low, int high ) {
        int pivot = nums[high];
        int i = low - 1;

        for ( int j = low; j < high; ++j ) {
            if ( nums[j] <= pivot ) {
                ++i;
                swap( nums[i], nums[j] );
            }
        }
        swap( nums[i+1], nums[high] );
        
        return i + 1;
    }
};

int main()
{
    

    return 0;
}