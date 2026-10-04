#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i = 1; i <= n;i++)
        cin >> a[i];

    vector<int> temp;
    temp.push_back(a[1]);
    temp.push_back(a[2]);
    temp.push_back(a[3]);
    sort(temp.rbegin(), temp.rend());
    cout << temp[2] << "\n";

    for(int k = 4; k <= n; k++) {
        temp.push_back(a[k]);
        sort(temp.rbegin(), temp.rend());
        temp.pop_back();
        cout << temp[2] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// k= 3 ... N 까지
// A1..Ak가 내림차순정렬해서 앞에서부터 3번째 값 출력

// 3 2 2 1 1
// 6 5 5 4 3 3 2 1 1 1  

// 11 9 1 3 17 19 10 19 17 3
// 11 9 1 
// 11 9 3
// 17 11 9
// 19 17 11 
// 19 17 11
// 19 19 17
// 19 19 17
// 19 19 17

// 19 19 17 17 11 10 9 3 3 1 

// https://atcoder.jp/contests/abc476/tasks/abc476_c