#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, s, l;
    cin >> n >> s >> l;
    vector<ll> a(n);
    vector<ll> prefix(n+1,0);
    for(int i = 1; i < n; i++) {
        cin >> a[i];
    }

    prefix[1] = 0;
    for(int i = 2; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i-1];
    }

    int ans = 0;
    ll dist = 0;
    for(int i = 1; i <= s; i++) {
        for(int j = n; j >=s;j--)
        {
            dist = min(2*(prefix[s]-prefix[i])+prefix[j]-prefix[s],(prefix[s]-prefix[i])+(prefix[j]-prefix[s])*2);
            if(dist <= l) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// n개의 마을 1 to n
// 1부터 n-1까지 i번째 마을은 i+1 마을과 길이 ai인 도로와 연결
// s마을에서 시작
// 총 이동거리 l 이하가 되도록 이동할 때 방문할 수 있는 마을의 최대 개수
// 처음 위치 s도 포함, 여러번 방문한 마을은 한번만 계산

// 1. 거리 누적합
// 2. 1 to s, s to n 까지 이중 for문으로 각 경우의 수 다 확인
// 3. 왕복하는 경우는 왼쪽 오른쪽 따로 각 * 2 해서 min값

// https://atcoder.jp/contests/abc475/tasks/abc475_c