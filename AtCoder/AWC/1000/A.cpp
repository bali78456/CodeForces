#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int a, t;
        cin >> a >> t;
        for(int i = 0; i < t;i++)
        {
            sum += a;
        }
    }
    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/awc0100/tasks/awc0100_a