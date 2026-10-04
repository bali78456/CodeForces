#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    vector<ll> v;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        if(i>=k&&i<=n-k+1)
        {
            ans += a[i];
            continue;
        }
        v.push_back(a[i]);
    }
    int t2 = max(0, (int)v.size() - (k - 1));
    int l = 0;
    int r = v.size()-1;
    while (t2--)
    {
        ans += max(v[l], v[r]);
        l++;
        r--;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}
// op
// 배열의 원소가 k개 이상이라면 다음 연산 중 하나 수행
// 1. ak를 제거하고 그 값을 점수에 더한다
// 2. a(m-k+1)을 제거하고 그 값을 점수에 더한다(m은 이 연산을 수행하기 전 배열 a의 길이)
// 얻을 수 있는 최대 점수

// 에디토리얼
// 1. 2k=n 인 경우
//    1,6 2,5 3,4 등 페어를 만들어서 각각 페어의 max값 저장
// 2. 2k<=n 인 경우
//    k<=i<=n-k+1 사이 원소들은 무조건 삭제
//    가운데를 제거하고 나면 앞쪽 k-1개 뒤쪽 k-1개
//    이제 양쪽에서 pair만들어서 max값 저장
// 3. 2k>n 인 경우
//    n-k+2 <= i <= k-1 인 원소들은 절대 삭제되지 않는다
//    나머지는 똑같이 pair 만들어서 연산
//

// https://codeforces.com/contest/2269/problem/C