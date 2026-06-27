#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << min(a, min(c, (a + b + c) / 3))<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// AAC -> A 카드 2개, C 카드 1개 사용
// ABC -> A 카드 1개, B 카드 1개, C 카드 1개 사용
// ACC -> A 카드 1개, C 카드 2개 사용
// 3 종류 대회 개최 가능

// 상한선
// 1. 총 횟수는 A를 넘을 수 없다
// 2. 총 횟수는 C를 넘을 수 없다
// 3. 뭘 하든 총 3장의 카드가 쓰이니까 (A+B+C)/3을 못넘는다
// => X = min(A,C,(A+B+C)/3)

// https://atcoder.jp/contests/abc422/tasks/abc422_c