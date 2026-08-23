#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<ll> d(n);
    for(int i = 0; i < n;i++)
        cin >> d[i];
    vector<pair<ll, ll>> v;
    for(int i = 0; i < m; i++) {
        ll l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }

    sort(v.begin(), v.end());
    vector<pair<ll, ll>> sh;
    for(auto &p:v)
    {
        if(sh.empty()||sh.back().second<p.first)
        {
            sh.push_back(p);
        }
        else
        {
            sh.back().second = max(sh.back().second, p.second);
        }
    }

    // ll ans=0;
    // for(int i = 0; i < n;i++)
    // {
    //     auto it = lower_bound(sh.begin(), sh.end(), d[i],
    //                           [](const pair<ll, ll>& interval, ll val) { return interval.second < val; });
    //     if(it!=sh.end() && it->first <= d[i])
    //     {
    //         ans += d[i] * 2;
    //     }
    //     else
    //         ans += d[i];
    // }
    // cout << ans;

    // lower_bound에 람다 함수 안쓴 코드

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(sh.begin(), sh.end(), make_pair(d[i]+1, -1LL));

        bool isIn = false;
        if(it != sh.begin()) {
            auto prev_it = prev(it);
            if(prev_it->second>=d[i])
            {
                isIn = true;
            }
        }

        if(isIn) ans += d[i] * 2;
        else
            ans += d[i];
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 0 - 80 150 300

// Lj <= D <= Rj 를 만족한다면 점수는 2*Dj

// 1. 구간 병합 후 이분탐색

// https://atcoder.jp/contests/awc0129/tasks/awc0129_c