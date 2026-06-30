#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph(2001);
bool visited[2001];
int cnt = 0;

void dfs(int x)
{
    if(visited[x]) return;
    visited[x] = true;
    cnt++;

    for(auto &nx:graph[x])
    {
        dfs(nx);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cnt++;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(auto &nx:graph[curr])
        {
            if(!visited[nx])
            {
                cnt++;
                visited[nx] = true;
                q.push(nx);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for(int i = 1; i <= n;i++)
    {
        fill(visited, visited + 2001, false);
        bfs(i);
        // dfs(i);
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// n개의 도시와 m개의 단방향 도로
// 도시 A에서 출발해서 도로를 타고 도달할 수 있는 도시 B의 쌍의 총개수

// 1. 모든 정점 A에서 각 bfs or dfs 돌려보면서 방문 가능한 정점의 개수 모두 더함

// https://atcoder.jp/contests/abc204/tasks/abc204_c