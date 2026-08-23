#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num % k == 0) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/awc0128/tasks/awc0128_a