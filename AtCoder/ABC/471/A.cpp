#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int a,b;
    cin >> a >> b;
    if(a+b==9 || a-b==9||a*b==9)
    {
        cout << "Nine";
    }
    else if(a/b==9 && a%b==0)
    {
        cout << "Nine";
    } else
        cout << "Nein";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc471/tasks/abc471_a