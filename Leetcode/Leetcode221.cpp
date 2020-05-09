/*
211. 最大正方形
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

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
            ans = max(dp[i][j],ans);
        }
    }
    return ans*ans;
}