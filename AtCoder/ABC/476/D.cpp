#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll x, y;
    cin >> x >> y;
    vector<ll> a(n);
    vector<ll> b(m);
    vector<ll> prefixA(n);
    vector<ll> prefixB(m);
    for(auto& num : a)
        cin >> num;
    for(auto &num:b)
        cin >> num;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    prefixA[0] = a[0];
    prefixB[0] = b[0];
    for(int i = 1; i < n;i++)
        prefixA[i] = prefixA[i - 1] + a[i];
    for(int i = 1; i < m;i++)
        prefixB[i] = prefixB[i - 1] + b[i];

    ll ans = 0;
    ll total = x + y * k;
    ll cur_k_used = 0;

    ll max_dessert = upper_bound(prefixA.begin(), prefixA.end(), total)-prefixA.begin();
    ans = max_dessert;

    for(int i = 0; i < m;i++)
    {
        cur_k_used += (b[i] + k - 1) / k;
        if(cur_k_used > y) break;

        ll remain_m = total - prefixB[i];
        ll dessert_cnt = upper_bound(prefixA.begin(), prefixA.end(), remain_m) - prefixA.begin();
        ans = max(ans, (ll)(i + 1) + dessert_cnt);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// N개 디저트, M개 음료
// a[i]는 i번째 디저트 가격
// b[i]는 i번째 음료 가격
// 디저트 자판기는 1달러짜리와 k달러짜리 지폐 받는다
// 음료 자판기는 k달러짜리 지폐만 받는다
// 두 자판기 모두 거스름돈은 1달러짜리만 준다
// 같은 물건은 두개이상 살수없다
// X개 1달러 지폐, Y개 k달러 지폐 들고있다
// 살수있는 최대 품목 개수 출력

// 1. a, b 배열 모두 오름차순 정렬
// 2. 각 배열 prefix sum 구해둔다
// 3. 

// https://atcoder.jp/contests/abc476/tasks/abc476_d