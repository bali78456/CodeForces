#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool memo[11][11][27];

void solve()
{
    int n,m;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n;i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    // memo 0으로 초기화
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 26; k++) {
                memo[i][j][k] = 0;
            }
        }
    }

    cin >> m;
    vector<string> v(m);
    for(int i = 0; i < m;i++)
    {
        string s;
        cin >> s;
        v[i] = s;
        for(int j = 0; j < v[i].size();j++)
        {
            memo[v[i].size()][j][v[i][j]-'a'] = true;
        }
    }

    for(int i = 0; i < m;i++)
    {
        if(v[i].size()!=n)
        {
            cout << "No\n";
        }
        else
        {
            bool ans = true;
            for(int j = 0; j < n;j++)
            {
                if(memo[arr[j].first][arr[j].second-1][v[i][j]-'a'] == true) continue;
                else
                    ans = false;
            }
            if(ans) cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1. 글자수가 n이 아니라면 무조건 No

// https://atcoder.jp/contests/abc452/tasks/abc452_c