/*
跳跃游戏II
给定一个非负整数数组，你最初位于数组的第一个位置
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

[2,3,1,1,4] == 2

[思路1] 动态规划，不出所料的最后一个用例超时了 jump1()
[思路2] 贪心，贪就完事了,每一步都尽可能走的更远
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{

}
int jump1(vector<int> &nums)
{
    int len = nums.size();
    if (len <= 1)
        return 0;
    vector<int> dp(len, INT_MAX - 1);
    dp[len - 1] = 0;
    for (int i = len - 2; i >= 0; i--)
    {
        for (int j = 1; j <= nums[i] && i + j < len; j++)
        {
            dp[i] = min(dp[i], dp[i + j] + 1);
        }
    }
    return dp[0];
}
int jump2(vector<int> &nums)
{
    int len = nums.size();
    if (len <= 1) return 0;
    int end = 0; // 当前跳跃的边界
    int maxposition = 0; // 可能到达的最远的边界
    int step = 0;
    for(int i=0;i<len-1;i++)
    {
        maxposition = max(maxposition,i+nums[i]);
        if(i == end)
        {
            end = maxposition;
            step++;
        }
    }
    return step;
}