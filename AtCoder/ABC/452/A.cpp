#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, d;
    cin >> m >> d;

    if(m == 1 && d == 7) cout << "Yes";
    else if(m == 3 && d == 3) cout << "Yes";
    else if(m == 5 && d == 5) cout << "Yes";
    else if(m == 7 && d == 7) cout << "Yes";
    else if(m == 9 && d == 9) cout << "Yes";
    else
        cout << "No";

    return 0;
}

// https://atcoder.jp/contests/abc452/tasks/abc452_a