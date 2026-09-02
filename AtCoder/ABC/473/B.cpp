#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    for(int i = 0; i < n;i++)
    {
        for(int j = i+1; j < n;j++)
        {
            if(a[i]==a[j] && a[i]!=-1&&a[j]!=-1)
            {
                a[i] = -1;
                a[j] = -1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]!=-1)
        {
            ans += a[i];
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 두장의 같은 카드 골라서 그 두장먹는다(먹은 카드는 사라짐)

// https://atcoder.jp/contests/abc473/tasks/abc473_b