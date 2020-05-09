/*
全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> permute(vector<int>& nums);
void permutehelp(vector<int>& nums,int start,int end);
void swap(vector<int>& nums,int i,int j);
vector<vector<int>> vc;
int main()
{

}
vector<vector<int>> permute(vector<int>& nums)
{
    if(nums.size() == 0) return vc;
    int len = nums.size();
    permutehelp(nums,0,len);
    return vc;

}
void permutehelp(vector<int>& nums,int start,int end)
{
    if(start == end)
    {
        vc.push_back(nums);
        return;
    }
    for(int i=start;i<end;i++)
    {
        swap(nums,start,i);
        permutehelp(nums,start+1,end);
        swap(nums,start,i);
    }
}
void swap(vector<int>& nums,int i,int j)
{
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}