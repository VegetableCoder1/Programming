/*
137. 只出现一次的数字II
除了某个元素只出现一次以外，其余每个元素均出现了三次。
nums = [3,5,3,3]
3 = 0 0 1 1
3 = 0 0 1 1
3 = 0 0 1 1
5 = 0 1 0 1
统计各位1的个数，结果对3求余即为答案
x = 0 1 3 4 = 0 1 0 1 = 5

进阶 Leetcode260.cpp
*/
#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    { // 确定每一位
        int sum = 0;
        for (int num : nums)
        {
            sum += (num >> i) & 1; // 统计当前位置有多少个元素
        }
        ans ^= (sum % 3) << i; // 还原到第i位
    }
    return ans;
}
