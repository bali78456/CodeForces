#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<bool>> visited;
vector<vector<char>> Map;
vector<vector<int>> dist;
int h, w;

void bfs(int start,int end)
{
    queue<pair<int,int>>q;
    q.push({start, end});
    visited[start][end]=true;

    while(!q.empty())
    {
        start=q.front().first;
        end = q.front().second;
        q.pop();

        for(int i = 0; i < 4;i++)
        {
            int nx = dx[i] + start;
            int ny = dy[i] + end;

            if(nx>=0&&ny>=0&&nx<h&&ny<w)
            {
                if(!visited[nx][ny]&&Map[nx][ny]=='.')
                {
                    visited[nx][ny]=true;
                    q.push({nx, ny});
                    dist[nx][ny] = dist[start][end]+1;
                }
            }
        }
    }
}

void solve() {
    cin >> h >> w;

    Map.assign(h, vector<char>(w, 0)); 
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w;j++)
        {
            cin >> Map[i][j];
        }
    }

    auto ans=0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w;j++)
        {
            if(Map[i][j]=='.')
            {
                visited.assign(h, vector<bool>(w, false));
                dist.assign(h, vector<int>(w, 0));

                bfs(i, j);

                for(int k = 0; k < h;k++)
                {
                    for(int l = 0; l < w;l++)
                    {
                        ans = max(ans, dist[k][l]);
                    }
                }
            }
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

// #라면 벽이고, . 이라면 길
// 인접한 4방향으로 이동가능(4방향탐색)

// 어느곳에서 시작했을 때 최대로 많이 움직여야하는 움직임 횟수 출력
// 1. 모든 가능한 . 에서 bfs시작해서 최대값 갱신(다른 모든 길까지 갈수있는 횟수)

// https://atcoder.jp/contests/abc151/tasks/abc151_d