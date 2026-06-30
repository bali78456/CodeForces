#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        for(int b = 1; b <= n; b++) {
            ll cnt = n / b;
            ans += cnt*cnt;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 1부터 n까지 번호가 있음
// gcd(lcm(a,b),lcm(b,c))=gcd(a,c)를 만족하는 경우의 수 출력
// n=1 => 1
// n=2 => 2
// n=20 => 612

// 1. 조건을 만족하는 a,b,c는 오직
// a와 c가 모두 b의 배수일 때 (b가 a와 c의 공약수일 때) 뿐이다
// 2. a가 b의 배수이므로 lcm(a,b)=a
//    c가 b의 배수이므로 lcm(b,c)=c

// 조건
// a와 c는 b의 배수여야 한다

// 1. b를 기준으로 잡고 루프를 돈다
// 2. 1부터 n까지의 자연수 중 b의 배수는 총 n/b개 존재
// 3. a와 c는 서로 독립적으로 b의 배수 중에서 아무거나 고르면 된다
// 4. 따라서 b에 대해 가능한 (a,c) 쌍의 개수는 n/b * n/b => (n/b)^2
// 5. 모든 가능한 b에 대해 이 값들을 더해주면 됨

// https://codeforces.com/contest/2238/problem/B