#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> v(n);
        for(int i = 0; i < n;i++)
            cin >> v[i];
        vector<ll> base;
        for(int i = 0; i < n;i++)
        {
            base.push_back(v[i] - c);
        }
        
        ll p=0;
        for(int i = 0; i < n;i++)
        {
            if(base[i] > 0) p++;
        }

        ll m = 0;
        if(n % 2 != 0) {
            m = (n / 2) + 1;
        }
        else
            m = n / 2;

        ll k = max(m, p);
        sort(base.begin(), base.end(), greater<ll>());
        ll sum = 0;
        for(int i = 0; i < k;i++)
        {
            sum += base[i];
        }
        cout << sum << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// op
// 1. 아무 원소 하나 골라서 스코어에 더하고 배열에서 지움
// 2. 두개의 인접한 원소 고르고 둘중 max를 스코어에 더하고 배열에서 지움(배열에 최소 원소 2개 있을때 가능)

// c는 각 연산할때 드는 비용
// 각 연산마다 내 스코어에서 c를 빼야됨

// max 스코어 출력

// 1. 모든 원소에서 c를 뺀 새로운 배열 base 만든다
// 2. base에서 0보다 큰 양수 원소의 개수 p 센다
// 3. max(n/2,p)를 계산
// 4. base 원소들을 내림차순 정렬하고 k개 원소의 합 출력

// https://codeforces.com/contest/2245/problem/B