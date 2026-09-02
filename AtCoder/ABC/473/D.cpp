#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
vector<int> temp;

void dfs(int depth,int sum)
{
    if(depth==n)
    {
        if((k-sum)%n==0)
        {
            for(int i = 1; i <= n-1; i++)
            {
                cout << temp[i] << " ";
            }
            cout << (k - sum) / n;
            cout << "\n";
            return;
        }
        return;
    }

    for(int i = 0; sum+depth*i <= k; i++) {
        temp[depth]=i;
        dfs(depth + 1,sum+depth*i);
    }
}

void solve()
{
    cin >> n >> k;
    temp.assign(n+1, 0);
    dfs(1,0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// n자리의 숫자 배열을 만드는데, k==8 이라면
// 이 숫자 배열이 (0,1,2) => 0*1 + 1*2 + 2*3 = 0+2+6=8
// 위 조건을 만족하는 n자리 배열 모두 출력

// https://atcoder.jp/contests/abc473/tasks/abc473_d