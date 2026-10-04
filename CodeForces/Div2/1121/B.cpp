#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(auto &q:a)  cin >> q;

    priority_queue<ll> pq;
    ll sum = 0;
    ll ans = LLONG_MIN;

    for(int j = 0; j < n;j++)
    {
        if(pq.size()==m-1)
        {
            ans = max(ans, static_cast<ll>(m) * a[j] - sum);
        }
        pq.push(a[j]);
        sum += a[j];    

        if(pq.size()>m-1)
        {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}

// 공식 변형
// mb_m - b_i(1<=i<=m-1)
// 마지막 원소 b_m에 m곱하고 나머지 m-1개 뺀다

// 마지막으로 고를 원소가 a_j라면 a_j앞에 있는 원소 중에서 가장 작은 m-1개 선택
// ma_j - (앞의 m-1개 최소값들의 합)

// max heap을 이용해서 가장 작은 값 m-1개 유지
// 1. 현재 heap을 이용해서 a[j]를 마지막으로 했을 때의 답 계산
// 2. a[j]를 heap에 넣기
// 3. heap 크기가 m보다 커지면 최대값 제거

// https://codeforces.com/contest/2264/problem/B