#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    string s;
    string t;
    cin >> n >> s >> t;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(t[i]!='*')
        {
            if(s[i]!=t[i])
            {
                flag = false;
            }
        }
    }
    if(flag) cout << "Yes";
    else
        cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc476/tasks/abc476_b