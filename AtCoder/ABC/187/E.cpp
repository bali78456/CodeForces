#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q;
vector<vector<int>> graph;
vector<ll> weight;
vector<pair<int, int>> edges;
vector<bool> visited;
vector<int> depth;

void dfs(int x)
{
    visited[x]=true;

    for(auto next:graph[x])
    {
        if(!visited[next])
        {
            weight[next] += weight[x];
            dfs(next);
        }
    }
}

void dfsDepth(int x)
{
    visited[x] = true;

    for(auto next:graph[x])
    {
        if(!visited[next])
        {
            depth[next] = depth[x] + 1;
            dfsDepth(next);
        }
    }
}

void solve()
{
    cin >> n;
    graph.assign(n + 1, vector<int>());
    weight.assign(n + 1, 0);
    edges.resize(n+1);
    visited.assign(n + 1, false);
    depth.assign(n + 1, 0);

    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges[i] = {a, b};
    }

    // 쿼리 처리하기 전 tree depth 구해놓기
    dfsDepth(1);
    // depth[u] < depth[v] 면 u가 부모 v가 자식
    // depth[u] > depth[v] 면 u가 자식 v가 부모
    visited.assign(n + 1, false);

    cin >> q;
    for(int i = 0; i < q;i++)
    {
        ll t, e, x;
        cin >> t >> e >> x;
        if(t==1)
        {
            if(depth[edges[e].first]>depth[edges[e].second])
            {
                weight[edges[e].first] += x;
            }
            else
            {
                weight[1] += x;
                weight[edges[e].second] -= x;
            }
        } else {
            if(depth[edges[e].first]<depth[edges[e].second])
            {
                weight[edges[e].second] += x;
            } else {
                weight[1] += x;
                weight[edges[e].first] -= x;
            }
        }
    }

    dfs(1);

    for(int i = 1; i <= n;i++)
    {
        cout << weight[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// t==1 일 때 정점 bei로 가는 간선을 막고 aei쪽 영역에 있는 모든 정점에 xi를 더하라
// t==2 일 때 정점 aei로 가는 간선을 막고 bei쪽 영역에 있는 모든 정점에 xi를 더하라

// 그냥 dfs로 전부 돌기에는 n이 2*10^5라 tle나고
// 저번 dfs누적합처럼 각 정점마다 더할 값만 저장해놓고 밑에 서브트리로 뿌리는 식으로
// dfs한번만 돌려야할듯

// 1. 루트를 1번정점으로 두고 dfs를 한번 돌려서 모든 정점의  깊이 저장
// 2. 자식쪽 서브트리에만 xi를 더해야 할 때
//      자식 정점 c의 배열 weight[c]에만 += xi
//    자식 서브트리를 제외한 나머지 전체에 xi를 더해야 할 때
//      전체 트리의 루트인 weight[1] += xi 하고 제외해야하는 자식정점 weight[c] -= xi

// t==1 => v를 방문하지않고 u에서 갈수있는 영역에 + x 즉 u 쪽 전체에 + x
// depth[u] > depth[v] (u=자식, v=부모)
// u의 서브트리 전체에 + 해줘야 하므로 weight[u] += x
// depth[u] < depth[v] (u=부모, v=자식)
// 루트 1번에 + x 해주고
// 그 중 제외되어야 하는 v의 서브트리에만 -= x 

// t==2 => u를 방문하지않고 v에서 갈수있는 영역에 +
// depth[u] < depth[v] (v=자식, u=부모)
// v 서브트리에만 + 
// depth[u] > depth[v] (v=부모, u=자식)
// 루트 1번에 + x
// 제외되어야 하는 u의 서브트리에만 -= x

// https://atcoder.jp/contests/abc187/tasks/abc187_e?utm_source=chatgpt.com