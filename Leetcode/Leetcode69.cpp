/*
x的平方根
实现 int sqrt(int x) 函数。

[思路1]二分搜索法：从0~x二分搜索
[思路2]牛顿迭代法
题目转化为求 y = x^2 - c 的零点
（x0,y0)对应的切线 y' = 2x0(x - x0) + y0，与x轴的交点 x1 = -y0/2x0 + x0 = (x0 + c/x0)/2
将x1作为新的迭代结果带入，直到两次迭代误差小于e
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

}
// 二分搜索法
int mySqrt1(int x)
{
    int l = 0, r = x, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

// 牛顿迭代法
int mySqrt2(int x)
{
    if(x == 0) return 0;
    double C=x,x0=x;
    while(true)
    {
        double xi = 0.5*(x0 +C/x0);
        if (fabs(x0 - xi) < 1e-7) 
        {
            break;
        }
        x0 = xi;
    }
    return int(x0);
}