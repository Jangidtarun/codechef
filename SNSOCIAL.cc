#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int val[N][N];
bool vis[N][N];
int level[N][N];
int n, m;

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            level[i][j] = INF;
        }
    }
}

vector<pair<int, int>> moves{
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0}};

bool isValid(pair<int, int> &coord)
{
    return coord.first >= 0 and coord.second >= 0 and
           coord.first < n and coord.second < m;
}

int bfs()
{
    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mx = max(mx, val[i][j]);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (val[i][j] == mx)
            {
                q.push({i, j});
                vis[i][j] = true;
                level[i][j] = 0;
            }

    while (!q.empty())
    {
        auto curv = q.front();
        q.pop();
        for (auto dir : moves)
        {
            pair<int, int> child = {dir.first + curv.first, dir.second + curv.second};
            if (isValid(child) and !vis[child.first][child.second])
            {
                q.push(child);
                vis[child.first][child.second] = true;
                level[child.first][child.second] = level[curv.first][curv.second] + 1;
                ans = max(ans, level[child.first][child.second]);
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> val[i][j];
        cout << bfs() << endl;
    }
}