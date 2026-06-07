#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<long long>> vec(n+1);
    for(int i = 0; i < n;i++)
    {
        long long c, v;
        cin >> c >> v;
        vec[c].push_back(v);
    }

    vector<long long> top;
    vector<long long> remain;
    for(int i = 1; i <= n; i++) {
        if(vec[i].empty()) continue;

        sort(vec[i].begin(),vec[i].end(),greater<long long>());
        top.push_back(vec[i][0]);

        for(int j = 1; j < vec[i].size();j++)
        {
            remain.push_back(vec[i][j]);
        }
    }


    sort(top.begin(), top.end(), greater<long long>());
    long long ans = 0;
    for(int i = 0; i < m;i++)
        ans += top[i];
    
    for(int i = m; i < top.size();i++)
        remain.push_back(top[i]);

    sort(remain.begin(), remain.end(), greater<long long>());
    for(int i = 0; i < k - m;i++)
    {
        ans += remain[i];
    }
    cout << ans;

    return 0;
}

// https://atcoder.jp/contests/abc461/tasks/abc461_c