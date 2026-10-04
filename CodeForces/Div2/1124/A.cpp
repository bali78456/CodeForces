#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    int x = 1;
    int i = 1;
    for(i = 1; i < k; i++) {
        x*=2;
        ans += x;
        x = 1;
    }
    ans += pow(2, n-i+1);
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
// 계좌 잔고 x가 있고
// 매일아침 잔고가 2배가 된다
// 매일 저녁 출금할수있다. 출금한만큼 카드에 추가되고 잔고는 즉시 1달러가 된다
// 또는 출금하지않고 남겨둘수도있음
// n일 뒤 은행이 문을 닫는다
// k번 출금하려한다

// output
// max값 카드에 있는 돈 출력

// 1. k=1이면 마지막날에만 뽑고
// 2. k-1만큼 1일차부터 바로바로뽑고
//    하나 남은건 맨마지막에 뽑으면 됨

// https://codeforces.com/contest/2269/problem/A