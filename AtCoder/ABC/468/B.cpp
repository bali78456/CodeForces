#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int m,d;
    cin >> m >> d;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        if(s[i]=='G')
        {
            for(int j = i+1; j <= i + d;j++)
            {
                if(j<m)
                {
                    if(s[j]!='G')
                        s[j] = 'x';
                }
            }

            for(int j = i - d; j < i;j++)
            {
                if(j>=0 && j<m)
                {
                    if(s[j]!='G')
                        s[j] = 'x';
                }
            }
        }
    }
    for(int i = 0; i < m;i++)
    {
        if(s[i] == '.') cnt++;
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 각각 g찾아서 g랑 좌우 d칸만큼 다른걸로 바꿔놓고 최종 . 만 센다

// https://atcoder.jp/contests/abc468/tasks/abc468_b