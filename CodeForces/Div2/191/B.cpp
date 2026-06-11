#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> ans;

        if(n%2==0)
        {
            int base2[] = {1, 2, 2, 1, 2, 1, 1, 2};
            for(int x:base2)
                ans.push_back(x);
            for(int i = 4; i <= n;i+=2)
            {
                int prev = i - 1;
                int curr = i;
                int pattern[] = {prev, curr, curr, prev, curr, prev, prev, curr};
                for(int x:pattern)
                    ans.push_back(x);
            }
        }
        else
        {
            int base3[] = {1,1,2,1,2,3,1,3,2,2,3,3};
            for(int x:base3)
                ans.push_back(x);
            for(int i = 5; i <= n;i+=2)
            {
                int prev = i - 1;
                int curr = i;
                int pattern[] = {prev, curr, curr, prev, curr, prev, prev, curr};
                for(int x:pattern)
                    ans.push_back(x);
            }
        }

        for(int x:ans)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}

// 4 * n 개 정수
// 1 to n 까지 정확히 4번씩 등장해야함
// pxi = 수 x의 배열에서 i번째(i는 숫자 x가 i번째 등장하는 자리) (인덱스번호)
// 이 때 모든 x에 대하여 세 값 (px2 - px1), (px3 - px2), (px4 - px3) 은 모두 달라야한다
// 즉 같은 숫자 x의 이웃한 등장 위치 간의 거리 3개가 모두 달라야 한다

// n = 2
// 1 2 2 1 2 1 1 2
// n-1,n,n,n-1,n,n-1,n-1,n

// n = 3
// 1 1 2 1 2 3 1 3 2 2 3 3 
// n-1,n,n,n-1,n,n-1,n-1,n

// https://codeforces.com/contest/2233/problem/B