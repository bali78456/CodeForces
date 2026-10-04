#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    int num = s.length();
    if(s[num-1]=='e')
    {
        s += "r";
        cout << s;
    }
    else
    {
        s += "er";
        cout << s;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc476/tasks/abc476_a