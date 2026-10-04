#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k, n;
        cin >> n >> k;
        string s;
        cin >> s;

        int ans = 0;
        for(int i = 0; i < s.length(); i += k) {
            int cnt0 = 0;
            for(int j = i; j < k + i;j++)
            {
                if(s[j] == '0')
                {
                    cnt0++;
                }
            }
            if(cnt0 == 0) ans++;
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
// si = 1 이면 i번째 들판은 농부 노지 소유 0이면 농부 노지 소유가 아니다
// 농부 노지의 땅에 학교를 지어야 하는 최소 횟수 출력

// 1. 문자열 처음부터 k개만큼 돌면서 0이 하나라도 있으면 no 0이 하나도 없으면 cnt++

// https://codeforces.com/contest/2259/problem/A