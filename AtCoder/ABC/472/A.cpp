#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i < s.length();i++)
    {
        if(s[i]=='A')
        {
            ans += 'A';
        }
        else
            ans += '.';
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc472/tasks/abc472_a