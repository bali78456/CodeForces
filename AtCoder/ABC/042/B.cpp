#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() 
{
    int n,l;
    cin >> n >> l;
    vector<string> s(n);
    for(int i = 0; i < n;i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    string ans = "";
    for(string a:s)
    {
        ans += a;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc042/tasks/abc042_b