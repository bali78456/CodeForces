#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> P(n);
    vector<int> Q(n);
    for(int i = 0; i < n; i++)
        cin >> P[i];
    for(int i = 0; i < n;i++)
        cin >> Q[i];

    
    if(P>=Q)
    {
        cout << 0;
    }
    else
    {
        int cnt = 0;
        while(next_permutation(P.begin(), P.end())) {
            if(P==Q)
            {
                break;
            }
            cnt++;
        }
        cout << cnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    solve();

    return 0;
}

// 1. P, Q 먼저 비교해서 P가 Q보다 크다면 무조건 0개

// https://atcoder.jp/contests/abc468/tasks/abc468_c