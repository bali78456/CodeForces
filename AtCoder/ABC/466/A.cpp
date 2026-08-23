#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int negative=0;
    int positive = 0;
    int zero = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] < 0) negative++;
        if(v[i] == 0) zero++;
        if(v[i] > 0) positive++;
    }

    if(positive > 0 || zero > 0) cout << "No\n";
    else
        cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc466/tasks/abc466_a