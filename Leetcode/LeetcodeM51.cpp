/*
面试题51  数组中的逆序对
【思路1】暴力法，超时 时间复杂度O(n^2)
【思路2】归并的思路 寻找左边逆序对 + 右边逆序对 +  跨越中间的逆序对
*/
#include <bits/stdc++.h>
using namespace std;
int reversePairs(vector<int> &nums);
int mergesort(vector<int> &nums, vector<int> tmp, int l, int r);
int cnt = 0;
int main()
{
    vector<int> vc;
    vc.push_back(7);
    vc.push_back(5);
    vc.push_back(6);
    vc.push_back(4);
    cout<<reversePairs(vc)<<endl;
}
int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    if(n == 0) return 0;
    vector<int> tmp(n);
    return mergesort(nums, tmp, 0, n - 1);
}
// 这个版本的居然超时了
int mergesort(vector<int> &nums, vector<int> tmp, int l, int r)
{
    if (l == r)
        return 0;
    int mid = (l + r) / 2;
    int inv_count = mergesort(nums, tmp, l, mid) + mergesort(nums, tmp, mid + 1, r);
    int i = l, j = mid + 1, pos = l;
    while (i <= mid && j <= r)
    {
        if (nums[i] <= nums[j])
        {
            tmp[pos] = nums[i++];
            // nums[i]一定大于nums[j-1]及以前
            inv_count += (j - mid - 1);
        }
        else
        {
            tmp[pos] = nums[j];
            j++;
        }
        pos++;
    }
    for (int k = i; k <= mid; ++k)
    {
        tmp[pos++] = nums[k];
        inv_count += (j - (mid + 1));
    }
    for (int k = j; k <= r; ++k)
    {
        tmp[pos++] = nums[k];
    }
    copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
    return inv_count;
}

// 使用一个全局变量进行统计
void mergsort1(vector<int> nums, vector<int> tmp, int l, int r)
{
    if(l>=r) return;
    int mid = l + (r-l)/2;
    mergsort1(nums,tmp,l,mid);
    mergsort1(nums,tmp,mid+1,r);
    int i = l, j = mid+1;
    for(int k=l;k<r;k++)
    {
        if(i>mid) tmp[k] = nums[j++];
        else if(j>r) tmp[k] = nums[i++];
        else if(nums[i]>=nums[j])
        {
            tmp[k] = nums[j++];
            cnt += mid - i + 1;
        }
        else
        {
            tmp[k] = nums[i++];
        }
    }
    for(int m=l;m<=r;m++) nums[m]=tmp[m];//
}