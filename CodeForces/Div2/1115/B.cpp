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
        cin >> n;
        string s;
        cin >> s;

        // 문자열 압축과정에서 지운 개수
        int L = 0;
        char c = s[0];
        string sh = "";
        sh += c;
        for(int i = 1; i < n; i++) {
            if(s[i]!=c)
            {
                c = s[i];
                sh += c;
            }
        }
        L = n - sh.length();

        // del(n) 원본 문자열의 0/1 개수 차이
        int c1=0;
        int c0 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') c0++;
            else
                c1++;
        }
        int delN = (c0 - c1);

        // del(L) 압축된 문자열의 0/1 개수 차이
        int L1=0;
        int L0 = 0;
        for(int i = 0; i < sh.length();i++)
        {
            if(sh[i] == '0') L0++;
            else
                L1++;
        }
        int delL = (L0 - L1);

        if(abs(delN)>2)
        {
            cout << -1 << "\n";
        }
        else cout << L + max(0, abs(delN - delL) - 1) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 에디토리얼
// 1. 전체 삭제 수 = (문자열 압축 과정에서 지운 개수) + (양 끝에서 추가로 지운 개수)
//      = (n-L) + max(0, |del(n) - del(L)| - 1)
// del(n) = n0 - n1 ( 원본 문자열의 0/1 개수 차이)
// del(L) = 압축된 문자열의 0/1 개수 차이
// del(n) > 2 라면 -1

// https://codeforces.com/contest/2252/problem/B