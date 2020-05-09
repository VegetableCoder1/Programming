/*
矩阵中的路径
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
[["a","b","c","e"],
 ["s","f","c","s"],
 ["a","d","e","e"]]
但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

[思路1] 一开始用的是BFS做的 发现BFS的解法本身存在缺陷 形如[[A,A,B]] 查找AAB时候就出错了，因为一开始就把所有的A都纳入第一次的考察范围了
[思路2] 了解到上述缺点后，改用BFS+回溯 超时了
[思路3] 对BFS进行减枝，只要有正确答案立即返回
*/
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{

}

// DFS + 回溯
bool exist(vector<vector<char>> &board, string word)
{
    queue<pair<int, int>> q;
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> issearch(row);
    for (int i = 0; i < row; i++)
    {
        issearch[i].resize(col);
        for (int j = 0; j < col; j++)
        {
            issearch[i][j] = 0;
            if (board[i][j] == word[0])
            {
                q.push(make_pair(i, j));
            }
        }
    }
    if (q.size() == 0)
        return false;
    while (!q.empty())
    {
        int thisx = q.front().first;
        int thisy = q.front().second;
        q.pop();
        if (dfs2(board, issearch, word, thisx, thisy, 0))
            return true;
    }
    return false;
}
bool dfs2(vector<vector<char>> &board, vector<vector<int>> &issearch, string word, int x, int y, int k)
{
    if (k == word.size())
        return true;
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || issearch[x][y] == 1 || board[x][y] != word[k])
        return false;
    issearch[x][y] = 1;
    bool flag1 = dfs2(board, issearch, word, x + 1, y, k + 1);
    bool flag2 = dfs2(board, issearch, word, x, y + 1, k + 1);
    bool flag3 = dfs2(board, issearch, word, x - 1, y, k + 1);
    bool flag4 = dfs2(board, issearch, word, x, y - 1, k + 1);
    issearch[x][y] = 0;
    return flag1 || flag2 || flag3 || flag4;
}

// DFS + 回溯 + 减枝
bool exist1(vector<vector<char>> &board, string word)
{
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> issearch(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (dfs1(board, issearch, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}
bool dfs1(vector<vector<char>> &board, vector<vector<int>> &issearch, string word, int x, int y, int k)
{
    if (k == word.size())
        return true;
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || issearch[x][y] == 1 || board[x][y] != word[k])
        return false;
    issearch[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (dfs1(board, issearch, word, x + dx[i], y + dy[i], k + 1))
            return true;
    }
    issearch[x][y] = 0;
    return false;
}