#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<string> s(2);
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool flag = false;

void bfs(int start,int end)
{
    queue<pair<int, int>> q;
    q.push({start, end});
    visited[start][end] = true;

    while(!q.empty())
    {
        start = q.front().first;
        end = q.front().second;
        q.pop();

        for(int i = 0; i < 4;i++)
        {
            int nx = start + dx[i];
            int ny = end + dy[i];

            if(nx >= 0 && ny >= 0 && nx < 2 && ny < n) {
                if(!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    if(s[nx][ny] == '<') {
                        if(ny-1>=0)
                        {
                            ny -= 1;
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            if(nx==1&&ny==n-1)
                            {
                                flag = true;
                                return;
                            }
                        }
                    }
                    else if(s[nx][ny]=='>')
                    {
                        if(ny+1<n)
                        {
                            ny += 1;
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            if(nx==1&&ny==n-1)
                            {
                                flag=true;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

void solve()
{
    flag = false;
    
    cin >> n;
    cin >> s[0] >> s[1];
    visited.assign(2, vector<bool>(n,false));
    bfs(0, 0);
    if(flag) cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}
// (1,1)에서 매 초 로봇이 출발한다
// 1. 로봇은 상하좌우로 이동가능(그리드 밖으로는 못나가고 이동을 스킵할수도없음)
// 2. 그 후 현재 위치한 칸(이동 후 도착한 칸)에 있는 화살표 방향 따라 한 칸 이동

// 로봇이 (2,n)으로 갈 수 있는지 판별

// 1. bfs로 4방향탐색 돌려서 2,n 달성하면 yes 못하면 no?

// https://codeforces.com/contest/1948/problem/C