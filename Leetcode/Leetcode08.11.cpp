/*
给定整数n 从25，10，5，1选择任意数字组成n 一共有多少种方法

动态规划的思想，最后加入了优化过程

原始dp：dp[i][j] = dp[i+1][j] + dp[i+1][j-qian[i]] + dp[i+1][j-2*qian[i]] + ...
我们可以发现：dp[i][j-qian[i]] = dp[i+1][j-qian[i]] + dp[i+1][j-2*qian[i]] + ...
因此有 
dp[i][j] = dp[i+1][j] + dp[i][j-qian[i]] (j-qian[i]>=0)
dp[i][j] = dp[i+1][j] (j-qian[i]<0)

   i\j 10  9  8  7  6  5  4  3  2  1  0
25  0   4  0  0  0  0  0  0  0  0  0  1
10  1   4  2  2  2  2  2  1  1  1  1  1
5   2   3  2  2  2  2  2  1  1  1  1  1
1   3   1  1  1  1  1  1  1  1  1  1  1
    4   0  0  0  0  0  0  0  0  0  0  1

*/

#include <bits/stdc++.h>
using namespace std;
int waysToChange(int n);
int main()
{
}

int waysToChange(int n)
{
    int qian[4] = {25, 10, 5, 1};
    vector<vector<int>> dp(5);
    for (int i = 0; i < 5; i++)
    {
        dp[i].resize(n + 1, 0);
    }
    for (int i = 0; i < 5; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (j - qian[i] >= 0)
            {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - qian[i]]) % 1000000007;
            }
            else
            {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }
    return (dp[0][n]) % 1000000007;
}