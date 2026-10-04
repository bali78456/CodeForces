#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;

    ll d = y - x;
    ll ans = 0;
    ll i = 0;
    while(x + i <= d) {
        if(i == k) break;
        ans += (x + i + d) % (x + i);
        i++;
    }
    
    if(k-i<=0)
    {
        cout << ans << "\n";
    }
    else
        cout << ans+(k-i)*d << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}
// 0<=i<k 에서
// 본인 제외한 x명의 직원, 해야되는 프로젝트 y개
// 매달 직원과 프로젝트는 i씩 증가

// y-x의 차이는 항상 같다 == d
// (y+i) mod (x+i) ==> (x+i)+d mod (x+i)
// 계속 mod 하다보면 결국 d로 고정됨
// x+i > d 까지 for문으로 계산하고
// 나머지는 (k-i) * d

// https://codeforces.com/contest/2260/problem/B