/*
11. 盛水最多的容器

给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

输入：[1,8,6,2,5,4,8,3,7]
输出：49

[思路]左右双指针，慢慢向中间逼近，寻找最优解。哪边小就移动哪边，左右相遇时退出循环
有一点点贪心的思想，不过不好证明
*/

# include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height);
int main()
{

}
int maxArea(vector<int>& height)
{
    if(height.size()<=1) return 0;
    int left = 0;
    int right = height.size()-1;
    int max_area = 0;
    while(left<right)
    {
        int current_area = min(height[left],height[right])*(right-left);
        max_area = max(max_area,current_area);
        if(height[left]<height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return max_area;
}