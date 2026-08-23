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
        vector<ll> v(n);
        for(int i = 0; i < n;i++)
            cin >> v[i];

        bool ans = true;
        ll temp = v[0] - 1;
        for(int i = 1; i < n; i++) {
            ll num = v[i] + temp;
            if(num >= i + 1) {
                temp = num - (i + 1);
            }
            else if(num<i+1)
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1부터 n까지 한줄로 책을 쌓아둠
// i번째 더미에는 ai권의 책이 있다
// 가장 오른쪽에 있는 책을 제외한 모든 책 개수가 바로 오른쪽에 있는 책 개수보다 작다면
// neat 다

// 1. 1<=i<n 이고 ai>1을 만족하는 책 더미 i 선택
// 2. i번째 더미의 맨 위에서 책 1권을 가져온다. ai 1 감소
// 3. 이 책을 i+1번째 더미의 맨 위에 올려놓는다. ai+1 1 증가

// 증가하는 수열 a1<a2<a3..<an
// 0은 될수없으니 1<2<3<4..<n 
// 앞에서부터 1 2 3 씩 빼면서 다음으로 넘겨서 만들수있으면 yes 아니면 no

// https://codeforces.com/contest/2244/problem/B