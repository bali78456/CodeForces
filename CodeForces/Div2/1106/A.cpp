#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n;i++)
            cin >> a[i];
        for(int i = 0; i < n;i++)
            cin >> b[i];

        int noSortAns = 0;
        int greaterCnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] >= b[i]) greaterCnt++;
        }

        if(greaterCnt==n)
        {
            for(int i = 0; i < n;i++)
            {
                noSortAns += (a[i] - b[i]);
            }
        }
        else
            noSortAns = 1e9;

        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        bool ans = true;
        int sortAns = c;
        for(int i = 0; i < n; i++) {
            if(a[i] < b[i]) ans = false;
            sortAns += a[i] - b[i];
        }

        if(ans)
        {
            cout << min(noSortAns, sortAns) << "\n";
        }
        else
            cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
//  정렬한다면 c만큼 시간이 걸림
// ai를 ai-1로 바꿀 수 있음 여기에는 1초 소요

// 1. a의 모든 원소가 b보다 작으면 -1
// 2. 기존 주어진 배열에서 걸리는 시간 세고
// 3. a,b 둘 다 정렬한 뒤 걸리는 시간 중 더 작은거 출력

// https://codeforces.com/contest/2238/problem/A