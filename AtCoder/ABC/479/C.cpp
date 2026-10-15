#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX 21

int n, w;
vector<ll> a, b;
ll max_de = 0;

void dfs(int idx, ll cur_w, ll cur_a) {
    if(idx==n)
    {
        max_de = max(max_de, cur_a);
        return;
    }
    if(cur_w+b[idx]<=w)
    {
        dfs(idx + 1, cur_w + b[idx], cur_a + a[idx]);
    }
    dfs(idx + 1, cur_w, cur_a);

}
void solve() {
    cin >> n >> w;
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    dfs(0, 0, 0);
    cout << max_de;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// dp state
// dp[21][2] => 0 이면 고른다 1이면 안고른다

// https://atcoder.jp/contests/abc479/tasks/abc479_c