/*
S1=[s1,n1] 、S2=[s2,n2]
请你找出一个可以满足使[S2,M] 从 S1 获得的最大整数 M 
即 从 s1s1s1s1s1s1s1s1... 中找最长的 s2s2s2s2...

【思路1】暴力就完事了，全过程只用遍历一次S1字符串,超时（java不会超时） 28/41
【思路2】从超时的原因分析，s1中存在很多多余的字符串，去除以后再来利用思路1的方法 31/41
【思路3】在循环里面做优化。n1与n2可能会很大，而且具有重复性，因此需要找循环节。即k个s1可以找出一个s2
        只要求出k,那么就可以很轻易的根据给定的数目求出M。

        url: https://www.cnblogs.com/grandyang/p/6149294.html

        s1 = abacb , s2 = bcaa;
        nextIndex表示在一个s1的重复片段中，找寻s2的第nextIndex个字符串
        S1 --------------> abacb | abacb | abacb | abacb | abacb | abacb ...
        search-----------> _b_c_ | a_a_b | ___c_ | a_a_b | ___c_ | a_a_b ...
        repeatCount ----->    0  |   1   |   1   |   2   |   2   |   3   ...
        nextIndex ------->    2  |   1   |   2   |   1   |   2   |   1   ...

        我们从上述的手动推到过程中发现 重复的 nextIndex 出现在第三段，和第一段一样都为2，那么重复的 pattern 就找到了，是第二段和第三段中的 aabc
        由于 pattern 占用了两段，所以 interval 为2，然后看整个 S1 中有多少个这样的两段，repeat = (n1 - start) / interval。
        start 表示 pattern 的起始段数，之前的不是 pattern，然后算在整个 S1 中有多少个 pattern 出现，

        ==> 一般情况
        repeatCnt ==> 记录 前k段中s2的个数；nextIndex ==> 记录 在下一段中寻找找寻s2的哪个字符串。
        每次搜寻下一段之前，检查一下是否存在重复，

        如果存在重复,按照以下情况分析
        计算重复的interval，当前为第k段，遍历到第start段，发生重复: interval = k - start;
        计算重复的interval个数: repeat = (n1 - start) / interval;
        计算一个interval中重复的s2的个数: patternCnt = (repeatCount[k] - repeatCount[start]);
        计算所有interval中重复的s2的个数: patternCnt = patternCnt*repeat;
        算出剩下的非 pattern 的字符串里能包含几个s2: remainCnt = repeatCount[start + (n1 - start) % interval];
        （最后剩下的 加上 start之前的看作一个新的串，在repeatCount中找到对应答案就行了）

        如果不存在重复
        如果 pattern 未曾出现，那么我们直接用 repeatCnt[n1] / n2 也能得到正确的结果，参见代码如下：

*/

#include<bits/stdc++.h>
using namespace std;
int getMaxRepetitions1(string s1, int n1, string s2, int n2);
int getMaxRepetitions2(string s1, int n1, string s2, int n2);
int getMaxRepetitions3(string s1, int n1, string s2, int n2);
int main()
{

}
int getMaxRepetitions1(string s1, int n1, string s2, int n2)
{
    int index = 0;
    int cnt = 0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<s1.size();j++)
        {
            if(s1[j] == s2[index])
            {
                index++;
            }
            if(index == s2.size())
            {
                index = 0;
                ++cnt;
            }
        }
    }
    return cnt/n2;
}
int getMaxRepetitions2(string s1, int n1, string s2, int n2)
{
    unordered_map<char,int> m2;
    for(int i=0;i<s2.size();i++)
    {
        m2[s2[i]] = 1;
    }
    string s3 = "";
    for(int i=0;i<s1.size();i++)
    {
        if(m2.count(s1[i])==1)
        {
            s3+=s1[i];
        }
    }
    int index = 0;
    int cnt = 0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<s3.size();j++)
        {
            if(s3[j] == s2[index])
            {
                index++;
            }
            if(index == s2.size())
            {
                index = 0;
                ++cnt;
            }
        }
    }
    return cnt/n2;
}
int getMaxRepetitions3(string s1, int n1, string s2, int n2)
{
    vector<int> repeatCnt(n1 + 1, 0);
    vector<int> nextIdx(n1 + 1, 0);
    int j = 0, cnt = 0;
    //k表示段数，i表示s1的下标，j表示s2的下标
    for (int k = 1; k <= n1; k++)
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s2[j])
            {
                j++;
                if (j == s2.size())
                {
                    j = 0;
                    cnt++;
                }
            }
        }
        repeatCnt[k] = cnt; //记录下前k段中s2的个数
        nextIdx[k] = j;
        for (int start = 0; start < k; start++)
        {
            //如果存在重复的nextIndex
            if (nextIdx[start] == j)
            {
                int interval = k - start;
                int repeat = (n1 - start) / interval;
                int patternCnt = (repeatCnt[k] - repeatCnt[start]) * repeat;
                // 一定可以在repeatCnt中找到remainCnt的答案
                int remainCnt = repeatCnt[start + (n1 - start) % interval];
                return (patternCnt + remainCnt) / n2;
            }
        }
    }
    return repeatCnt[n1] / n2;
}