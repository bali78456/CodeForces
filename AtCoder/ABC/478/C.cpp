#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &p:a)
        cin >> p;
    vector<int> temp(a);
    sort(temp.begin(), temp.end());
    int l = 0;
    int r = 0;
    for(int i = 0; i < n; i++) {
        if(temp[i] != a[i])
        {
            l = i;
            break;
        }
    }
    for(int i = n-1; i>=0; i--) {
        if(temp[i] != a[i])
        {
            r = i;
            break;
        }
    }
    int res = r - l + 1;
    if(res==k)
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
// op 단 한번만 실행가능
// 1 and n-k+1 사이의 숫자 골라서 
// a_i ... a_i+k-1 까지 배열을 오름차순 정렬
// 연산 한번으로 오름차순 되면 yes 안되면 no

// n=3, k=1
// 1 3

// 1. 주어진배열이 오름차순이 아니고 k>=n/2라면?
// 2. 만약 정렬되어서 주어지면 항상가능

// n = 30, k = 15
// 1 and 16
// 1 15

// 1. 정렬되어있지 않은 구간 길이 센다음
//    그 구간 길이가 k랑 같아야됨

// https://atcoder.jp/contests/abc478/tasks/abc478_c