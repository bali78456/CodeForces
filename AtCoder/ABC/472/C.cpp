#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n;i++)
        cin >> a[i];

    ll sum = 0;
    ll days = 0;
    queue<pair<ll, ll>> q;
    ll temp = 0;
    for(int i = 0; i < n; i++) {
        if(i!=0)
        {
            if(!q.empty())
            {
                if(q.front().first <= i - m + 1) {
                    temp = q.front().second;
                    q.pop();
                    if(sum - temp >= 0) sum -= temp;
                    else
                        sum = 0;
                }
            }
        }

        if(sum+a[i]<=k)
        {
            cout << "Yes\n";
            sum += a[i];
            q.push({i+1,a[i]});
            
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 최근 m일동안 먹은 칼로리가 k를 넘으면 안된다

// 1. 큐에 먹은 칼로리, 먹은날짜 푸시
// 2. 다음 음식 먹기 전마다 m일 지났는지 체크

// https://atcoder.jp/contests/abc472/tasks/abc472_c