/*
    循环码排列：
    给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：
    p[0] = start
    p[i] 和 p[i+1] 的二进制表示形式只有一位不同
    p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同

    【思路】
    首先生成从0开头的格雷码，然后找到start的位置,将[0:start-1]位置翻转到数组最尾部即可
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> circularPermutation(int n, int start)
{
    vector<int> init = grayCode(n);
    int pos = -1;
    vector<int> res;
    for (int i = 0; i < init.size(); i++)
    {
        if (init[i] == start)
        {
            pos = i;
            res.push_back(init[i]);
            continue;
        }
        if (pos >= 0)
        {
            res.push_back(init[i]);
        }
    }
    for (int i = 0; i < pos; i++)
    {
        res.push_back(init[i]);
    }
    return res;
}

vector<int> grayCode(int n)
{
    int shift = 1;
    vector<int> res;
    while (n >= 0)
    {
        if (res.size() == 0)
        {
            res.push_back(0);
        }
        else
        {
            for (int i = shift - 1; i >= 0; --i)
            {
                res.push_back(res[i] + shift);
            }
            shift *= 2;
        }
        n--;
    }
    return res;
}