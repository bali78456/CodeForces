#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<long long,long long>> v[n];

        for(int i = 0; i < n; i++) {
            long long a, b;
            cin >> a >> b;
            v[i].push_back({a, b});
        }
        pair<long long, long long> fLift = v[0].front();
        for(int i = 1; i < n; i++) {
            if(fLift.first <=v[i].front().first)
            {
                if(fLift.second <= v[i].front().second)
                {
                    cout << -1 << "\n";
                    break;
                }
            }
            if(i==n-1)
            {
                cout << fLift.first << "\n";
            }
        }
    }
    return 0;
}

// n명의 참가자
// si = strength
// ei = endurance

// 1번 참가자가 polycarp 고 polycarp가 이겼으면 좋겠다

// 0이 아닌 정수 w를 고른다 (바벨의 무게)
// 각 참가자는 바벨을 최대한 많이 드는게 목표 (최대 갯수가 동일한 참가자가 있다면 우승자는 없다)

// 1. 참가자의 strength가 w 이상이라면 참가자는 ei 개만큼 들 수 있다.
// 2. 참가자의 strengthrk w 보다 작다면 참가자는 들 수 없다

// output
// ploycarp가 우승할 수 있는 w 출력
// 우승못한다면 -1

// 1. 친구의 최대 무게를 저장하고 그거보다 큰 놈들이 누군지 체크한 다음
// 2. 무게가 더 큰 놈이 친구와 lift 횟수가 같거나 더 크다면 -1 출력
// 3. 그게 아니라면 친구의 무게 출력

// https://codeforces.com/contest/1879/problem/A