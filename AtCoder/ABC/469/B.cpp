#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt=0;

    if(s.length() == 1 && s[0] == 'x') cnt++;

    if(s[1] == 'x' && s[0]=='x') cnt++;
    if(s[s.length() - 2] == 'x' && s[s.length()-1]=='x') cnt++;
    for(int i = 1; i < s.length()-1; i++) {
        if(s[i - 1] == 'x' && s[i] == 'x' && s[i + 1] == 'x') cnt++;
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1. 사람이 앉아있지 않다
// 2. 왼쪽에 의자가 없거나, 왼쪽 의자에 사람이 앉아있지않다
// 3. 오른쪽에 의자가 없거나, 오른쪽 의자에 사람이 앉아있지 않다.

// 1. 현재위치 기준 좌우 i-1, i+1이 x인곳

// 8
// oxoxoxox

// https://atcoder.jp/contests/abc469/tasks/abc469_b