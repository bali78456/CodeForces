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

        for(int i = 0; i < s.length(); i++) {
            if(s[i]=='0')
            {
                s.erase(i, 1);
                break;
            }
        }

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i]=='1')
            {
                s.erase(i, 1);
                break;
            }
        }
        cout << s << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 엘리스는 0을 하나 지운다
// 밥은 1을 하나 지운다
// 엘리스는 최종 문자열이 사전순으로 최대한 크게
// 밥은 최대한 작게

// 각각 한번씩만 연산수행

// 0101010000010100100101
// 01010000010100100101

// https://codeforces.com/contest/2248/problem/A