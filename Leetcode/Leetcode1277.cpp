/*
1277. 统计全为1的正方形子矩阵
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

[思路]动态规划
一个n*n的正方形可以看成3个n-1*n-1的正方形加上右下角的值构成的（三个正方形相互重叠）
因此我们可以定义状态(i，j)表示从以(i，j)为右下角的正方形中的最大矩形的边长
递推关系：（i,j) = min( (i-1,j),(i,j-1),(i-1,j-1) ) + 1
边界条件：矩阵第一行与第一列的元素 (i,j) = 原始矩阵的对应元素值
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{

}
int countSquares(vector<vector<int>>& matrix) 
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row,vector<int>(col,0));
    int ans = 0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = matrix[i][j];
            }
            else if(matrix[i][j]!=0)
            {
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
            ans += dp[i][j];
        }
    }
    return ans;
}