#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.length();i++)
    {
        if(i<s.length()-1)
        {
            cout << s[i];
            cout << "o";
        }
        else
            cout << s[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc475/tasks/abc475_a