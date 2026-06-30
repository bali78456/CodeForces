#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph(101);
bool visited[101];
int cnt = 0;

int dfs(int x)
{
    if(visited[x]) return 0;
    visited[x] = true;

    for(auto &nx:graph[x])
    {
        dfs(nx);
    }
    return 1;
}

int bfs(int start)
{
    if(visited[start]) return 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(auto &nx:graph[curr])
        {
            if(!visited[nx])
            {
                visited[nx] = true;
                q.push(nx);
            }
        }
    }
    return 1;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= n;i++)
    {
        // cnt+=dfs(i);
        cnt+=bfs(i);
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc284/tasks/abc284_c