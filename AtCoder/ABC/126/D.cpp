#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int,int>>> graph;
vector<bool> visited;
vector<int> color;

void dfs(int x, ll dist) {
    visited[x]=true;

    if(dist % 2 == 0) color[x] = 0;
    else
        color[x] = 1;

    for(auto [next, weight] : graph[x]) {
        if(!visited[next])
        {
            dfs(next, dist + weight);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    graph.assign(n + 1, vector<pair<int, int>>());
    color.assign(n+1, 0);
    visited.assign(n + 1, false);
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dfs(1, 0);

    for(int i = 1; i <= n;i++)
    {
        cout << color[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1 to N 정점
// i번째 간선은 u,v 연결하고 길이는 w
// 각 정점을 흰색 or 검은색으로 칠해라 (모든 정점이 같은색도 가능)

// 조건
// 1. 같은 색으로 칠해진 임의의 두 정점 사이의 거리는 짝수여야 한다

// output
// 1. 조건을 만족하는 정점 칠하는 방법 아무거나 하나 출력
// 2. i번째 줄에 정점 i가 흰색이라면 0, 검은색이라면 1

// 1. 루트에서 dfs로 전파
// 2. 가중치 합이 짝수면 같은색으로 칠하고 다르면 다른색으로
//    루트 색은 1로 고정

// https://atcoder.jp/contests/abc126/tasks/abc126_d