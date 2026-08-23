#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
        if(i%3==0)
        {
            cout << "Fizz\n";
        }
        else
            cout << i << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc470/tasks/abc470_a