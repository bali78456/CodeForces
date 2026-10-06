#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 20001

vector<bool> visited;
vector<int> dist;
int n, m;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        start = q.front();
        q.pop();

        if(start == m) return;

        int nx = start * 2;
        int ny = start - 1;

        if(!visited[nx] && nx>0 && nx <MAX)
        {
            q.push(nx);
            visited[nx] = true;
            dist[nx] = dist[start] + 1;
        }

        if(!visited[ny] && ny>0 && ny <MAX)
        {
            q.push(ny);
            visited[ny] = true;
            dist[ny] = dist[start] + 1;
        }
    }
}

void solve()
{
    cin >> n >> m;
    visited.assign(MAX, false);
    dist.assign(MAX, 0);
    bfs(n);
    cout << dist[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}

// https://codeforces.com/problemset/problem/520/B