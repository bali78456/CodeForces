#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, d;
    cin >> a >> d;
    if(d > a || d==a) cout << "Yes";
    else
        cout << "No";

    return 0;
}

// https://atcoder.jp/contests/abc461/tasks/abc461_a