#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, vector<int>> graph;
map<int, bool> visited;
int ans = 1;

void dfs(int start)
{
    visited[start]=true;
    for(auto next:graph[start])
    {
        if(!visited[next])
        {
            ans = max(ans, next);
            dfs(next);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for(int i{}; i < n;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        visited[a] = false;
        visited[b] = false;
    }

    dfs(1);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
// N은 2*10^5인데
// A,B가 10^9이라서
// vector<vector<int>> 못쓰고
// map<int,vector<int>>로 그래프 입력받아야됨
// 나머지는 똑같이 dfs돌려서 max값 갱신하면 끝

// https://atcoder.jp/contests/abc277/tasks/abc277_c