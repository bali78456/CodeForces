#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<ll> v;
        v.push_back(2);
        v.push_back(4);
        v.push_back(6);
        ll temp = 12;
        if(n == 1) {
            cout << 1 << "\n";
        } else if(n == 2) {
            cout << "-1\n";
        } else {
            if(n==3) 
            {
                for(auto &a:v)
                    cout << a << " ";
                cout << "\n";
            }
            else
            {
                for(int i = 4; i <= n; i++) {
                    v.push_back(temp);
                    temp *= 2;
                }

                for(auto &a:v)
                    cout << a << " ";
                cout << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 배열 a1부터 an까지 모두 합한 값이 각 ai와 모두 나누어떨어져야한다
// 이런 배열을 못만들면 -1
// 만들수있으면 그 배열 출력

// 1. 안되는 경우
// n=2
// 2. 배열 원소들이 배열 총합의 약수로 이루어져야됨
// 2 4 6 12 => 24
// 2 4 6 12 24 => 48

// https://codeforces.com/contest/2246/problem/B