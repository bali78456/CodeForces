#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n;i++)
        cin >> a[i];
    vector<ll> diff(n + 2, 0);

    for(ll k = 1; k <= n; k++) {
        ll s = a[k] * k;
        ll e = a[k] * k + k - 1;

        if(s<=n-1)
        {
            ll S = max(0LL, s);
            ll E = min((ll)n - 1, e);
            diff[S] += 1;
            diff[E+1] -= 1;
        }
    }
    vector<int> ans;
    int cur_sum = 0;

    for(int i = 0; i < n;i++)
    {
        cur_sum += diff[i];
        if(cur_sum == 0) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(auto res:ans)
        cout << res << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}
// 1. f(B,k) = ak 가 되려면 집합의 mex값이 ak라는 뜻
//    집합에 ak라는 값은 없어야 하고, 집합에 0부터 ak-1까지의 값이 전부 있어야 한다
// 2. y값으로 봤을 때
//    집합 b에는 ak * k 부터 ak. * k + k - 1 사이의 숫자가 하나라도 들어가면 안된다
//    집합 b에는 v * k 부터 v * k + k - 1 구간 안의 숫자가 하나이상 들어가야 한다
// 3. 0부터 n-1까지의 숫자를 후보로 보고 각 k에 대해 ak*k ~ ak*k+k-1 사이 숫자들 제거
//    남은 숫자 모두를 b에 집어넣는다
// 위 방법은 tle

// 1. diff 배열 만들어서
//    diff(n+1,0) 초기화
//    지워야할 구간 [S,E] 라면
//    diff[S]+=1, diff[E+1]-=1 로 하고
//    누적합 구해서 누적값이 0보다 크면 금지, 0이면 세이프


// https://codeforces.com/contest/2263/problem/C1