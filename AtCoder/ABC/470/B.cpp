#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(101,0);
    for(int i = 0; i < n;i++)
    {
        int num;
        cin >> num;
        c[num]++;
    }
    sort(c.rbegin(),c.rend());
    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans += c[i];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// Ci 는 i번째 볼 색상
// 원하는 볼 색을 1부터 n 컬러 중 하나로 바꿀수있다
// 모든 볼 색을 같게 만들기 위한 최소 횟수

// https://atcoder.jp/contests/abc470/tasks/abc470_b