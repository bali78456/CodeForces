#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> prefix(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    prefix[0] = v[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + v[i];
    }

    ll ans = abs(prefix[0]-(prefix[n-1]-prefix[0]));
    for(int i = 1; i < n;i++)
    {
        ans = min(ans, abs(prefix[i] - (prefix[n - 1] - prefix[i])));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1 to K 까지 팀 A => S1
// K+1 to N 까지 팀 B => S2
// |S1 - S2| 값을 최소화

// https://atcoder.jp/contests/awc0100/tasks/awc0100_d