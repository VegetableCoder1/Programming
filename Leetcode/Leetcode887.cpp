/*
你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑
每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去
你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
*/



#include <bits/stdc++.h>
using namespace std;
int superEggDrop(int K, int N);
int process(int K,int N);
unordered_map< pair<int,int> , int> m;
int main()
{
    cout<<process(2,6)<<endl;
}
int process(int K,int N)
{
    int  curmax = 0;
    if(K == 1) return N; //只剩1个鸡蛋，只能一层一层的去尝试
    if(N == 0) return 0; //楼层用完了，返回0
    if(m.count(make_pair(K,N))!=0) return m[make_pair(K,N)];
    for(int i = 0;i < N; i++)
    {
        int temp = max(process(K-1,i-1),process(K,N-i));
        curmax = min(temp,curmax);
    }
    m[make_pair(K,N)] = curmax+1;
    return curmax;
}
