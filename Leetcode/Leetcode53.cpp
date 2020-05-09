/*
最大子序列的和

【思路1】动态规划的方法
【思路2】分治法
*/

#include<bits/stdc++.h>
using namespace std;
// 分治法
int maxSubArray(vector<int> &nums)
{
	//类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
	int result = INT_MIN;
	int numsSize = int(nums.size());
	result = maxSubArrayHelper(nums, 0, numsSize - 1);
	return result;
}
int maxSubArrayHelper(vector<int> &nums, int left, int right)
{
	if (left == right)
	{
		return nums[left];
	}
	int mid = (left + right) / 2;
	int leftSum = maxSubArrayHelper(nums, left, mid);
	//注意这里应是mid + 1，否则left + 1 = right时，会无线循环
	int rightSum = maxSubArrayHelper(nums, mid + 1, right);
	int midSum = findMaxCrossingSubarray(nums, left, mid, right);
	int result = max(leftSum, rightSum);
	result = max(result, midSum);
	return result;
}
// 从mid向两边寻找，找出跨越分界线的最大数组值
int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
{
	int leftSum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= left; i--)
	{
		sum += nums[i];
		leftSum = max(leftSum, sum);
	}

	int rightSum = INT_MIN;
	sum = 0;
	//注意这里i = mid + 1，避免重复用到nums[i]
	for (int i = mid + 1; i <= right; i++)
	{
		sum += nums[i];
		rightSum = max(rightSum, sum);
	}
	return (leftSum + rightSum);
}

// 动态规划
int maxSubArray1(vector<int>& nums)
{
	int ans = nums[0];
	int sum = 0;
	for(int i=0; i<nums.size(); i++)
	{
		if(sum>0) sum+=nums[i];
		else sum = nums[i];
		ans = max(ans,sum);
	}
	return ans;
}

int main()
{

}