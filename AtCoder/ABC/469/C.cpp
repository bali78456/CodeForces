#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> x(n + 1);

    int cnt = 1;
    for(int i = 0; i < n; i++) {
        if(s[i]=='x')
        {
            x[cnt] = i + 1;
            cnt++;
        }
    }
    for(int i = 1; i <= n;i++)
    {
        cout << (x[i] != 0 ? x[i] : n) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 문자열에서 x의 등장위치, 순서와 인덱스 저장 (1_idx)
// ex) x[1]=4 라면 첫번째 x의 등장 위치 인덱스가 4다
// x[i]==0 이라면 x는 등장하지않는거

// n=8
// x(1) o(4) o(7) x(8) o(8) o(8) x(8) o(8)
// 1 1
// 2 4
// 7 8

// https://atcoder.jp/contests/abc469/tasks/abc469_c