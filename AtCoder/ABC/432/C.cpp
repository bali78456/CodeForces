#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n + 1);
    for(int i = 1; i <= n;i++)
        cin >> v[i];

    sort(v.begin() + 1, v.end());

    ll a1 = v[1];
    ll totalNum = a1;
    for(int i = 2; i <= n;i++)
    {
        // editorial 공식 dk = ( ak - a1 ) * x / ( y - x )
        ll num = (v[i] - v[1]) * x;
        ll d = y - x;
        if(num%d!=0){
            cout << -1;
            return 0;
        }

        ll di = num / d;
        if(di>a1){
            cout << -1;
            return 0;
        }

        ll ai = a1 - di;
        totalNum += ai;
    }
    cout << totalNum;

    return 0;
}

// small candy weight X
// large candy is Y
// N children (1 to N )

// 1. i번쨰 친구는 정확히 Ai개 사탕을 받아야 한다. 두 타입의 캔디 합쳐서
// 2. 나눠진 캔디의 무개는 모두 같아야 한다
// output = max num of large candy

// https://atcoder.jp/contests/abc432/tasks/abc432_c