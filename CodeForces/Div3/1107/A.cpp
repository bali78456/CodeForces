#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, y;
        cin >> x >> y;

        if(x % y == 0) cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// z를 선택해라
// x/z = x
// x랑 y랑 같아질 수 있는 수가 존재하는가

// 1. x%y==0 이라면 항상 가능
// 2. 나머지는 다 안됨

// https://codeforces.com/contest/2241/problem/A