#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

int n;
vector<vector<pair<int, ll>>> graph;
vector<ll> dist;
const ll INF = LLONG_MAX / 2;

void dijkstra(int start)
{
    priority_queue<pli, vector<pli>, greater<>> pq;
    dist.assign(n + 1, INF);
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v,w]:graph[u])
        {
            if(dist[v]>d+w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    cin >> n;
    graph.assign(n + 1, {});
    for(int i = 1; i < n;i++)
    {
        ll a, b, x;
        cin >> a >> b >> x;
        graph[i].push_back({i + 1, a});
        graph[i].push_back({x, b});
    }

    dijkstra(1);

    cout << dist[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc340/tasks/abc340_d