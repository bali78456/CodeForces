#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

void solve()
{
    string n;
    int k, r;
    cin >> n >> k >> r;
    if(k > 1) cout << 0;
    else {
        ll mod = 0;
        for(char c:n)
        {
            mod = (mod * 10 + (c - '0')) % MOD;
        }
        ll ans = (mod - 2 + MOD) % MOD;
        cout << ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// digit sum MOD k == r 이라면 당첨
// 2 <= x <= n-1 사이에 있는 x가
// x-1, x, x+1 MOD k == r 인 x의 개수 MOD 출력

// 1을 k로 나눈 나머지가 0이되는 정수 k는?
// 1

// https://atcoder.jp/contests/awc0126/tasks/awc0126_b