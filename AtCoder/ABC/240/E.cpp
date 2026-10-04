#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>>graph;
int n;
vector<int> L;
vector<int> R;
int timer = 0;

void dfs(int cur,int p)
{
    int child_cnt=0;
    int min_L = 1e9;
    int max_R = 0;

    for(auto next:graph[cur])
    {
        if(next == p) continue;

        child_cnt++;

        dfs(next, cur);

        min_L = min(min_L, L[next]);
        max_R = max(max_R, R[next]);
    }

    if(child_cnt==0)
    {
        timer++;
        L[cur] = timer;
        R[cur] = timer;
    }
    else
    {
        L[cur] = min_L;
        R[cur] = max_R;
    }
}

void solve()
{
    cin>>n;
    graph.assign(n+1,vector<int>());
    L.assign(n + 1, 0);
    R.assign(n + 1, 0);

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);

    for(int i = 1; i <= n;i++)
    {
        cout << L[i] << " " << R[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc240/tasks/abc240_e