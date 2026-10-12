#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> type;
vector<int> parent;
vector<int> out_degree;

void solve() {
    int n;
    cin >> n;
    type.resize(n + 1);
    parent.assign(n + 1,0);
    out_degree.assign(n + 1, 0);

    for(int i = 1; i <= n;i++)
        cin >> type[i];
    for(int i = 1; i <= n;i++)
    {
        int num;
        cin >> num;
        parent[i] = num;
        out_degree[num] += 1;
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(type[i]==1)
        {
            vector<int> v;
            v.push_back(i);
            int temp = parent[i];

            while(out_degree[temp]==1&&type[temp]!=1&&temp!=0)
            {
                v.push_back(temp);
                temp = parent[temp];
            }
            if(ans.size()<v.size())
            {
                ans = v;
            }
        }
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for(auto a : ans)
        cout << a << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}


// https://codeforces.com/contest/350/problem/B