/*
26. 删除顺序数组中的重复元素
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

[思路]双指针法。快指针j用来遍历数组，慢指针i用来在原数组中顺序插入不同的值。
*/
#include<bits/stdc++.h>
using namespace std;
// 时间复杂度O(n) 空间复杂度O(1)
int removeDuplicates(vector<int>& nums)
{
	int len = nums.size();
	int i = 0;int j = 0;
	while(j<len)
	{
		int current = nums[i];
		if(nums[j]!=current)
		{
			nums[++i] = nums[j];
		}
		j++;
	} 
	return i;
}
int main()
{
    
}