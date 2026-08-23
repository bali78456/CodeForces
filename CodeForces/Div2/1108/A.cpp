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

        vector<int> v;
        v.push_back(2);
        for(int i = 3; i <= n; i++) {
            v.push_back(i);
        }
        v.push_back(1);

        for(auto &a:v)
            cout << a << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 1. 카운터 c=0으로 초기화
// 2. 1부터 n까지 각 i에 대해 i*pi의 값을 c에 더하거나, c에서 빼거나
//      아무것도 안한다
// 3. 이때 최종적으로 만들어진 카운터의 값을 Cfinal이라고 한다

// 최종 카운터 값 Cfinal이 절대 1이 될수 없는
// 1부터 n까지 한번씩만 등장하는 순열 출력

// 2 1
// 2 3 4 1
// 2 3 4 5 6 1

// https://codeforces.com/contest/2246/problem/A