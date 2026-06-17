#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 가격
    vector<ll> w(n+1);
    for(int i = 1; i <= n; i++)
        cin >> w[i];

    vector<vector<ll>> a(m+1);
    int k;
    for(int i = 1; i <= m;i++)
    {
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int num;
            cin >> num;
            a[i].push_back(num);
        }
    }

    for(auto &v:a)
    {
        ll sum = 0;
        for(auto& c : v) {
            sum += w[c];
        }
        if(sum!=0)
            cout << sum << "\n";
        else
            continue;
    }
    return 0;
}

// https://atcoder.jp/contests/awc0093/tasks/awc0093_a