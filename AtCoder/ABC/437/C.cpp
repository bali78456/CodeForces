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
        vector<ll> wp(n + 1);
        ll sum = 0;
        ll sumP = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ll w, p;
            cin >> w >> p;
            wp[i] = w + p;
            sumP += p;
        }
        sort(wp.begin() + 1, wp.end());
        for(int i = 1; i <= n;i++)
        {
            if(sum+wp[i]<=sumP)
            {
                sum += wp[i];
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

// i 번째 reindeer 무게는 wi, 힘은 pi
// pull or ride 골라야한다
// pull 하는 reindeer의 힘은 ride하는 reindeer의 무게 총합과 같거나 더 커야함
// output => max num of reindeer that can ride on the sled

// ex)
// 3
// 3 1
// 4 1
// 5 9
// 일 때 3번이 끈다면 1, 2번은 탈수있다
// 3번의 pi = 9 이고
// 1,2 번의 w1 + w2 = 7 이니까

// 1. w+p 값을 저장한 후 sort
// 2. 낮은 무게부터 더해준다 => sum <= sumP 까지

// https://atcoder.jp/contests/abc437/tasks/abc437_c