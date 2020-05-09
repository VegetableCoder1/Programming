/*
85. 最大矩形
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

[思路]把矩形的每一行看作是一个直方图，求解柱状图中的最大矩形
一行与之前的行对应数值累加，如果这一行对应位置为0，则直接记为0
每一行数据代表的含义，以这一行为底的时候，包括自己在内的上方的1的数量
1 0 1 1 -> 1 0 1 1 
1 1 1 1 -> 2 1 2 2 
1 1 1 0 -> 3 2 3 0 
最后一行求的的最大面积即为围成的最大子矩阵大小

换言之求解m*n的矩阵的最大面积，就是求1*n得最大矩形面积，然后2*n,3*n,...,一直求解到m*n
其中把矩阵得行数转化为直方图得形式表达

求解柱状图中的最大面积 用到了单调栈的结构
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{

}
// 求解直方图的最大矩形 左右最近最大值
int maxArea(vector<int>& matrix)
{
    if(matrix.size()==0) return 0;
    int len = matrix.size();
    int maxarea = 0;
    stack<int> s;
    for(int i=0;i<len;i++)
    {
        while(!s.empty() && matrix[i] <= matrix[s.top()]) 
        {
            // i就是右边最近的最大值
            int j = s.top(); 
            s.pop();
            int k = s.empty()?-1:s.top(); //左边最近的最大值
            int curArea = (i-k-1)*matrix[j];
            maxarea = max(curArea,maxarea);
        }
        s.push(i);
    }
    while(!s.empty())
	{
		int j = s.top();
		s.pop();
		int k = s.empty()?-1:s.top();
		// 左边界为k,右边界统一为数组的右边 
		int curArea = (len-k-1)*matrix[j];
		maxarea = max(maxarea,curArea);
	} 
	return maxarea;

}
// 求解矩阵中的最大矩形
int maximalRectangle(vector<vector<int>>& matrix) 
{
    if(matrix.size() == 0) return 0;
    int ans = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]!=0)
            {
                matrix[i][j] += matrix[i-1][j];
            }
        }
        int tmp = maxArea(matrix[i]);
        ans = max(ans,tmp);
    }
    return ans;
}
