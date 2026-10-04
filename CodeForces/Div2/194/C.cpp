#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll x, y;
    cin >> x >> y;

    ll s = x + y;
    if(x==0)
    {
        cout << y << " " << 0 << "\n";
        return;
    }

    ll x_prime = 0;
    for(int i = 30; i >= 0;i--)
    {
        if((s>>i)&1LL)
        {
            ll bit_val = (1LL << i);
            if(x_prime+bit_val<=x)
            {
                x_prime += bit_val;
            }
        }
    }
    cout << s << " " << (x - x_prime) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}
// 한번의 연산으로 x-- y++ 할수있다. x=0일때는 못함
// x xor y 값이 최대가 되도록 연산 수행(0번도 가능)
// x xor y의 가능한 최대값과 필요한 최소 연산 수


// 1
// 6 4
// 110
// 100
// => x가 010이 되어야하고
// => x-010만큼 y에 더한게 최대값

// 1010 => 10
// 0010

// 2 6 4
// 0 5 5
// 2 4 6
// 4 3 7
// 10 2 8
// 8 1 9
// 10 0 10

// 3 1 => 0 4
// 011 3 
// 001 1

// 100 => 4
// 000

// 1. 맨처음 주어진 두 값 xor해서 나온 값이 x, 나머지만큼 y++ 해준게 최대값

// 1. s를 2진수로 바꾸고 최상위비트부터 보면서 
//    x보다 작거나 같은 값 중 가장 큰 수 x'을 구하면 된다

// https://codeforces.com/contest/2260/problem/C