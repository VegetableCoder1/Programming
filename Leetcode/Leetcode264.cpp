/*

264 丑数||
丑数是因式只有2 3 5 的数
找出第k个丑数（第一个丑数是1）

[思路]
由第一个丑数1 得到三个丑数 1*2 1*3 1*5
由第二个丑数2 得到三个丑数 2*2 2*3 2*5
...
每次都从剩下的里面选择最小的一个，然后依次*2 *3 *5
直到找到第k个

需要一个容器，每次可以直接返回最小值，就可以想到使用堆
c++ stl queue文件里面的 priority_queue
最大堆 priority_queue<int, vector<int> , less<int> > q;
最小堆 priority_queue<int, vector<int> , greater<int> > q;

*/

#include <bits/stdc++.h>
using namespace std;
int nthUglyNumber(int n);
int main()
{

}

int nthUglyNumber(int n)
{
    priority_queue<long long, vector<long long>, greater<long long>> a;
    unordered_set<long long> s;
    a.push(1);
    s.insert(1);
    long long count = 0;
    long long curmin = 0;
    while (count < n)
    {
        curmin = a.top();
        a.pop();
        count++;
        long long k1 = 2 * curmin;
        long long k2 = 3 * curmin;
        long long k3 = 5 * curmin;
        if (s.find(k1) == s.end())
        {
            s.insert(k1);
            a.push(k1);
        }
        if (s.find(k2) == s.end())
        {
            s.insert(k2);
            a.push(k2);
        }
        if (s.find(k3) == s.end())
        {
            s.insert(k3);
            a.push(k3);
        }
    }
    return curmin;
}

/*
自定义类型堆的使用
*/
struct Type1
{
    int k;
};
// 1. 自己写比较函数
struct cmp
{
    bool operator()(Type1 a,Type1 b)
    {
        return a.k > b.k; //小于号 大根堆 大于号 小根堆
    }
};
priority_queue< Type1, vector<Type1>, cmp> q;

// 2. 重载运算符
struct Type2
{
    int k;
    int s;
    bool operator<(const Type2 t) const
    {
        if( k == t.k) // 还可以实现多条件比较
        {
            return s > t.s;
        }
        return k<t.k; //小于号 大根堆 大于号 小根堆
    }
};
priority_queue<Type2> q;
