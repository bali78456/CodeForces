#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> w(n);
    vector<ll> c(m);

    for(int i = 0; i < n;i++)
        cin >> w[i];
    for(int i = 0; i < m;i++)
        cin >> c[i];

    sort(c.begin(), c.end());
    ll minC = c[0];

    int l = 0, r = 0;
    ll ans = 0;
    ll sum = 0;
    while(l < n) {
        while(r<n && sum+w[r]<=minC)
        {
            sum += w[r];
            r++;
        }
        ans += r-l;
        sum -= w[l];
        l++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 조건 만족하는 구간 l,r 구해서
// 가져갈수있는 과자 총 개수

// 1. 투포인터
// 2.

// https://atcoder.jp/contests/awc0128/tasks/awc0128_c