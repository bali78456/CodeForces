#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> Map;
vector<int> row_bomb_cnt;
vector<int> col_bomb_cnt;
vector<vector<int>> dist;
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int h, w, k;

void bfs()
{
    while(!q.empty())
    {
        auto [start, end] = q.front();
        q.pop();

        if(dist[start][end] == k) continue;

        for(int i = 0; i < 4;i++)
        {
            int nx = start + dx[i];
            int ny = end + dy[i];

            if(nx>=0&&ny>=0&&nx<h&&ny<w)
            {
                if(Map[nx][ny]=='.'&&dist[nx][ny]==-1)
                {
                    dist[nx][ny] = dist[start][end] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void solve() {
    cin >> h >> w >> k;

    Map.resize(h);
    row_bomb_cnt.assign(h, 0);
    col_bomb_cnt.assign(w,0);
    dist.assign(h, vector<int>(w, -1));

    for(int i = 0; i < h; i++) {
        cin >> Map[i];
    }

    for(int i = 0; i < h;i++)
    {
        for(int j = 0; j < w;j++)
        {
            if(Map[i][j]=='#')
            {
                row_bomb_cnt[i]++;
                col_bomb_cnt[j]++;
            }
        }
    }

    for(int i = 0; i < h;i++)
    {
        for(int j = 0; j < w;j++)
        {
            if(Map[i][j]=='.'&&row_bomb_cnt[i]==0&&col_bomb_cnt[j]==0)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    bfs();

    int ans = 0;
    for(int i = 0; i < h;i++)
    {
        for(int j = 0; j < w;j++)
        {
            if(dist[i][j]!=-1)
            {
                ans++;
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

// . 는 비어있는 셀
// # 는 폭탄 셀

// 비어있는 셀 기준 가로세로에 폭탄이 하나도 없으면 그 칸은 안전한 셀
// 그 안전한 셀에서 갈수있는 셀의 개수 출력

// 1. 각 행 열에 폭탄수 체크
// 2. 폭탄이 없는 안전한 셀 미리 좌표 확보한 후 한번에 bfs로 거리 체크
// 3. dist 배열 돌면서 거리 2 이내인 셀 수만 세면 됨

// https://atcoder.jp/contests/abc472/tasks/abc472_d