/*
790.多米诺与托米诺平铺
有两种形状的瓷砖：一种是 2x1 的多米诺形"I"，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。
给定 N 的值，有多少种方法可以平铺 2 x N 的面板？返回值 mod 10^9 + 7。

[思路] 递推关系即可
N = 0 f(0) = 1  
N = 1 f(1) = 1 
N = 2 f(2) = 2 
N = 3 f(3) = 5
N = 4 f(4) = f(3) + f(2) + 2f(1) + 2f(0)
N = 5 f(5) = f(4) + f(3) + 2f(2) + 2f(1) + 2f(0)

f(n) = f(n-1) + f(n-2) + 2(f(n-3) + f(n-4) + ... + f(0))
f(n-1) = f(n-2) + f(n-3) + 2(f(n-4) + ... + f(0))
==> f(n) = 2*f(n-1) + f(n-3)
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

}
int numTilings(int N)
{
    int mod = 1000000007;
    vector<int> dp(N+3,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i=4;i<=N;i++)
    {
         dp[i] = (2*(dp[i-1] % mod) % mod + dp[i-3] % mod) % mod;
    }
     return dp[N] % mod;
}