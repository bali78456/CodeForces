#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[200005];
vector<vector<ll>> adj(200005);
ll T[200005];
ll total_time = 0;

void dfs(ll x)
{
    if(visited[x]) return;
    visited[x] = true;
    total_time += T[x];

    for(auto &nx:adj[x])
    {
        dfs(nx);
    }
}

void solve() {
    int n;
    cin >> n;
    ll k;
    for(int i = 0; i < n;i++)
    {
        cin >> T[i] >> k;
        for(int j = 0; j < k;j++)
        {
            ll a;
            cin >> a;
            adj[i].push_back(a-1);
        }
    }
    dfs(n - 1);
    cout << total_time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// Ti = i번 기술을 배우는 데 걸리는 시간

// https://atcoder.jp/contests/abc226/tasks/abc226_c