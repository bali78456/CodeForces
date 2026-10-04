#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> graph;

int costA = 0;
void dfs(int cur, int p) {
    for(auto next:graph[cur])
    {
        if(next.first==p) continue;
        costA += next.second;

        if(next.first!=1)
            dfs(next.first, cur);
        return;
    }
}

void solve()
{
    int n;
    cin >> n;
    graph.assign(n + 1, vector<pair<int, int>>());
    int total = 0;
    for(int i{}; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, 0});
        graph[b].push_back({a, c});
        total += c;
    }
    dfs(1, 0);

    int ans = min(costA, total - costA);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// n개의 도시는 링 모양으로 n개의 양방향 도로를 통해 연결되어 있다
// 이 모든 n개의 도로에 일방통행 도입했지만 일부 도시에서 다른 특정 도시들로 이동 불가한걸 알았다
// 각 도로에 대해 차량의 통행 방향과 방향을 반대로 바꾸는 데 드는 비용이 알려져 있다
// 모든 도시에서 다른 모든 도시로 이동할 수 있도록 도로의 방향을 바꾸기 위해 정부가
// 지출해야하는 최소 비용은 얼마인가

// input
// a b c
// 도로가 도시 a에서 b로 향하고 있고 방향을 바꾸는 데 c의 비용이 든다

// 1. 최적은 결국 반시계방향으로 도는것 or 시계방향으로 도는 것
// 2. 결국 한 방향으로 돌았을 때 코스트가 costA라면 반대방향의 코스드는 total-costA
// 3. 둘 중 더 작은 값 출력하면 됨

// https://codeforces.com/contest/24/problem/A