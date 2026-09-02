#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int,int>>> graph;
vector<bool> visited;

int dfs(int x, int ignore_edge) {
    visited[x]=true;
    int count = 1;

    for(auto [next,edge]:graph[x])
    {
        if(edge==ignore_edge)
        {
            continue;
        }

        if(!visited[next])
        {
            count+=dfs(next, ignore_edge);
        }
    }
    return count;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    graph.assign(n + 1, vector<pair<int, int>>());
    
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
    }

    int ans = 0;
    int cnt=0;
    for(int i = 1; i <= m; i++) {
        visited.assign(n + 1, false);
        cnt=dfs(1, i);
        if(cnt<n)
        {
            ans++;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 그래프가 주어졌을 때 사이클을 구성하는 엣지를 제외한 나머지 제거해야될 엣지의 개수 출력

// 1. dfs 매개변수로 무시할 간선을 지정 1 to m
// 2. 방문한 정점 개수가 n보다 작다면 그 부분의 간선을 지워야한다
//    사이클을 이루는 간선은 지운다고 해도 모든 정점을 도달하기 때문

// https://atcoder.jp/contests/abc075/tasks/abc075_c?utm_source=chatgpt.com