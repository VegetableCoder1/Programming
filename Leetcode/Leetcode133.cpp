/*
133. 只出现一次的数字
时间复杂度O(n) 空间复杂度O(1)

[思路] 异或的思想
两个相同的数，xor值为0，a xor 0 = a
因此这个数组只有一个数只出现了一次，因此全部异或就可以了

进阶：Leetcode137
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

}
int singleNumber(vector<int>& nums)
{
    int ans = 0;
    for(int a:nums)
    {
        ans = ans ^ a;
    }
    return ans;
}