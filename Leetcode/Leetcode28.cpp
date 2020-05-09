/*
实现substr
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

[思路]KMP算法（状态机解法）
KMP算法永不退回haystack的指针i，而是借助辅助数组存储的信息把needle移动到正确的位置继续匹配
核心是构造状态机，通过状态机的转移状态来确定needle的正确位置

*/

#include<bits/stdc++.h>
using namespace std;
// 构造字符映射表和状态转移表
set<char> ss;
int dp[26][26];
void state_machine_table(string s,string pat)
{
	
	int len1 []= s.length();
	int len2 = pat.length();
	//map<key,value> 由于map方便通过map[key]找，其余均要用到迭代器，这里就建立两个map，方便双向搜索
    //个人感觉这里使用make_pair()打包更好
	map<int,char> m;
	map<char,int> M;
	int count1 = 1;
	int count2 = 1;
	for(int i=0;i<len1;i++)
	{
		ss.insert(s[i]);
	}
	set<char>::iterator iter = ss.begin();
	for(;iter!=ss.end();iter++)
	{
		m[count1++] = *iter;
		M[*iter] = count2++;
	}
	cout<<"------字符映射表------"<<endl; 
	for(int i=1;i<count1;i++)
	{
		cout<<i<<"---"<<m[i]<<endl; 
	}
	// 开始构建状态机
	// dp[][]的前一个坐标记录当前状态，后一个坐标记录转移条件（字符映射），值记录下一状态 
	// dp[0][]表示初始状态 统一记录为0 
	int X = 0;
	dp[0][M[pat[0]]] = 1; // 初始状态下，字符为s[0]才能进入状态 1 
	for(int j=1;j<len2;j++) 
	{
		for(int k=1;k<count1;k++) //顺序遍历字符映射 
		{
			if(m[k] == pat[j]) //推进状态，当前转移条件正好是字符串的下一个字符 
			{
				dp[j][k] = j+1; 
			}
			else //状态重启，委托影子状态X计算重启位置 
			{
				dp[j][k] = dp[X][k];
			}
		} 
		//找字符串中第j个字符对应的map映射 但是为什么呢？ 
		X = dp[X][M[pat[j]]];
	}
	cout<<"------状态转移表------"<<endl;
	cout<<"  - ";
	for(int j=1;j<count1;j++)
	{
		cout<<m[j]<<" ";
	} 
	cout<<endl;
	for(int j=0;j<len2;j++) 
	{
		cout<<j<<" ";
		for(int k=0;k<count1;k++) //顺序遍历字符映射 
		{
			cout<<dp[j][k]<<" ";
		}
		cout<<endl;
	}
}
// 将txt字符走状态转移表，寻找匹配
int search(string txt,string pat)
{
	int len_txt = txt.length();
	int len_pat = pat.length();
	int j = 0;
	for(int i=0;i<len_txt;i++)
	{
		// 计算pat的下一个状态 
		j = dp[j][M[txt[i]]];
		if(j == len_pat) //到达最终状态
		{
			return i-len_pat+1;
		}
	} 	
	return -1;
} 
int main()
{

}