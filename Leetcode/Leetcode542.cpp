/*
01矩阵
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离

【麻烦思路】找到一个0开始的位置，从这个位置开始进行bfs遍历，上下左右四个方向，重复跳过，非零加一取最小 

【简便思路】找到所有0的位置，然后再开始bfs遍历
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>> &matrix);
int is_search[10000][10000] = {0};
int main()
{
    vector<vector<int>> matrix(3);
    for (int i = 0; i < 3; i++)
    {
        matrix[i].resize(3, 0);
    }
    matrix[1][1] = 1;
    updateMatrix(matrix);
}
vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dist(m, vector<int>(n));
    vector<vector<int>> seen(m, vector<int>(n));
    queue<pair<int, int>> q;
    // 将所有的 0 添加进初始队列中
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 0)
            {
                q.emplace(i, j);
                seen[i][j] = 1;
            }
        }
    }

    // 广度优先搜索
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d)
        {
            int ni = i + dirs[d][0];
            int nj = j + dirs[d][1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj])
            {
                dist[ni][nj] = dist[i][j] + 1;
                q.emplace(ni, nj);
                seen[ni][nj] = 1;
            }
        }
    }

    return dist;
}