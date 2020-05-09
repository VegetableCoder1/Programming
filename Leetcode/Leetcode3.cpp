/*
3. 无重复字符的最长子串
abcabcbb ==> abc/bca/cab...
bbbbb ==> b
pwwkew ==> wke/kew

[思路]模拟一遍abcabcbb的过程就直到该怎么做了
a ==> ab ==> abc ==> a重复，从第一个a的下一个位置作为起点，bca ==> b重复，从第一个a的下一个位置作为起点，cab ==> ...
即需要一个容器可以记录元素和它上一次出现的下标位置，因此使用哈希表
*/
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s);
int main()
{
    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s)<<endl;
}
int lengthOfLongestSubstring(string s)
{
    int len = s.size();
    if(len == 0) return 0;
    int pos = 0;
    int start = 0;
    int curres = 0;
    int res = 0;
    unordered_map<char,int> m;
    while(pos<len)
    {
        char temp = s[pos];
        //仅当s[start,end) 中存在s[end]时更新start,修改当前长度
        if( m.count(temp)!=0 && m[temp]>=start)
        {
            start = m[temp]+1;
            curres = pos - start;
        }
        m[temp] = pos++;
        curres++;
        res = max(curres,res);
    }
    return res;
}