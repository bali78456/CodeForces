#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n;i++)
        cin >> a[i];
    
    int ans=0;
    for(int i = (n / 2)+1; i <= n;i++)
    {
        ans += a[i];
        // cout << a[i] << "\n";
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc473/tasks/abc473_a