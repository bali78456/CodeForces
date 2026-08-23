#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 200000
bool is_prime[MAX_N + 1];

void prime()
{
    fill(is_prime, is_prime + MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= MAX_N;++i)
    {
        if(is_prime[i]){
            for(int j = i * i; j <= MAX_N;j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
}

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==2||n==4)
        {
            cout << "Yes\n";
        }
        else
        {
            if(is_prime[n+1]) cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prime();
    solve();

    return 0;
}

//  n개의 카드 2,3,4,...,n+1 
// x, y가 서로 나누어떨어지면 더 작은 카드가 이김
// 나머지는 더 큰 카드가 이김

// n이 주어질 때 한 카드가 나머지 모든 카드를 이기는가

// n이 소수인것

// https://codeforces.com/contest/2253/problem/A