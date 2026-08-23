#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n,d;
    cin >> n >> d;
    
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        ll x, y;
        ll sum = 0;
        cin >> x >> y;
        sum = pow(x, 2) + pow(y, 2);
        if(sum > pow(d, 2)) cnt++;
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/awc0126/tasks/awc0126_a