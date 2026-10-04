#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n,0);
    
    while(m!=0)
    {
        for(int i = 0; i < n;i++)
        {
            if(m==0)
            {
                break;
            }

            v[i]++;
            m--;
        }
    }

    for(auto ans:v)
        cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/abc478/tasks/abc478_a