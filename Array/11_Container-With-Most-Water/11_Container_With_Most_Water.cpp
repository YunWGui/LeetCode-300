/*
Title:
	11. Container With Most Water
	11. 盛水最多的容器
Address:
	https://leetcode-cn.com/problems/container-with-most-water/
*/



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 解法一： 暴力循环
class Solution{
public:
	int maxArea(vector<int>& height){
		if(height.size() <= 1)
			return -1;

		int maxValue = 0, area = 0;

		for(int i = 0; i < height.size()-1; i++)
			for(int j = i+1; j < height.size(); j++){
				area = min(height[i], height[j]) * (j - i);
				maxValue = max(maxValue, area);
			}
		return maxValue;
	}
};

// 解法二：双指针
// 思路：(1)：两线段之间形成的区域总是会受到其中较短那条长度的限制。
//       (2)：两线段距离越远，得到的面积就越大
class Solution_2{
public:
	int maxArea(vector<int>& height){
		if(height.size() <= 1)
			return -1;

		int i = 0, j = height.size()-1, maxValue = 0;
		while(i < j){
			int h = min(height[i], height[j]);
			maxValue = max(maxValue, h * (j - i));
			if(height[i] < height[j])
				++i;
			else
				--j;
		}
		return maxValue;
	}
};




int main()
{
	vector<int> nums{1, 8, 6, 2, 5, 4, 8, 3, 7};

	Solution solve;
	cout << solve.maxArea(nums) << endl;

	// cout << "The max value is: " << maxArea(nums) << endl;


	return 0;
}
