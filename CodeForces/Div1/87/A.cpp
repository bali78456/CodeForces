#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph;

int dfs(int start,int depth)
{
    int max_depth = depth;
    for(auto next : graph[start]) {
        max_depth = max(max_depth,dfs(next, depth+1));
    }
    return max_depth;
}

void solve()
{
    int n;
    cin >> n;
    graph.assign(n + 1, vector<int>());
    vector<int> root;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(a == -1)
            root.push_back(i);
        else {
            graph[a].push_back(i);
        }
    }
    int max_ans=0;
    for(auto a : root)
        max_ans = max(max_ans, dfs(a, 1));
    cout << max_ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://codeforces.com/contest/115/problem/A