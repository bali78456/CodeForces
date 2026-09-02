#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q,k;
vector<vector<pair<int, int>>> graph;
vector<ll> dist;

void dfs(int x)
{
    for(auto [next,weight]:graph[x])
    {
        if(dist[next]==-1)
        {
            dist[next] = dist[x] + weight;
            dfs(next);
        }
    }
}

void solve()
{
    cin >> n;
    graph.assign(n+1, vector<pair<int, int>>());
    dist.assign(n + 1, -1);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> q >> k;
    dist[k] = 0;
    dfs(k);

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << dist[x] + dist[y]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 쿼리
// 정점 xj에서 정점 k를 경유하여 정점 yj로 가는 최단 경로의 길이 구하라

// 1. 모든 정점은 k를 지나야하기 때문에 k를 루트로 잡고 시작하는 다른 정점까지의 거리를 구하고
//    쿼리가 들어오면 dist[x] + dist[y]를 출력하면 된다

// https://atcoder.jp/contests/abc070/tasks/abc070_d?utm_source=chatgpt.com