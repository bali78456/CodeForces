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
        string s;
        cin >> s;
        int cnt=0;
        int len = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '#') cnt++;
            else if(s[i]=='*')
            {
                len = max(cnt, len);
                cnt = 0;
            }
            len = max(cnt, len);
        }
        if(len==0)
        {
            cout << 0 << "\n";
        }
        else if(len%2==0)
            cout << len / 2 << "\n";
        else
            cout << (len / 2) + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 지울수있는 선의 최대시간 하나 골라라

// 짝수면 /2, 홀수면 /2 + 1

// https://codeforces.com/contest/2244/problem/A