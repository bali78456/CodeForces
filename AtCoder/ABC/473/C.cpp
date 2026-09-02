#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,k;
    cin >> n >> k;

    vector<int> a(k+1,0);
    int maxNum = 0;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a[num]++;
    }
    for(int i = 1; i <= k;i++)
    {
        maxNum = max(maxNum, a[i]);
    }
    int cnt = 0;
    
    for(int i = 1; i <= k; i++) {
        if(a[i]==maxNum || a[i]==maxNum-1)
        {
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// k개 반 n명 학생
// i번째 학생은 ai 교실에 배정
// 전학시 k개의 반중 하나 선택가능

// 1: 0
// 2: 1
// 3: 3
// 4: 2
// 5: 2

// https://atcoder.jp/contests/abc473/tasks/abc473_c