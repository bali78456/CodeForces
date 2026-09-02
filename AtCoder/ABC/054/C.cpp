#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<bool> visited;
int n, m;
int ans = 0;

void dfs(int x,int depth)
{
    if(depth == n)
    {
        ans++;
        return;
    }

    for(auto next:graph[x])
    {
        if(visited[next]) continue;

        visited[next] = true;

        dfs(next, depth + 1);

        visited[next] = false;
    }
}

void solve()
{
    cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited[1] = true;
    dfs(1,1);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// output
// 정점 1에서 시작해서 모든 정점을 한번씩만 방문해서 전부 돌 수 있는 방법 개수 출력

// 1. dfs랑 백트래킹 결합

// https://atcoder.jp/contests/abc054/tasks/abc054_c