#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> parent;
vector<int> degree;
vector<bool> is_cycle;

void init(int v)
{
    parent[v] = v;
}

int find(int v)
{
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void union_find(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    degree.assign(n + 1, 0);
    is_cycle.assign(n + 1, true);

    for(int i = 1; i <= n;i++)
    {
        init(i);
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        union_find(u, v);
    }

    for(int i = 1; i <= n;i++)
    {
        if(degree[i] != 2) is_cycle[find(i)] = false;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(is_cycle[i] && i == find(i)) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://codeforces.com/problemset/problem/977/E