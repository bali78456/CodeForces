#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin >> s;

        int cnt=1;
        char c = s[0];
        for(int i =1; i < n; i++)
        {
            if(c!=s[i])
            {
                cnt++;
                c = s[i];
            }
        }

        if(cnt==1)
        {
            cout << 1<<"\n";
        }
        else
        {
            int minus=0;
            int small = 1000;
            for(int i = 1; i < n - 1; i++) {
                if(s[i]==s[i+1]&&s[i]==s[i-1])
                {
                    minus = 0;
                    small = min(small, minus);
                }
                else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]==s[i+1])
                {
                    minus = -2;
                    small = min(small, minus);
                }
                else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
                {
                    minus = -1;
                    small = min(small, minus);
                }
                else
                {
                    minus = 0;
                    small = min(small, minus);
                }
            }
            cout << cnt + small << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 일단 붙어있는거 다 지운 개수 카운트
// 맨 앞이나 맨 뒤는 못지움

// 1. si를 지운다면 si-1 si+1 확인
//    si랑 두 문자가 같다면 어차피 1이니까 변화 0
//    si랑 두 문자가 전부 다르다면 변화 -1
//    두 문자만 같다면 변화 -2
// 2. 이 중 가장 작은 값 하나 찾아서 카운트에 더해주면 됨

// https://codeforces.com/contest/2254/problem/B