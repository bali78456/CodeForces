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
        vector<int> a(n+1);
        vector<int> idx;
        int cnt1 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] == 1)
            {
                cnt1++;
                idx.push_back(i);
            }
        }

        if(cnt1==0)
        {
            for(int i = 0; i < n;i++)
            {
                if(a[i]==-1) 
                {
                    a[i] = 1;
                    break;
                }
            }
            for(int i = n - 1; i >= 0;i--)
            {
                if(a[i]==-1)
                {
                    a[i] = 1;
                    break;
                }
            }

            for(int i = 0; i < n;i++)
            {
                if(a[i]!=1)
                {
                    a[i] = 0;
                }
            }

            for(int i = 0; i < n;i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            int temp = 0;
            int Max = 0;
            int l=n;
            int r = n;
            int left = 0;
            int right = 0;

            for(auto i : idx) {
                for(int j = temp; j <= i; j++) {
                    if(a[j]==-1 || a[j]==1)
                    {
                        left = j;
                        break;
                    }
                }

                for(int j = i; j >=temp; j--) {
                    if(a[j]==1 || a[j]==-1)
                    {
                        right = j;
                        break;
                    }
                }


                temp = i;
                if(Max<right-left)
                {
                    Max = right - left;
                    l = left;
                    r = right;
                }
            }

            for(int i = idx.back(); i < n; i++) {
                if(a[i]==-1 || a[i]==1)
                {
                    left = i;
                    break;
                }
            }
            for(int i = n-1; i >=idx.back(); i--) {
                if(a[i]==-1 || a[i]==1)
                {
                    right = i;
                    break;
                }
            }
            if(Max<right-left)
            {
                Max = right - left;
                l = left;
                r = right;
            }

            a[l] = 1;
            a[r] = 1;
            for(int i = l+1; i < r; i++) {
                a[i] = 0;
            }
            for(int i = 0; i < n;i++)
            {
                if(a[i]!=1)
                {
                    a[i] = 0;
                }
            }

            for(int i = 0; i < n;i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 길이가 m인 배열 b의 점수는 부분 배열의 첫번째와 마지막 원소가 1이고 부분 배열의 나머지
// 모든 원소가 0인 부분 배열의 최대 길이로 정의된다
// 배열 a의 점수가 최대가 되도록 -1을 0이나 1로 바꿔라


// 1, -1 개수 세고

// 1은 절대 바꾸지 못함
// 맨 앞에서부터 1끼리의 거리만 확인해서 사이에 0이나 -1은 있어도 상관없으니까
// 각 구간별 최대값 비교해서 가장 큰 부분의 사이와 나머지를 다 0으로 1은 놔두고
// 만약 1이 하나도 없으면 첫번째 -1, 마지막 -1만 1로 바꾸고 나머지 다 0으로

// https://codeforces.com/contest/2259/problem/C