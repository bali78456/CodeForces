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
        vector<ll> a(n);
        for(int i = 0; i < n;i++)
            cin >> a[i];
        cout << gcd(a[0], a[n - 1]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 정수 k하나 선택하고 현재 배열의 길이 m에 대해 2k+1개의 인덱스 선택
// 그 후 배열에서 i_k+1번째 원소 제거

// 1. 항상 홀수개의 인덱스를 뽑아서 그 중 가운데 인덱스 위치한 원소 제거

// n=7
// 2 4(x) 6 7(x) 8 9 10
// 1 => 3.  1 (2) 3
// n=6
// 2 => 5  1 2 (3) 4 5
// n=5

// https://codeforces.com/contest/2258/problem/A