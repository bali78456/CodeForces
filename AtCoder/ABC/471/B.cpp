#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    unordered_map<string, int> m;
    string s;
    for(int i = 0; i < n;i++)
    {
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
        m[s]++;
    }
    if(!m.empty())
    {
        auto max_it = max_element(m.begin(), m.end(), [](const auto& a, const auto& b) { return a.second < b.second; });
        cout << max_it->second;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc471/tasks/abc471_b