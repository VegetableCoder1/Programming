/*
编写一个函数来查找字符串数组中的最长公共前缀。

水平扫描法，依次向后传递公共子串，遍历完成即求得公共子串
*/
// 时间复杂度O(n)
#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
	if(strs.size()==0) return "";
	if(strs.size()==1) return strs[0];
	string common = strs[0];
	for(int i=1; i<strs.size(); i++)
	{
		common = findcommon(common,strs[i]);
		cout<<common<<endl; 
		if(common == "") break;
	}
	return common;
}
string findcommon(string s1,string s2)
{
	int l1 = s1.size();
	int l2 = s2.size();
	int len = l1<l2?l1:l2;
	int pos = 0;
	for(int i=0; i<=len; i++)
	{
		if(i==len)
		{
			pos = len;
			break;
		}
		if(s1[i]!=s2[i])
		{
			pos = i;
			break;
		}
	}
	return s1.substr(0,pos);
}
int main()
{
    
}