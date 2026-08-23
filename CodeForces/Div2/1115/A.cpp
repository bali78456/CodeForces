#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(1001,0);
        for(int i = 0; i < n;i++)
        {
            int num;
            cin >> num;
            v[num]++;
        }
        vector<pair<int, int>> vp;
        for(int i = 1; i <= 1000; i++) {
            if(v[i]!=0)
            {
                vp.push_back({v[i], i});
            }
        }
        sort(vp.rbegin(), vp.rend());

        int X=vp[0].second;
        int F = vp[0].first;
        int O = 0;
        int sum = 0;
        for(int i = 1; i < vp.size(); i++) {
            O += vp[i].first;
            sum += vp[i].second*vp[i].first;
        }
        cout << sum + X * min(F, O + 2)<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 동일한 카드 2장 연속으로 쓰면 방어막 활성화돼서 3번째 카드부터 데미지 안들어감

// 에디토리얼
// 1. 가장 많이 등장하는 카드의 데이지 = X, 개수 = F
// 2. X가 아닌 나머지 모든 카드들의 총 개수 = O
// 3. O 개의 다른 카드가 있을 때 낼 수 있는 X의 최대 개수는 O + 2 개
// 4. 실제로 가지고 있는 X의 개수 F가 O+2보다 작다면 모든 F사용가능
// 5. 나머지 O 카드들도 전부 사용 가능
// 6. 최대 데미지 = (나머지 모든 카드들의 데미지 합) + X*min(F,O+2);

// https://codeforces.com/contest/2252/problem/A