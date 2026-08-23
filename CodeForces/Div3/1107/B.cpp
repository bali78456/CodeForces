#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        string ans = "1";
        for(int i = 0; i < s.size();i++)
        {
            if(i == s.size() - 1) ans += '1';
            else
                ans += '0';
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 전체 숫자에서 다른수가 최대 2개만 들어있는 수를 만들어야하는데
// 이 조건을 만족하는 y를 찾고 x*y도 만족해야함

// 자릿수에 맞춰서 11, 101, 1001 등 곱하면 기존 수가 그대로 감

// 각 자릿수별로 
// len = 1 => 11 곱함
// len = 2 => 101 곱함
// len = 3 => 1001 곱함

// https://codeforces.com/contest/2241/problem/B