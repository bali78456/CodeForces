#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n;i++)
            cin >> a[i];

        for(int i = 1; i < n;i++)
        {
            if(a[i]>a[i+1])
            {
                ll temp = a[i + 1];
                ll tempsum=a[i]+a[i+1];
                a[i] = a[i + 1];
                a[i + 1] = tempsum;
            }
        }
        auto it = max_element(a.begin() + 1, a.end());
        cout << *it << "\n";
    }

    return 0;
}


// https://codeforces.com/contest/2237/problem/C