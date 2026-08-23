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
        vector<int> v(n);
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(v[i]==1)
            {
                a[i] = 1;
                b[i] = 1;
            } else if(v[i] == 2) {
                a[i] = -1;
                b[i] = 1;
            }
            else
            {
                a[i] = -1;
                b[i] = -1;
            }
        }
        vector<int> p1(n);
        vector<int> p2(n);
        p1[0] = a[0];
        p2[0] = b[0];
        for(int i = 1; i < n; i++) {
            p1[i] = p1[i - 1] + a[i];
            p2[i] = p2[i - 1] + b[i];
        }

        bool flag=false;
        bool cond1 = false;
        bool cond2 = false;


        for(int i=0; i < n - 2; i++) {
            cond1 = (p1[i] >= 0);
            if(cond1) break;
        }
        
        int Min = 1e9;
        for(int i = 1; i < n - 1; i++) {
            int x = i - 1;
            if(p1[x]>=0)
            {
                Min = min(Min, p2[x]);
            }
            
            if(Min<=p2[i])
            {
                cond2 = true;
                break;
            }
        }

        if(cond1 && cond2) flag = true;

        if(flag)
            cout << "Yes\n";
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
// 1,2,3으로만 이루어진 배열을 3개로 나눌 수 있냐
// 연속으로 왼쪽, 중간, 오른쪽 으로

// 조건
// 각 i번째 부분에서 i보다 큰 원소의 개수가 해당 부분 전체 크기의 절반 이하여야 한다
// 왼쪽 부분(i=1): 1보다 큰 원소 (2,3) 의 총 개수가 해당 부분의 절반 이하여야한다
//  즉 1의 개수가 2와 3의 개수를 합한 것보다 크거나 같아야 한다
// 중간 부분(i=2): 2보다 큰 원소(3)의 개수가 해당 부분의 절반 이하여야 한다
//  즉 1과 2의 개수를 합한게 3의 개수보다 크거나 같아야 하낟
// 오른쪽 부분(i=3): 3보다 큰 원소는 배열에 없으므로 어떤 원소가 와도 상관없다
//  하지만 비어있지 않은 상태여야한다 (최소 원소 1개이상)

// https://codeforces.com/contest/2242/problem/B