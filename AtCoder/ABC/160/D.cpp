#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<int> res;
vector<int> dist;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto next:graph[cur])
        {
            if(dist[next]==-1) {
                dist[next] = dist[cur]+1;
                q.push(next);
            }
        }
    }
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    graph.assign(n + 1, vector<int>());
    res.assign(n, 0);
    for(int i = 1; i <= n - 1; i++) {
        graph[i].push_back(i + 1);
        graph[i+1].push_back(i);
    }
    graph[x].push_back(y);
    graph[y].push_back(x);
    

    for(int i = 1; i <= n;i++)
    {
        dist.assign(n + 1, -1);
        bfs(i);

        for(int j = i + 1; j <= n;j++)
        {
            res[dist[j]]++;
        }
    }

    for(int i = 1; i < n;i++)
    {
        cout << res[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// N개 정점 1 to n 
// 각 정점별로 i, i+1이 이어진 간선이 기본으로 존재하고
// x,y사이에 추가 간선 존재

// 1부터 n-1까지
// 그래프 g에서 정점 i와 정점 j 사이의 최단 거리가 k가 되는 정점 쌍의 개수 구하라
// 정점 1은 k가 1이니까 최단거리가 1인 정점쌍 개수
// 2번정점이라면 k=2 최단거리가 2인 정점쌍개수

// https://atcoder.jp/contests/abc160/tasks/abc160_d