/*
Title:
	15. 3Sum
	15. 三数之和
Address:
	https://leetcode-cn.com/problems/3sum/
*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int> > &matrix){
    for(int i=0; i<matrix.size(); i++){
        printf("{");
        for(int j=0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        printf("}\n");
    }
    cout << endl;
}

// 双指针
class Solution{
public:
	vector<vector<int>> threeSum(vector<int>& nums){
		sort(nums.begin(), nums.end());  // 对数组排序
		vector<vector<int>> res;
		int len = nums.size();
		if(len < 3 || nums.front() > 0 || nums.back() < 0)
			return res;
		for(int i = 0; i < len -2; i++){
			if(i > 0 && nums[i] == nums[i - 1])	continue;  // 去掉重复值，下同
			int low = i + 1, high = len - 1;
			while(low < high){
				int sum = nums[i] + nums[low] + nums[high];
				if(sum < 0)
					low++;
				else if(sum > 0)
					high--;
				else{
					res.push_back({nums[i], nums[low], nums[high]});
					while(low < high && nums[low] == nums[low + 1])
						low++;
					while(low < high && nums[high] == nums[high - 1])
						high--;
					low++;
					high--;
				}
			}
		}
		return res;
	}
};

// class Solution{
// public:
// 	vector<vector<int>> threeSum(vector<int> &num) {
//
//     vector<vector<int>> result;
//     if (num.size() == 0 || num.size() == 1 || num.size() == 2)
//         return result;
//
//     // sort the array, this is the key
//     sort(num.begin(), num.end());
//
//     int n = num.size();
//
//     for (int i = 0; i < n - 2; i++) {
//         // skip the duplication
//         if (i > 0 && num[i - 1] == num[i])
//             continue;
//         int a = num[i];
//         int low = i + 1;
//         int high = n - 1;
//         while (low < high) {
//             int b = num[low];
//             int c = num[high];
//             if (a + b + c == 0) {
//                 // got the soultion
//                 vector<int> v;
//                 v.push_back(a);
//                 v.push_back(b);
//                 v.push_back(c);
//                 result.push_back(v);
//                 // Continue search for all triplet combinations summing to zero.
//                 // skip the duplication
//                 while (low < n - 1 && num[low] == num[low + 1])
//                     low++;
//                 while (high > 0 && num[high] == num[high - 1])
//                     high--;
//                 low++;
//                 high--;
//             } else if (a + b + c > 0) {
//                 // skip the duplication
//                 while (high > 0 && num[high] == num[high - 1])
//                     high--;
//                 high--;
//             } else {
//                 // skip the duplication
//                 while (low < n - 1 && num[low] == num[low + 1])
//                     low++;
//                 low++;
//             }
//         }
//     }
//     return result;
// }
// };


int main()
{
	// vector<int> nums1 {-1, 0, 1, 2, -1, -4};
	// vector<int> nums1 {-2, 0, 1, 1, 2};
	vector<int> nums1 {0, 0, 0};
	Solution solve;
	vector<vector<int>> result;

	result = solve.threeSum(nums1);

	printMatrix(result);


	// print(nums);


	return 0;
}
