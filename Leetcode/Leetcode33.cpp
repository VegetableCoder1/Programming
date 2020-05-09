/*
33. 搜索旋转数组
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
要求时间复杂度为logN

[思路] 题目给出了二分搜索的方向 根据数据的分布 我们可以得到以下结论
[4 5 6 7 0 1 2]  mid = 3; nums[3]>nums[lo] 说明左边部分有序
[6 7 0 1 2 4 5]  mid = 3; nums[3]<nums[lo] 说明右边部分有序
target是否在有序部分里面可以通过区间端点值判断，进而可以下一次搜索的区间
*/
# include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target);
int main()
{
    vector<int> vc;
    vc.push_back(0);
    // vc.push_back(5);
    // vc.push_back(6);
    // vc.push_back(7);
    // vc.push_back(0);
    // vc.push_back(1);
    // vc.push_back(2);
    cout<<search(vc,0)<<endl;
}
int search(vector<int>& nums, int target)
{
    if(nums.size() == 0) return -1;
    int lo = 0;
    int hi = nums.size()-1;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(nums[mid] == target) return mid;
        // 左半边有序,
        if(nums[lo] <= nums[mid])
        {
            if(nums[mid]>target && nums[lo]<=target)
            {
                hi = mid - 1;
                continue;
            }
            else
            {
                lo = mid + 1;
                continue;
            }
        }
        else
        {
            if(nums[mid]<target && nums[hi]>=target)
            {
                lo = mid + 1;
                continue;
            }
            else
            {
                hi = mid - 1;
                continue;
            }
        }
    }
    return -1;
}