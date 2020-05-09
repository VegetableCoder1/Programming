/*
实现pow(x,n)

[思路]快速幂算法
快速幂算法的本质就是分治算法，如计算x^64,只需要计算x,x^2,x^4,x^8,x^16,x^32,x^64
通过快速幂算法，只需要计算七次乘法

方法一：快速幂 + 递归
以x^77为例，x,x^2,x^4,x^9,x^19,x^38,x^77
发现有的在做幂的时候多乘了一个x，从前往后很难说明，所以可以从后往前使用递归的方法

方法二 快速幂 + 迭代
77 = 1001101 = 2^64 + 2^8 + 2^4 + 1
x^77 = x^64 * x^8 * x^4 * x
通过1轮循环，每次循环都让x乘以自身，然后根据二进制位选择需要的位数对应的幂
*/
#include<bits/stdc++.h>
using namespace std;


/*
快速幂 + 递归
*/
double quickMul(double x,long long N)
{
    if(N == 0) return 1.0;
    double y = quickMul(x,N/2);
    return N%2==0? y*y : y*y*x;
}
double myPow1(double x, int n) 
{
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}

// 快速幂
double myPow1(double x, long long N) 
{
    double ans = 1.0;
    // 贡献的初始值为 x
    double x_contribute = x;
    while(N>0)
    {
        if(N%2==1)
        {
            // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
            ans *= x_contribute;
        }
        x_contribute*=x_contribute;
        N/=2;
    }
    return ans;
}

int main()
{

}
































