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
        vector<pair<long double, long double>> v;
        long double S = 1;

        for(int i = 0; i < n; i++) {
            double c, p;
            cin >> c >> p;
            v.push_back({c, p});
        }
        long double DP[100001];
        DP[n - 1] = v[n-1].first;
        DP[n - 2] = max(DP[n - 1], DP[n - 1] * (1 - (v[n - 2].second / 100)) + v[n - 2].first);

        for(int i = n - 3; i >= 0;i--)
        {
            DP[i] = max(DP[i+1], DP[i+1] * (1 - (v[i].second / 100)) + v[i].first);
        }

        cout << fixed << setprecision(10);
        cout << DP[0] << "\n";

        fill(DP, DP + 100001, 0);
    }

    return 0;
}

// ci = 가치
// pi = 난이도
// 초기체력 = 1 = S

// 1-n까지 작업 수행하는데
// 1. 작업 포기 = 아무일도 일어나지 않음
// 2. 작업 완료 => S * ci 만큼의 점수 획득 하지만 작업 완료 후 체력 S는 
// S * (1 - pi/100)이 됨
// 3. 모든 과정을 마쳤을 때 얻을 수 있는 최대 점수 구해라

// 1. S는 선택에 영향을 주지 않는다.
// 2. 


// https://codeforces.com/contest/2208/problem/C