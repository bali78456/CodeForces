#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph;
ll A = 0;
ll B = 0;

void dfs(int start,int p,int color)
{
    if(color == 0) A++;
    else
        B++;
    for(auto next:graph[start])
    {
        if(next == p) continue;
        dfs(next, start, 1 - color);
    }
}

void solve()
{
    int n;
    cin >> n;
    graph.assign(n + 1, vector<int>());
    for(int i{}; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0, 0);
    ll ans = (A * B) - (n - 1);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://codeforces.com/contest/862/problem/B