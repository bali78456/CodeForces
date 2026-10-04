#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt1 = 0;
    int cnt0 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 1) cnt1++;
        else
            cnt0++;
    }

    if(cnt0<2)
    {
        cout << -1 << "\n";
    }
    else
    {
        int ans = 0;
        if(a[0] == 1) ans++;
        if(a[n - 1] == 1) ans++;
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}

// https://codeforces.com/contest/2260/problem/A