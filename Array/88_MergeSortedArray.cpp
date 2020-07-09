/*
Title:
    88. 
Description:
    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
    one sorted array.
    
    Note:
    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to
    m + n) to hold additional elements from nums2.
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：从前往后排序
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if ( m == 0 ) {
            swap( nums1, nums2 );
            return;
        }            
        if ( n == 0 )
            return;
        
        int i = 0, j = 0;
        int k = 0;
        
        // 整体向后移 n 个单位
        i = m - 1;
        while ( i > -1 )  {
            nums1[n+i] = nums1[i];  // 从 nums1 的最后一个字符开始从后往前移
            --i;
        }
            
        i = n;
        while ( i < (m + n) && j < n ) {  // 此时 i == m
            if ( nums1[i] < nums2[j] )
                nums1[k++] = nums1[i++];
            else
                nums1[k++] = nums2[j++];
        }

        while ( j < n )
            nums1[k++] = nums2[j++];
    }
};

// 方法二：从后往前排序
// 所以当 nums1 先遍历完成时，将 nums2 剩余的数依次复制到 nums1 对应的位置即可；
// 当 nums2 先遍历完成时，不用做任何操作。
class Solution_2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m + n - 1;
        --m;
        --n;
        while(0 <= m && 0 <= n){
            if(nums1[m] > nums2[n]){
                nums1[end--] = nums1[m--];
            } else {
                nums1[end--] = nums2[n--];
            }
        }
        while( -1 < n ){
            nums1[end--] = nums2[n--];
        }
    }
};


int main()
{
    Solution solve;
    vector<int> arr1 {1, 2, 3, 7, 10,0, 0, 0, 0, 0, 0};
    vector<int> arr2 {4, 5, 9, 11, 13, 15};
    solve.merge(arr1, 5, arr2, 6);
    // vector<int> arr1 {0};
    // vector<int> arr2 {1};

    // solve.merge(arr1, 4, arr2, 2);
    // print(arr1);

    return 0;
}
