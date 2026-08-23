#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353

ll modpow(ll base,ll exp,ll Mod)
{
    // modpow를 범용 함수로 만들기 위한 세 줄
    base %= Mod;
    if(base < 0) base += Mod; 
    ll res = 1 % Mod;

    while(exp>0)
    {
        // exp를 이진수로 봤을 때 1인 자리(비트)에 해당하는 base값들만 곱해서 최종 결과 만든다
        if(exp&1)   res=res*base%Mod;
        base = base * base % Mod; // exp=13은 이진수로 1101(2)=8+4+1
        exp >>= 1;
    }
    return res;
}
void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;
        unsigned ll exp = n * m - (n - r + 1) * (m - c + 1);

        cout << modpow(2, exp, MOD) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// row는 1 to n
// col은 1 to m
// i-th row, j-th col = ai,j
// output = clean 매트릭스 갯수 출력

// 1. 모든 r*c 부분행렬의 xor합이 0이어야한다
// 2. 

// r=1,c=2
// ai,j xor ai,j+1=0
// 2개의 행 => 2^2=4

// r=2, c=2
// ai,j x ai,j+1 x ai+1,j x ai+1,j+1
// n=2 

// r=c=2 , n=r or m=c

// https://codeforces.com/contest/2240/problem/B

// 코드는 맞는데 이해를 못함