#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 100000000

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i = 1; i <= n;i++)
    {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());

    ll elementSum = 0;
    ll totalSum = 0;
    for(int i = 1; i <= n;i++)
        elementSum += v[i];
    totalSum = elementSum * (n - 1);


    // Aj >= 10^8 - Ai 인 쌍
    ll cnt = 0;
    for(int i = 1; i <= n; i++) {
        ll target = MOD-v[i];
        auto it = lower_bound(v.begin()+1+i, v.end(), target);
        cnt += (v.end() - it);
    }
    ll ans = totalSum - (cnt * MOD);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// Ai < 10^8 이기 때문에
// Ai+Aj < 10^8 이라면 나머지는 Ai+Aj
// Ai+Aj > 10^8 이라면 나머지는 Ai+Aj-10^8
// 모든 쌍을 더한다음 Ai+Aj > 10^8 인 쌍이 몇개인지 찾아야함

// 원소가 n개일 때 모든 쌍의 합은 n-1 * (각 원소의 합)

// 합이 10^8이상인 쌍 찾기
// Aj >= 10^8 - Ai 인 쌍
// 정렬한 뒤 lowr_bound로 찾아라

// 1. 수열 정렬
// 2. 모든 쌍을 더했을 때의 값 구하기
// 3. 이진탐색으로 10^8을 넘기는 쌍의 개수 찾기
// 4. 찾아낸 쌍의 개수 * 10^8만큼 수열의 총합에서 빼기

// https://atcoder.jp/contests/abc353/tasks/abc353_c