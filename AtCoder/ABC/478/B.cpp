#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, v;
    cin >> n >> v;
    vector<int> w(n);
    for(auto &a:w)
        cin >> a;


    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n;j++){
            for(int k = 0; k < n;k++){
                if(i+j+k+3 <= v && i!=j &&i!=k&&j!=k)
                {
                    ans = max(ans, w[i] + w[j] + w[k]);
                }
            }
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
// total price 가 최대 v가 되도록
// 고르는 토핑 max값 구해라 토핑은 항상 3개만 고름

// 인덱스 합 v 초과안하는 모든 조합의 합 저장
// 

// https://atcoder.jp/contests/abc478/tasks/abc478_b