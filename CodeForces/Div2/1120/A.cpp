#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt1 = 0;
    int cnt0 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) cnt1++;
        else
            cnt0++;
    }

    if(cnt0 > cnt1) cout << "Elsie" << "\n";
    else
        cout << "Bessie" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}
// bessie가 먼저 시작
// 인접한 두 원소 골라서 max(x,y)로 교체
// elsie턴에는 
// 인접한 두 원소 골라서 min(x,y)로 교체
// 원소가 1개만 남았을 때 게임 종료
// 1이 남으면 bessie 이기고, 0 남으면 elsie 이김

// https://codeforces.com/contest/2263/problem/A