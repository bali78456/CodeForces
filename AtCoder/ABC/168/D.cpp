#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> ans;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto next:graph[cur])
        {
            if(!visited[next])
            {
                q.push(next);
                visited[next] = true;
                ans[next] = cur;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    graph.assign(n + 1,vector<int>());
    visited.assign(n + 1, false);
    ans.assign(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);
    int cnt = 0;
    for(int i = 2; i <= n; i++)
    {
        if(ans[i] > 0) cnt++;
    }

    if(cnt==n-1)
    {
        cout<<"Yes\n";
        for(int i = 2; i <= n;i++)
            cout << ans[i] << "\n";
    }
    else
        cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// n개의 방(정점)과 m개의 통로(간선)
// 1 to n, 1 to m
// i번째 통로는 ai와 bi를 양방향으로 연결한다
// 1번방은 외부로 통하는 입구가 있는 방이다
// 1번방을 제외한 모든 방에 표지판 설치, 표지판은 해당 방과 통로로 직접 연결된
// 인접한 방 중 하나를 가리킨다

// 조건
// 해당 방에서 출발하여 현재 있는 방의 표지판이 가리키는 방으로 계속 이동하면서 최소한의
// 통로만 거쳐서 1번 방에 도달해야 한다

// output
// 목표를 만족하도록 표지판을 설치하는 방법이 존재하는지 판별하고
// 존재한다면 그 중 한가지 방법을 출력하라

// 1. 1번정점을 시작점으로 하는 bfs를 수행했을 때 각 노드 직전 방문 노드(부모 노드)
//    기록해두고 출력하는 문제



// https://atcoder.jp/contests/abc168/tasks/abc168_d