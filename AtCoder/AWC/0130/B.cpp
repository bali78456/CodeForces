#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    for(int i = 0; i < n;i++)
    {
        cin >> p[i];
    }
    for(int i = 0; i < n;i++)
    {
        cin >> q[i];
    }

    int l = 0, r = 0;
    for(int i = 0; i < n;i++)
    {
        if(p[i]!=q[i])
        {
            l = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0;i--)
    {
        if(p[i]!=q[i])
        {
            r = i;
            break;
        }
    }

    reverse(p.begin() + l, p.begin() + r+1);
    if(p==q)
    {
        cout << "Yes";
    }
    else
        cout << "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 한번만 특정구간 뒤집어서 p를 q와 같게 만들수 있는지 판별

// 1. 처음부터 같다면 yes
// 2. 달라지는 구간 처음과 끝을 구하고 이 구간을 뒤집었을 때 같은지 판별

// https://atcoder.jp/contests/awc0130/tasks/awc0130_b