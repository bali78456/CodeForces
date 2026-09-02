#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<bool> visited;

void solve()
{
    int n,m;
    cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    for(int i = 1; i <= m;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n;i++)
    {
        cout << graph[i].size() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc061/tasks/abc061_b?utm_source=chatgpt.com