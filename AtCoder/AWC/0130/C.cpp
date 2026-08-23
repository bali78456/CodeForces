#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

// void solve()
// {
//     int n,k;
//     cin >> n >> k;
//     vector<ll> a(n);
//     for(int i = 0; i < n;i++)
//         cin >> a[i];
//     vector<ll>dp(k,0);
//     dp[0] = 1;
//     for(int i = 0; i < n;i++)
//     {
//         int rem = a[i] % k;
//         vector<ll> next_dp = dp;
//         for(int r = 0; r < k;r++)
//         {
//             int prev_r = (r - rem + k) % k;
//             next_dp[r] = (dp[r] + dp[prev_r]) % MOD;
//         }
//         dp = next_dp;
//     }
//     ll ans = (dp[0] - 1 + MOD) % MOD;
//     cout << ans;
// }

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n;i++)
        cin >> a[i];

    // dp[i][r] = i번째 동아리까지 고려했을 때 나머지가 r이 되는 경우의 수
    vector<vector<ll>> dp(n + 1, vector<ll>(k, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n;i++)
    {
        int rem = a[i] % k;
        for(int r = 0; r < k;r++)
        {
            // 1. i번째 동아리는 선택하지 않는 경우(이전 상태 dp[i-1][r]을 가져옴)
            // 2. i번째 동아리를 선택하는 경우 (이전 상태 dp[i-1][prev_r]에서 가져옴)
            int prev_r = (r - rem + k) % k;
            dp[i][r] = (dp[i - 1][r] + dp[i - 1][prev_r]) % MOD;
        }
    }

    // dp[n][0]은 모든 동아리를 고려했을 대 k의 배수가 되는 경우의 수
    // 1개 이상 선택해야 하므로 공집합(1개)를 뺀다
    ll ans = (dp[n][0] - 1 + MOD) % MOD;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// n개의 동아리활동이 있다
// Ai는 각 동아리의 활동 포인트

// 1. 고른 동아리들의 총 포인트가 K의 배수여야한다
// 2. 최소 1개이상 동아리를 들어가야한다

// output
// 선택할수있는 n개의 동아리 중 1개 이상을 선택하는 모든 방법 가운데
// 선택한 동아리 활동 포인트 합이 k의 배수가 되는 경우의 수 구하라 % MOD


// 정렬먼저
// 1. 각 원소 하나씩 k보다 작으면 탈락
//    k보다 큰것들 중에서 k 배수만 1씩 추가
// 2. 

// https://atcoder.jp/contests/awc0130/tasks/awc0130_c