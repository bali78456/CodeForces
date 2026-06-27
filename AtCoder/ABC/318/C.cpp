#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, d, p;
    cin >> n >> d >> p;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll temp=0;
    ll ans = 0;
    while(!v.empty()) {
        int idx=0;
        for(int i = v.size()-1; i >= 0;i--)
        {
            if(idx<d)
            {
                temp += v[i];
                idx++;
            }
            else
                break;
        }
        if(temp >= p) {
            ans += p;
            for(int i = 0; i < d; i++)
            {
                if(!v.empty())
                    v.pop_back();
            }

            temp = 0;
        } else {
            break;
        }
    }
    if(!v.empty())
    {
        for(int i = 0; i < v.size();i++)
        {
            ans += v[i];
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
// 각 날마다 요금 지불할지 패스 쓸지 선택

// 패스 가격은 P고 패스 하나로 D 만큼의 일수 패스가능

// 1. 모든 날짜 가격 합한것과 전부다 패스로 통과했을 때의 가격 비교
// 2. 패스를 몇 개만 쓴 날짜 비교

// 1. 패스 써서 가장 비싼날들만 패스
// => 패스로 패스한 날들의 합이 패스 가격보다 비싸다면 패스 사용
// 그게 아니라면 그냥 

// https://atcoder.jp/contests/abc318/tasks/abc318_c