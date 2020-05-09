/*
372.超级次方
你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

[思路]以快速幂为基础
x^[a,b,c] = (x^c)*x^[a,b,0] = (x^c)*(x^[a,b])^10 = (x^c)*(x^10)^b*(x^100)^a
从低位开始 先用快速幂算x^c 然后用快速幂算x^10
*/
#include<bits/stdc++.h>
using namespace std;
int K = 1377;
int quickpow(int e,int n)
{
    int ans = 1;
    int this_x = e;
    while(n>0)
    {
        if(n%2==1)
        {
            ans = ((ans%K)*(this_x%K))%K;
        }
        this_x = ((this_x%K)*(this_x%K))%K;
        n/=2;
    }
    return ans;
}
int superPow(int a, vector<int>& b) 
{
    int res = 1;
    int firstpow = 1;
    int secondpow = 1;
    for(int i=b.size()-1;i>=0;i--)
    {
        firstpow = quickpow(a,b[i]) % K;
        res = (res%K)*(firstpow);
        a = quickpow(a,10) % K;
    }
    return res%K;
}

int main()
{

}