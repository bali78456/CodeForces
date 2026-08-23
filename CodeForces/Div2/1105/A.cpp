#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        if(n<=k)
        {
            cout << n << "\n";
        }
        else
        {
            int m = 1;
            while(k*((pow(2,m)-1))<=n)
            {
                m++;
            }
            m--;
            int r = n - k * (pow(2, m) - 1);
            int u = r / pow(2, m);
            cout << k * m + u << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// i=1 to k 까지에서 숫자를 고르는데 이게 <= n 이어야 함
// popcount는 어떤 숫자 ai를 2진수로 바꿨을 때 1의 갯수임
// 이 popcount의 max를 구해라

// 즉 k==1 이라면 popcount는 n을 2진수로 바꿨을 때 1의 갯수가 됨
// n==k라면 popcount도 n

// 3 = 11
// 7 = 111
// 15 = 1111
// 31 = 11111
//.     11111111 = 1 2 4 8 16 32 64 128

// 1. k개의 숫자를 모두 2^m-1 꼴로 맞춰야한다 (m을 가능한 크게)
//    k*(2^m - 1) <= n
// 2. 남는 예산 처리
//    R = n - k*(2^m - 1)
//    u = R // (2^m)
// 3. ans = k * m + u


// https://codeforces.com/contest/2240/problem/A