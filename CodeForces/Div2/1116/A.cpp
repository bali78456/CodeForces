#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        auto Min = min_element(v.begin(), v.end());
        auto Max = max_element(v.begin(), v.end());
        if(*Min==*Max)
        {
            cout << 0 << "\n";
        }
        else
        {
            sort(v.begin(), v.end());
            if(v[0]+v[1]<v[2])
            {
                cout << (v[0] + v[1]) - v[0]<<"\n";
            }
            else
            {
                cout<<(v[2]) - v[0]<<"\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://codeforces.com/contest/2256/problem/A