# include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums);
int main()
{

}

// 超时
bool canJump1(vector<int>& nums)
{
    if(nums.size()<=1) return true;
    vector<bool> dp(nums.size(),false);
    dp[nums.size()-1] = true;
    for(int i=nums.size()-2;i>=0;i--)
    {
        if(nums[i] + i >= nums.size())
        {
            dp[i] = true;
            continue;
        }
        else
        {
            for(int k=0;k<=nums[i] && k+i < nums.size();k++)
            {
                dp[i] = dp[i] || dp[i+k];
            }
        }
    }    
    return dp[0];
}

// 优化上述的dp
// 如果near_index可以到达最后，那么任何可以到near_index的点都可以到达最后
// 迭代的过程中，不断向前推进near_index的距离
bool canJump2(vector<int>& nums)
{
    if(nums.size()<=1) return true;
    vector<bool> dp(nums.size(),false);
    dp[nums.size()-1] = true;
    int near_index = nums.size()-1;
    for(int i=nums.size()-2;i>=0;i--)
    {
        if(nums[i]>=near_index-i)
        {
            dp[i] = true;
            near_index = i;
        }
        else
        {
            dp[i] = false;
        }
    }    
    return dp[0];
}
