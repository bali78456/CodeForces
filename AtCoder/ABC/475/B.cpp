#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int> charge(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]%1000!=0)
            charge[i] = (a[i] / 1000) + 1;
        else
            charge[i] = a[i] / 1000;
    }

    vector<int> ans(3,0);
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        int temp = (charge[i] * 1000) - a[i];
        
        if(temp%100!=0)
        {
            cnt += (temp / 100) + 1;
            ans[2] += cnt-1;
        }
        else
        {
            cnt += temp / 100;
            ans[2] += cnt;
            continue;
        }
        cnt = 0;

        temp = temp % 100;

        if(temp%10!=0)
        {
            cnt += (temp / 10) + 1;
            ans[1] += cnt-1;
        } else {
            cnt += (temp / 10);
            ans[1] += cnt;
            continue;
        }
        cnt = 0;

        temp = temp % 10;

        cnt += temp;
        ans[0] += cnt;
    }

    for(auto a:ans)
    {
        cout << a << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 1000으로 나눈 몫 + 1

// https://atcoder.jp/contests/abc475/tasks/abc475_b