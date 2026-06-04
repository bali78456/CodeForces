#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        long long a, b;
        cin >> a >> b;

        cout << min(min(a, b), (a + b) / 4)<<"\n";
    }
    return 0;
}

// a = num of programmer
// b = num of mathmaticians

// 각 팀은 정확히 4명으로 구성
// a 나 b 만 4명있는 팀은 안됨
// 최소 각 한명씩 들어가야함

// output = 만들 수 있는 팀 수 최대

// 1. 만들 수 있는 총 팀의 개수는 min(a,b)를 넘을 수 없다
// 2. 만들 수 있는 총 팀의 개수는 (a+b)/4를 넘을 수 없다

// ans = min(min(a,b),(a+b)/4)


// https://codeforces.com/contest/1611/problem/B