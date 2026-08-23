#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> k;
        vector<int> v(k);
        int sum = 0;
        int cnt3=0;
        int cnt2 = 0;
        for(int i = 0; i < k; i++) {
            cin >> v[i];
            sum += v[i];
            if(v[i] >= 3) cnt3++;
            if(v[i] >= 2) cnt2++;
        }

        if(sum==k || sum==k+1)
        {
            cout << "No\n";
        }
        else
        {
            if(cnt3>=1 || cnt2>=2)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
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
// v[i]는 각 i번째 알파뱃 카드 개수

// 전체 카드 갯수가 k라면 x
// or k+1이라도 x
// 3장이상인 카드가 1개라도 있거나, 2장 이상인 카드가 2개 이상이면 o
// 나머지는 x

// https://codeforces.com/contest/2242/problem/A