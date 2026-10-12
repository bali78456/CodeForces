#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>> v;
vector<bool> visited;
int n;
bool bfs(int start, int end) {
    visited.assign(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur == end) return true;

        for(int next = 0; next < v.size();next++) {
            if(visited[next]) continue;

            auto [a, b] = v[cur];
            auto [c, d] = v[next];

            if((c<a&&a<d)||(c<b&&b<d))
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n;
    for(int i{}; i < n; i++) {
        int num;
        cin >> num;
        if(num==1)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        } else if(num == 2) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if(bfs(a, b))
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 매 순간 구간들의 집합이 주어진다 
// 집합에 속한 구간 a,b에서 집합에 속한 구간 c,d로 이동할 수 있는 조건은
// c < a < d 또는 c < b < d 를 만족할 대 이다

// type 1
// 새로운 구간 (x,y)를 구간 집합에 추가 
// type 2
// a번째 (1번째부터 시작)로 추가된 구간에서 b번째로 추가된 구간으로 가는 경로가 존재하는가

// type 2쿼리가 주어질때마다 yes no 출력

// https://codeforces.com/contest/320/problem/B