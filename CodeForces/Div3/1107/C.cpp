#include <bits/stdc++.h>
using namespace std;

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
        char ch = s[0];
        int c = 1;
        for(int i = 1; i < n;i++)
        {
            if(ch != s[i])
            {
                c++;
                ch = s[i];
            }
        }
        
        if(c == 1 || c > 2) cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 01010
// 0010
// 000
// 00
// 0

// 00 11 101 010 이 있으면 지울 수 있다

// 에디토리얼
// 1. 주어진 문자열을 1,0 으로 나눠진 블럭으로 놓고
// 2. 이 경계를 c라고 했을 때
// 3. c==1 || c > 2 라면 1
//    c==2 라면 2

// https://codeforces.com/contest/2241/problem/C