/*
交点问题
给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2, Y2}），如果它们有交点，请计算其交点，没有交点则返回空值

线段的表示：(x1,y1) (x2,y2)
参数方程是最适合表示的形式
x = x1 + t(x2 - x1)   0<=t<=1
y = y1 + t(y2 - y1)   0<=t<=1

1. 两条线段不平行： (x2-x1)(y4-y3) - (x4-x3)(y2-y1) != 0
x1 + t1(x2 - x1)  =  x3 + t2(x4 - x3)
y1 + t1(y2 - y1)  =  y3 + t2(y4 - y3)
联立两个线段的参数方程, 得到t1 t2的解 ==>
t1 = (x3(y4-y3)+y1(x4-x3)-y3(x4-x3)-x1(y4-y3)) / ((x2-x1)(y4-y3) - (x4-x3)(y2-y1))
t2 = (x1(y2-y1)+y3(x2-x1)-y1(x2-x1)-x3(y2-y1)) / ((x4-x3)(y2-y1) - (x2-x1)(y4-y3))
判断交点是否在直线上 ==>
判断t1,t2是否在[0,1]之间即可

2. 两条线段平行 (x2-x1)(y4-y3) - (x4-x3)(y2-y1) = 0
两条线段不在一条直线上，不会有交点。
这两条线段在同一条直线上 ==> 即判断第二个线段的一个端点是否在 第一个线段所在的直线上 ==> (y2-y1)(x3-x1) = (y3-y1)(x2-x1)
如果在一条直线上，每个线段的两个端点是否在对方线段上,更新题目要求的最优解

3. 线段与x轴平行

4. 线段与y平行
*/

#include <bits/stdc++.h>
using namespace std;
bool inside(int x1, int y1, int x2, int y2, int xk, int yk);
void update(vector<double> &ans, double xk, double yk);
vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2);
int main()
{
}
// 判断 (xk, yk) 是否在「线段」(x1, y1)~(x2, y2) 上
// 这里的前提是 (xk, yk) 一定在「直线」(x1, y1)~(x2, y2) 上
bool inside(int x1, int y1, int x2, int y2, int xk, int yk)
{
    // 若与 x 轴平行，只需要判断 x 的部分
    // 若与 y 轴平行，只需要判断 y 的部分
    // 若为普通线段，则都要判断
    return (x1 == x2 || (min(x1, x2) <= xk && xk <= max(x1, x2))) && (y1 == y2 || (min(y1, y2) <= yk && yk <= max(y1, y2)));
}
void update(vector<double> &ans, double xk, double yk)
{
    // 将一个交点与当前 ans 中的结果进行比较
    // 若更优则替换
    if (!ans.size() || xk < ans[0] || (xk == ans[0] && yk < ans[1]))
    {
        ans = {xk, yk};
    }
}
vector<double> intersection(vector<int> &start1, vector<int> &end1, vector<int> &start2, vector<int> &end2)
{
    int x1 = start1[0], y1 = start1[1];
    int x2 = end1[0], y2 = end1[1];
    int x3 = start2[0], y3 = start2[1];
    int x4 = end2[0], y4 = end2[1];

    vector<double> ans;
    // 判断 (x1, y1)~(x2, y2) 和 (x3, y3)~(x4, y3) 是否平行
    if ((y4 - y3) * (x2 - x1) == (y2 - y1) * (x4 - x3))
    {
        // 若平行，则判断 (x3, y3) 是否在「直线」(x1, y1)~(x2, y2) 上
        if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1))
        {
            // 判断 (x3, y3) 是否在「线段」(x1, y1)~(x2, y2) 上
            if (inside(x1, y1, x2, y2, x3, y3))
            {
                update(ans, (double)x3, (double)y3);
            }
            // 判断 (x4, y4) 是否在「线段」(x1, y1)~(x2, y2) 上
            if (inside(x1, y1, x2, y2, x4, y4))
            {
                update(ans, (double)x4, (double)y4);
            }
            // 判断 (x1, y1) 是否在「线段」(x3, y3)~(x4, y4) 上
            if (inside(x3, y3, x4, y4, x1, y1))
            {
                update(ans, (double)x1, (double)y1);
            }
            // 判断 (x2, y2) 是否在「线段」(x3, y3)~(x4, y4) 上
            if (inside(x3, y3, x4, y4, x2, y2))
            {
                update(ans, (double)x2, (double)y2);
            }
        }
        // 在平行时，其余的所有情况都不会有交点
    }
    else
    {
        // 联立方程得到 t1 和 t2 的值
        double t1 = (double)(x3 * (y4 - y3) + y1 * (x4 - x3) - y3 * (x4 - x3) - x1 * (y4 - y3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
        double t2 = (double)(x1 * (y2 - y1) + y3 * (x2 - x1) - y1 * (x2 - x1) - x3 * (y2 - y1)) / ((x4 - x3) * (y2 - y1) - (x2 - x1) * (y4 - y3));
        // 判断 t1 和 t2 是否均在 [0, 1] 之间
        if (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0)
        {
            ans = {x1 + t1 * (x2 - x1), y1 + t1 * (y2 - y1)};
        }
    }
    return ans;
}
