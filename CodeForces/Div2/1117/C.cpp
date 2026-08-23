#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
vector<vector<int>>adj;
vector<bool> has_dam;
vector<int> cameras;

int dfs(int u)
{
    int total_dam = has_dam[u] ? 1 : 0;
    vector<int>valid_children;
    for(int v:adj[u])
    {
        int chile_dams=dfs(v);
        if(chile_dams>0)
        {
            valid_children.push_back(v);
            total_dam += chile_dams;
        }
    }

    int X = valid_children.size();
    if(X>0)
    {
        if(has_dam[u])
        {
            for(int i = 0; i < X;i++)
            {
                cameras.push_back(valid_children[i]);
            }
        }
        else
        {
            for(int i = 0; i < X - 1;i++)
            {
                cameras.push_back(valid_children[i]);
            }
        }
    }
    return total_dam;
}

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        adj.assign(n + 1, vector<int>());
        has_dam.assign(n + 1, false);
        cameras.clear();

        for(int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        cin>>m;
        for(int i = 0; i < m;i++)
        {
            int a;
            cin >> a;
            has_dam[a] = true;
        }

        dfs(1);
        cout << cameras.size();
        for(int u:cameras)
        {
            cout << " " << u;
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// pi는 2...n번 정점까지 부모 정점 번호
// a1...am 은 댐이 있는 정점의 번호

// https://codeforces.com/contest/2257/problem/C