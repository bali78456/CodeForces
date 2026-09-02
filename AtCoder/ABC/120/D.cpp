#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> parent;
ll total_cnt;
vector<int> Size;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x,int y)
{
    int rootX=find(x);
    int rootY = find(y);

    if(rootY == rootX) return;

    ll s_a = Size[rootX];
    ll s_b = Size[rootY];
    total_cnt -= (s_a * s_b);

    parent[rootY] = rootX;
    Size[rootX] += Size[rootY];
}

void solve()
{
    cin >> n >> m;
    vector<pair<int, int>> bridge;
    Size.assign(n+1, 1);
    parent.resize(n + 1);

    for(int i = 1; i <= n;i++)
        parent[i] = i;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        bridge.push_back({a, b});
    }

    total_cnt = ((ll)n * (n - 1)) / 2;
    vector<ll> ans(m);
    for(int i = m - 1; i >= 0; i--) {
        ans[i] = total_cnt;
        merge(bridge[i].first, bridge[i].second);
    }
    for(auto a:ans)
    {
        cout << a << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// i번째 다리는 Ai, Bi를 연결(무방향)
// 첫번째 다리부터 m번째 다리까지 노후로 무너진다
// 1 to m 까지 각 i번째 다리가 무너진 직후에 이동할수 없게 된 섬의 쌍 개수 출력
// (a,b) a<b

// 1. 불편한 다리 쌍의 개수는 n개의 수 중 a<b인쌍 고르는 경우의 수
//    전체 경우의 수 = n * (n-1) / 2

// https://atcoder.jp/contests/abc120/tasks/abc120_d