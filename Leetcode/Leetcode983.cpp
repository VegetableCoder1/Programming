/*
983.最低票价
你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
火车票有三种不同的售票方式：
一张为期一天的通行证售价为 costs[0] 美元；
一张为期七天的通行证售价为 costs[1] 美元；
一张为期三十天的通行证售价为 costs[2] 美元。

输入：days = [1,4,6,7,8,20], costs = [2,7,15]
输出：11

[思路]贪心 + 动态规划
如果第i天没有出行计划，则dp[i] = dp[i-1]
如果第i天有出现计划，则dp[i] = min(dp[i-1]+cost[0],dp[i-7]+cost[1],dp[i-30]+cost[2])
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

}
int mincostTickets(vector<int>& days, vector<int>& costs) 
{
    vector<int> dp(days.back()+1,0);
    vector<bool> travel(days.back()+1,false);
    for(auto i:days)
        travel[i]=true;
    int len = dp.size();
    for(int i=1;i<len;i++)
    {
        if(travel[i] == false)
        {
            dp[i] = dp[i-1];
        }
        else
        {
            dp[i] = min(min(costs[0] + getdp(i-1,dp), costs[1] + getdp(i-7,dp)), costs[2] + getdp(i-30,dp));
        }
    }
    return dp.back();
}
int getdp(int index, vector<int>& dp)
{
    if(index<0)
        return 0;
    else
        return dp[index];        
}
