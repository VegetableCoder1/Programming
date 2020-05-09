/*
格雷码
给定整数n 返回从0开头的格雷码排列 长度为2^n

镜像法：
观察如下格雷码：
0
0 1
00 01 11 10
000 001 011 010 110 111 101 100

n阶格雷码G(n),n+1阶格雷码G(n+1)
G(n+1) = ['0' + G[0:n/2-1], '1' + G[n/2:n-1]]
且 G[n/2:n-1] 为 G[0:n/2-1]的镜像]

延申到这个题
0：[0]
1：得到[0]的镜像，加2^0，再与[0]合并得到[0,1]
2: 得到[0,1]的镜像[1,0],加2^1,再与[0,1]合并得到[0,1,3,2]
...
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> grayCode(int n);
int main()
{

}
vector<int> grayCode(int n)
{
    int shift = 1;
    vector<int> res;
    while(n>=0)
    {
        if(res.size()==0)
        {
            res.push_back(0);
        }
        else
        {
            for(int i=shift-1;i>=0;--i)
            {
                res.push_back(res[i]+shift);
            }
            shift *= 2;
        }
        n--;
    }
    return res;
}