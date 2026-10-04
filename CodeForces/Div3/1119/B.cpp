#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        int odd=0;
        int even = 0;
        int ans0=0;
        int ans2 = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2 == 0) 
            {
                if((a[i]/2)%2==0)
                {
                    ans0++;
                }
                else
                    ans2++;
            }
            else
            {
                odd++;
            }
        }
        cout << max(odd, max(ans0, ans2))<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// ai = |ai-2|로 바꿀수있다 (한번 연산할때마다 모든 원소들에 적용)
// 배열 a에서 나타날 수 있는 정수의 최대 빈도 수 출력

// 6 7 8
// 4 5 6
// 2 3 4
// 0 1 2
// 2 1 0
// 0 1 2
// 홀수면 1로 되고
// 짝수인데 2로 나눈 몫이 홀수면 0 짝수면 2 반복

// https://codeforces.com/contest/2259/problem/B