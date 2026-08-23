#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b, a % b);
}

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, y, n;
        cin >> n >> x >> y;
        vector<ll> v(n);
        vector<ll> temp;
        for(int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        temp = v;
        sort(temp.begin(), temp.end());

        if(temp == v) cout << "Yes\n";
        else
        {
            bool ans = true;
            ll num = gcd(x, y);
            for(int i = 0; i < n;i++)
            {
                if((i+1)%num!=v[i]%num)
                {
                    ans = false;
                    break;
                }
            }
            if(ans) cout << "Yes\n";
            else
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

// 두 인덱스 i,j를 선택해서
// |i-j|=x or |i-j|=y 라면 두 원소 pi와 pj의 위치를 바꿀수있다
// 이 연산 수행해서 순열을 오름차순으로 바꿀수있는가

// gcd로 풀린다

// 1. x,y에 따라 이동할수있는 인덱스범위가있음
// 2. i번째 인덱스 % gcd랑  v[i]%gcd랑 같으면 같은 인덱스범위 안에있어서 서로 교환가능함
// 3. 그게아니면 정렬불가

// 5 4 2 1 3
// 1 2 3 4 5


// https://codeforces.com/contest/2244/problem/C