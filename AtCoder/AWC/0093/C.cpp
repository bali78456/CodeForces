#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int l, r, d;
    ll arr[n + 1];
    fill(arr, arr + n + 1, 0);
    for(int i = 1; i <= m; i++) {
        cin >> l >> r >> d;
        arr[l] += d;
        if(r + 1 <= n ) arr[r + 1] += -d;
    }

    for(int i = 1; i < n;i++)
    {
        arr[i + 1] += arr[i];
    }

    for(int i = 1; i <= n;i++)
    {
        cout << v[i]+arr[i] << " ";
    }
    
    return 0;
}

// L 부터 R 까지 모든 구역의 수분량을 D만큼 변화시킨다
// 해당 범위에 속한 각 구역의 수분량에 D를 더해라 (양수면 물 주고 음수면 물 빼고)

// output 작업이 완료된 후 각 구역의 최종 수분량 출력

// 1 3 2 
// 2 5 -1
// 4 4 5

// 10 5 8 3 6
// 2 2 2
//  -1-1-1-1
//       5
// 2 1 1 4 -1

// 10 5 8 3 6
// 2.     -2
//    -1      
//        5 -5  

// 2 -1 0 3 -5. 
// 2 1  1  4  -1
// 12 6 9 7 5

// https://atcoder.jp/contests/awc0093/tasks/awc0093_c