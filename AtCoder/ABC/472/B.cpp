#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> l(n);
    for(int i = 0; i < n;i++)
        cin >> l[i];
    vector<ll> prefix(n);
    prefix[0] = l[0];
    for(int i = 1; i < n;i++)
    {
        prefix[i] += prefix[i - 1] + l[i];
    }

    ll ans = 1e9;
    for(int i = 0; i < n;i++)
    {
        ans = min(ans, abs(prefix[i] - abs(prefix[i] - prefix[n - 1])));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 5 7 10 18


// https://atcoder.jp/contests/abc472/tasks/abc472_b