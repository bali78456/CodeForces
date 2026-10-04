#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int,int>>> graph;
int ans = 0;

void dfs(int cur_n,int p,int cur_edge,int cnt)
{
    ans = max(ans, cnt);
    for(auto next : graph[cur_n]) {
        if(next.first == p) continue;
        if(cur_edge<next.second)
            dfs(next.first, cur_n, next.second, cnt);
        else 
            dfs(next.first, cur_n, next.second, cnt+1);
    }
}

void solve()
{
    ans = 0;
    int n;
    cin >> n;
    graph.assign(n + 1, vector<pair<int,int>>());
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
    }
    dfs(1, 1, 0, 1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}
// step 0: 첫번째 정점 그린다(정점1) -> step 1으로 이동
// step 1: 입력에 주어진 간선 목록 순서대로 다음 수행
//         만약 어떤 간선이 이미 그려진 정점 u와 아직 그려지지 않은 정점 v를 연결한다면
//         아직 그려지지 않은 정점 v와 그 간선을 그린다
//         모든 간선을 확인한 후 -> step 2로 이동
// step 2: 모든 정점이 그려졌다면 알고리즘 종료, 그렇지 않다면 step 1으로 이동

// 읽기 횟수는 1단계를 수행한 횟수로 정의
// 트리를 모두 그리는 데 필요한 읽기 횟수를 구해라

// 1. 간선번호까지 저장해놓고 dfs한번 돌면서 현재 간선번호가 다음 간선번호보다 작으면
//    cnt 유지, 아니라면 cnt++ 해서 dfs 돌려서 max(cnt) 출력하면됨

// https://codeforces.com/contest/1830/problem/A