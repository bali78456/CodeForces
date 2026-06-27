#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, l, q;
    cin >> n >> l >> q;

    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < q;i++)
    {
        int m;
        cin >> m;
        vector<int> v(m);
        string ans = "";
        for(int j = 0; j < m; j++) {
            cin >> v[j];
        }

        for(int j = 0; j < l; j++) {
            bool isOne = false;
            for(int k = 0; k < m;k++)
            {
                if(s[v[k]-1][j] == '1') 
                {
                    isOne = true;
                    break;
                }
            }
            if(isOne) ans += '1';
            else
                ans += '0';
            isOne = false;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/awc0100/tasks/awc0100_c