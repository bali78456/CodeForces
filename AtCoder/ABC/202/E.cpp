#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
vector<vector<int>> graph;
vector<vector<int>> depth_list;
int timer=0;
vector<int> in_time;
vector<int> out_time;

void dfs(int cur,int depth)
{
    timer++;
    in_time[cur] = timer;

    depth_list[depth].push_back(timer);
    for(int next:graph[cur])
    {
        dfs(next, depth + 1);
    }

    out_time[cur] = timer;
}

void solve()
{
    cin >> n;
    graph.assign(n + 1, vector<int>());
    depth_list.assign(n + 1,vector<int>());
    in_time.assign(n+1,0);
    out_time.assign(n + 1, 0);

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        graph[p].push_back(i);
    }
    dfs(1, 0);
    
    cin >> q;
    for(int i = 0; i < q;i++)
    {
        int u, d;
        cin >> u >> d;

        auto& vec = depth_list[d];
        auto it1=lower_bound(vec.begin(), vec.end(), in_time[u]);
        auto it2 = upper_bound(vec.begin(), vec.end(), out_time[u]);
        cout << it2 - it1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 쿼리
// 1. 정점 u에서 루트까지의 최단 경로 상에 정점 Ui가 포함되어 있어야 한다
// 2. 정점 u에서 루트까지의 최단 경로에는 정확히 Di개의 간선이 있어야 한다

// 1. u가 U의 서브트리 안에 있어야 한다
// 2. u의 깊이가 정확히 D여야 한다

// 1. ett로 서브트리를 구간으로 만든다
// 2. 깊이별로 in 시간 모아둔다
// 3. binary_search로 탐색

// https://atcoder.jp/contests/abc202/tasks/abc202_e?utm_source=chatgpt.com