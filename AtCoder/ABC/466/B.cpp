#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(m+1);
    fill(v.begin(), v.end(), 0);
    for(int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;
        if(i!=0)
        {
            if(v[c]!=0)
            {
                if(v[c]<s)
                {
                    v[c] = s;
                }
            }
            else
                v[c] = s;
        } else
            v[c] = s;
    }
    for(int i = 1; i <= m;i++)
    {
        if(v[i] == 0) cout << -1 << " ";
        else
            cout << v[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// i번째 공의 색은 Ci, 크기는 Si
// 색깔은 1부터 m까지
// 각 색상별 가장 큰 사이즈 출력, 없으면 -1

// https://atcoder.jp/contests/abc466/tasks/abc466_b