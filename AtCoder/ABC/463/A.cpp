#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    if(x%16==0 && y%9==0)
    {
        cout << "Yes";
    }
    else
        cout << "No";

    return 0;
}

// https://atcoder.jp/contests/abc463/tasks/abc463_a