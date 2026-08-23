#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> w(n);
    for(int i = 0; i < n;i++)
    {
        char c;
        cin >> c;
        if(c=='S')
        {
            w[i] = 1;
        }
        else
            w[i] = 0;
    }

    vector<int> prefix(n);
    prefix[0] = w[0];
    for(int i = 1; i < n; i++) {
        if(w[i]==1)
        {
            prefix[i] = 1+prefix[i-1];
        }
        else
            prefix[i] = prefix[i - 1];
    }

    int ans = prefix[k - 1];
    for(int i = 1; i <= n - k; i++) {
        ans = max(ans, prefix[i + k - 1] - prefix[i - 1]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// s = sunny
// c = cloudy
// r = rainy

// s 일때만 수확가능
// k일동안 알바 고용가능
// d (1 <= d <= n-k+1) 하나를 골라야된다 
// d 부터 d+k-1 까지 일할 

// k일에 속하는 s 개수 출력

// 1. k구간씩 확인하면서 s가 가장 클때 출력
// tle

// 1. s만 1로 보고 나머지는 0으로 만들어서
//    prefix
// 2. d번째 날부터 d+k-1 까지 s 개수는 prefix[d+k-1] - prefix[d-1]

// 1 1 2 3 3 4 4
// 1 0 1 1 0 1 0
// 

// https://atcoder.jp/contests/awc0128/tasks/awc0128_b