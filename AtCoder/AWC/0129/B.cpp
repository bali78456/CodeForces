#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,t;
    cin >> n >> t;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n;i++)
    {
        ll s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());

    ll ans=v[0].first-0;
    for(int i = 0; i < n-1;i++)
    {
        if(v[i+1].first-v[i].second>0)
        {
            ans = max(ans, v[i + 1].first - v[i].second);
        }
    }
    ans = max(t - v[n - 1].second, ans);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/awc0129/tasks/awc0129_b