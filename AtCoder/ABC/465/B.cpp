#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;
    int ans = 0;
    if(a>=r)
    {
        ans += ((b - a) * y);
    }
    else if(b<=l)
    {
        ans += ((b - a) * y);
    } else if(a >= l && b <= r) {
        ans += ((b - a) * x);
    } else {
        if(a>=l && b>=r)
        {
            ans += ((r - a) * x) + ((b - r) * y);
        }
        else if(a<=l && b>=r)
        {
            ans += ((l - a) * y) + ((r - l) * x) + ((b - r) * y);
        }
        else if(a>=l&&b<=r)
        {
            ans += ((b - a) * x);
        }
        else if(a<=l &&b<=r)
        {
            ans += ((l - a) * y) + ((b - l) * x);
        }
    }

    cout << ans;
}

void editorial()
{
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;
    int ans = 0;
    for(int h = a; h < b; h++) {
        if(l<=h&&h<r)
        {
            ans += x;
        }
        else ans += y;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve();
    editorial();

    return 0;
}

// 1. a,b 구간이 l,r에 포함되지 않는다면 ans+=(b-a)*y
// 2. a,b구간이 l,r에 포함된다면 ans+=(b-a)*x
// 3. a,b구간이 일부만 l,r에 포함된다면
//.   a는 l보다 크고 b도 r보다 클 때 => (r-a)*x + (b-r)*y
//    a는 l보다 작고 b는 r보다 클 때 => (l-a)*y + (r-l)*x + (b-r)*y
//    a는 l보다 크고 b는 r보다 작을 때 => (b-a)*x
//    a는 l보다 작고 b는 r보다 작을 때 => (l-a)*y + (b-l)*x
// 4. b가 l보다 작다면 => (b-a)*y
// 9 17 17 20
// 

// l부터 r 시각까지
// 각 시간당 주차비 = x
// a b 시간에 포함되지 않으면 각 시간당 주차비 = y

// a부터 b 시간까지 주차함

// https://atcoder.jp/contests/abc465/tasks/abc465_b