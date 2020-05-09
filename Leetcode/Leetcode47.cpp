/*
全排列 返回不重复的所有排列

[思路] 在回溯的过程中进行减枝
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vc;
int main()
{
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    if (nums.size() == 0)
        return vc;
    int len = nums.size();
    permutehelp(nums, 0, len);
    return vc;
}
void permutehelp(vector<int> &nums, int start, int end)
{
    if (start == end)
    {
        vc.push_back(nums);
        return;
    }
    unordered_set<int> uniq;
    for (int i = start; i < end; i++)
    {
        if (uniq.count(nums[i]))
        {
            continue;
        }
        swap(nums, start, i);
        permutehelp(nums, start + 1, end);
        swap(nums, start, i);
        uniq.insert(nums[i]);
    }
}
void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}