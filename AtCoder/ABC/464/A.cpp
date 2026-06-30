#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    int cntE = 0;
    int cntW = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'E') cntE++;
        else
            cntW++;
    }
    if(cntE > cntW) cout << "East";
    else
        cout << "West";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc464/tasks/abc464_a