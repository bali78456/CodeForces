#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int k = 0;
vector<vector<pair<int,int>>> graph;
vector<int> ans;

void dfs(int u,int p,int p_color)
{
    int next_color = 1;

    for(auto &edge:graph[u])
    {
        int v = edge.first;
        int idx = edge.second;

        if(v == p) continue;

        if(next_color == p_color) next_color++;

        ans[idx] = next_color;
        dfs(v, u, next_color);

        next_color++;
    }
}

void solve()
{
    cin >> n;
    graph.assign(n + 1, vector<pair<int,int>>());
    ans.assign(n + 1, 0);

    for(int i = 1; i < n;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
    }

    for(int i = 1; i <= n;i++)
    {
        int Size = graph[i].size();
        k = max(k, Size);
    }

    dfs(1,0,0);

    cout << k << "\n";
    for(int i = 1; i < n; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 트리의 간선을 색칠하려한다
// 각 정점에 대해 해당 정점에 인접한 간선들의 색이 모두 서로 다르도록 칠해야 한다
// 위 조건을 만족하는 방식 중 사용하는 색의 개수를 최소화하는 방식 하나 출력
// output
// 사용한 최소 색의 개수 k
// i번째 간선에 사용한 색을 나타내는 정수 1<=ci<=k 출력

// 1. 각 정점별로 간선 size세면서 가장 큰 사이즈가 k가 된다


// 1. 최대 간선 수는 최대 차수인 k가 된다
// 2. 트리 구조는 사이클이 없기 때문에 루트노드부터 아래로 내려가면서 색칠을 하면
//    이전에 칠했던 색과 충돌할 일이 없다
//    어떤 정점 u에 도착했을 때 신경써야할 색은 바로 부모 정점에서 나에게로 내려온 간선의 색 뿐이다
//    따라서 정점 u에 연결된 나머지 간선들에는 부모와 연결된 간선의 색만 피하면 된다
// 3. dfs의 매개변수 u: 현재 정점 번호, p: 부모 정점 번호(역주행 방지용)
//    p_color: 부모 정점에서 현재 정점 u로 올 때 사용한 간선의 색상 번호
// 4. 

// https://atcoder.jp/contests/abc146/tasks/abc146_d?utm_source=chatgpt.com