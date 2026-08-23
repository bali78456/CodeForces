#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int q;
    cin >> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll plus = 0;
    for(int i = 0; i < q; i++) {
        int num;
        ll x;
        cin >> num;
        if(num==1)
        {
            cin >> x;
            pq.push(x-plus);
        } else if(num == 2) {
            cin >> x;
            plus += x;
        } else {
            ll temp = pq.top();
            cout << temp + plus << "\n";
            pq.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1 쿼리 : Xi를 가방에 넣는다
// 2 쿼리 : 가방에 있는 각 공의 숫자를 Xi를 더한 값으로 교체
// 3 쿼리 : 가장 작은 숫자 꺼내서 출력

// 2번쿼리 이후에 들어온 애들은 그전의 plus를 적용하면 안됨

// https://atcoder.jp/contests/abc212/tasks/abc212_d