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
        vector<int> v(n+1);
        for(int i = 1; i <= n;i++)
            cin >> v[i];
        vector<int> even;
        vector<int> odd;
        for(int i = 1; i <= n;i++)
        {
            if(i%2!=0)
            {
                odd.push_back(v[i]);
            }
            else
                even.push_back(v[i]);
        }
        auto eIt = max_element(even.begin(), even.end());
        auto oIt = min_element(odd.begin(), odd.end());
        bool flag = true;
        if(n==1 || n%2!=0)
        {
            flag = false;
        }
        else
        {
            if((*oIt)-(*eIt)>=2)
            {
                flag = true;
            }
            else
                flag = false;
        }

        if(flag) cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1. n==1, 홀수라면 항상 no
// 2. 1번인덱스 오른쪽, 2번인덱스 왼쪽 이런식으로 이동해야됨
// 3. 홀수번은 오른쪽, 짝수번은 왼쪽
// 4. ki보다 작아야 오른쪽으로 가니까 홀수번째 숫자들 최소값
// 5. 짝수번째 숫자들 최대값 이 사이에 들어갈 k가 있으면 Yes

// https://codeforces.com/contest/2250/problem/A