#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);

    for(int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m;i++)
    {
        cin >> b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(), b.end());

    bool ans = (n >= 2 * m);
    if(ans)
    {
        for(int i = 0; i < m;i++)
        {
            if(!(a[i]<=b[i]&&b[i]<=a[n-m+i]))
            {
                ans = false;
                break;
            }
        }
    }
    cout << (ans ? "Yes" : "No") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// a배열 연산
// 1. 두 원소 고른다(x<y)
// 2. 그 두 원소 삭제
// 3. 정수 z하나를 a에 넣는다 (x<z<y)

// a배열은 아무 순서로 바꿀수있음
// a를 b와 똑같이 만들 수 있는지 yes, no 출력

// editorial (두 조건을 모두 만족하면 yes, 아니면 no)
// 1. n >= 2m 
// 2. ai <= bi <= a{n-m+i}


// https://codeforces.com/contest/2248/problem/B