#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;

void dfs(int x)
{
    visited[x]=true;

    for(auto next:graph[x])
    {
        if(!visited[next])
        {
            dist[next] += dist[x];
            dfs(next);
        }
    }
}

void solve()
{
    cin >> n >> q;
    graph.assign(n + 1, vector<int>());
    dist.assign(n + 1, 0);
    visited.assign(n + 1, false);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < q;i++)
    {
        int p, x;
        cin >> p >> x;
        dist[p] += x;
    }

    dfs(1);

    for(int i = 1; i <= n;i++)
    {
        cout << dist[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 각 정점에는 카운터 연결돼있고 초기값은 0
// q개의 작업에서 정점 pj를 루트로 하는 서브트리에 포함된 모든 정점의 카운터를
// xj만큼 증가 (루트인 pj도 xj만큼 카운터 증가해줘야됨)
// 모든 작업 후 1번부터 n번 정점까지 각 정점의 카운터 구해라

// 1. dfs에서 weight을 줄게 아니라 매개변수로만 counter 주고
// 2. 따로 dist만들어서 여기에 각 정점별 현재 카운터만 저장해놓고
//    dfs에서도 dist에 무게 추가하는 방식으로

// 1. 쿼리받을때 각 노드 점수만 저장
// 2. 마지막에 1번부터 dfs돌린다음 그 밑으로 누적해서 더해줌

// https://atcoder.jp/contests/abc138/tasks/abc138_d?utm_source=chatgpt.com