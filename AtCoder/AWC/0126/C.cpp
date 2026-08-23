#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bfs(int start,int end,int n,const vector<vector<int>>&graph)
{
    vector<int>dist(n+1,-1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(cur == end) return dist[cur];

        for(int next:graph[cur])
        {
            if(dist[next]==-1)
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>graph(n+1);
    for(int i = 0; i < m;i++)
    {
        int u, v, s;
        cin >> u >> v >> s;
        if(s==1)
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    cout << bfs(1, n, n, graph);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/awc0126/tasks/awc0126_c