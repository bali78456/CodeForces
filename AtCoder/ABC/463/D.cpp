#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<pair<ll, ll>> v;

ll check(ll x)
{
    ll last = INT_MIN;
    int cnt = 0;
    for(auto &[R,L]:v)
    {
        if(L-last>=x)
        {
            cnt++;
            last = R;
        }
    }
    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n;i++)
    {
        ll l, r;
        cin >> l >> r;
        v.push_back({r, l});
    }
    sort(v.begin(), v.end());

    if(!check(1))
    {
        cout << -1;
        return 0;
    }

    ll lo = 0, hi = INT_MAX;
    while(lo<hi)
    {
        ll mid = lo + (hi - lo + 1) / 2;
        if(check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo;

    return 0;
}

// 1. L 기준으로 오름차순 정렬
// 2. 점수 x를 찾음

// https://atcoder.jp/contests/abc463/tasks/abc463_d