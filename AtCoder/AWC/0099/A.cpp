#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, w;
    cin >> n >> w;
    vector<ll> v(n + 1);
    ll sum = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(w>=v[i])
        {
            w -= v[i];
            ans++;
        }
        else
            break;
    }
    cout << ans;

    return 0;
}

// https://atcoder.jp/contests/awc0099/tasks/awc0099_a