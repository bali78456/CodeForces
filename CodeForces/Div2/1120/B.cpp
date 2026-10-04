#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    if(n > k) 
    {
        cout << "-1\n";
        return;
    }

    if(k==2*n)
    {
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> v(n, vector<int>(n,0));
    int num = 1;
    int cnt = 2 * n - k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n;j++)
        {
            if(i==j && cnt>0)
            {
                v[i][j] = num;
                num++;
                cnt--;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(v[0][i] == 0) 
        {
            v[0][i] = num;
            num++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(v[i][0] == 0) 
        {
            v[i][0] = num;
            num++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n;j++)
        {
            if(v[i][j]==0)
            {
                v[i][j] = num;
                num++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}
// 1. n>k는 안됨
// 2. k=2n 도 안됨
// 3. n==k면 행과 열에 1 2 3 이런식으로 안겹치게 두면 됨 대각선으로
// 4. k=2n-1이면 1 2 3 4 5 6 순서대로 넣으면 됨
// 5. 나머지는 공유되는 최솟값이 2n-k개니까 
//    그 최솟값만큼 대각선 배치하고 나머지 숫자를 순서대로 ?

// 1행 먼저 순서대로 채우고
// 1열 순서대로 채우고 나머지 빈칸 순서대로 ? 

// https://codeforces.com/contest/2263/problem/B