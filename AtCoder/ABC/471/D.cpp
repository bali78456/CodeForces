#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll q,v;
    cin >> q >> v;
    priority_queue<ll> pq;
    for(int i = 0; i < q;i++)
    {
        ll num,t,w;
        cin >> num;
        if(num==1)
        {
            cin >> t >> w;
            pq.push(w - t);
        } else {
            cin >> t;
            if(pq.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                ll temp = pq.top();
                pq.pop();
                cout << min(v,temp + t) << "\n";
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

// https://atcoder.jp/contests/abc471/tasks/abc471_d