#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = a + b;
    }
    auto it = max_element(v.begin(), v.end());
    cout << it - v.begin()+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/awc0100/tasks/awc0100_b