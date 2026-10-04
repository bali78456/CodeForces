#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
vector<int> vertices;
vector<vector<int>> graph;
vector<int> top[100005];

void dfs(int cur,int p)
{
    for(int next:graph[cur])
    {
        if(next == p) continue;
        dfs(next, cur);
    }

    top[cur].push_back(vertices[cur]);

    for(auto next:graph[cur])
    {
        if(next == p) continue;
        for(auto val:top[next])
        {
            top[cur].push_back(val);
        }
    }
    sort(top[cur].rbegin(), top[cur].rend());

    while(top[cur].size()>20)
    {
        top[cur].pop_back();
    }
}

void solve() {
    cin >> n >> q;
    vertices.assign(n + 1, 0);
    graph.assign(n + 1, vector<int>());

    for(int i = 1; i <= n; i++) {
        cin >> vertices[i];
    }

    for(int i = 1; i < n;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        cout << top[v][k-1]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 쿼리
// 정점 Vi를 루트로 하는 서브트리에 속한 정점들에 적힌 정 수 중 Ki번째로 큰 값 출력

// 1. 각 노드마자 정수를 저장핼 vector를 만든다
// 2. 리프노드부터 루트노드로 post-order dfs 실행
// 3. 리스트 내림차순 정렬하고 앞에서부터 20개만 남기고 나머지는 버린다
// 4. 쿼리가 들어오면 node[Vi][Ki-1] 출력하면된다

// https://atcoder.jp/contests/abc239/tasks/abc239_e?utm_source=chatgpt.com