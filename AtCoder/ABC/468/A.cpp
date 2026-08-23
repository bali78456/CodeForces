#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    int cnt = 0;

    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= n-2; i++)
    {
        if(v[i] < v[i + 1] && v[i + 1] > v[i + 2])
        {
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1이상 n-2이하인 정수 i중에서 ai < ai+1 > ai+2 만족하는 i의 개수

// https://atcoder.jp/contests/abc468/tasks/abc468_a