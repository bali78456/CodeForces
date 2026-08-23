#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());

        int cnt = 0;
        while(1) {
            if((v[0] == v[1] || v[0] == v[2] || v[1] == v[2]))
            {
                break;
            }
            v[2]--;
            v[0]++;
            sort(v.begin(), v.end());
            cnt++;
        }
        cout << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://codeforces.com/contest/2254/problem/A