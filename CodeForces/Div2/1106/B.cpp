#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a,ll b)
{
    return (a * b) / gcd(a, b);
}

void solve() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> v;
        for(int i = 1; i <= n;i++)
            v.push_back(i);
        
    }
}
// a=b=c 라면 무조건 가능함
// 그리고 n-1 일 때의 경우의 수는 모두 다 가능(n일때도 n-1일때의 조합을 만들수있으니까)
// a=b, c=a+2일때도 가능


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1 1 1 *
// 2 2 2 *
// 3 3 3 *

// 1 1 2 *
// 1 1 3 *

// 1 2 1 x
// 1 3 1 x

// 2 1 1 *
// 3 1 1 *

// 1 2 2 x
// 1 3 3 x

// 2 2 1 x
// 3 3 1 x

// 2 1 2 *
// 3 1 3 *

// 1 2 3 x
// 1 3 2 x
// 3 1 2 *
// 3 2 1 x


// n = 2
// 1 1 1  *
// 2 2 2  *

// 1 1 2  *
// 1 2 1
// 2 1 1  *

// 1 2 2
// 2 2 1
// 2 1 2  *


// 1부터 n까지 번호가 있음
// gcd(lcm(a,b),lcm(b,c))=gcd(a,c)를 만족하는 경우의 수 출력
// n=1 => 1
// n=2 => 2
// n=3 => 10

// n=20 => 612



// 못품