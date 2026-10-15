#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> ans;
    int cntS = 0;

    for(int i = 1; i < s.length(); i++) {
        if(s[i] == s[i - 1] && s[i] == 'R') cnt++;
        else
        {
            ans.push_back(cnt);
            cnt = 0;
        }
    }

    for(auto c:s) if(c=='S') cntS++;

    ans.push_back(cnt);
    int m = *max_element(ans.begin(), ans.end());
    if(cntS==n) {
        cout << 0;
    }
    else if(m==0)
    {
        cout << 1;
    } else
        cout << m + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc479/tasks/abc479_b