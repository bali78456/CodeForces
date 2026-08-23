#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n + 1);
        int minusCnt = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> v[i];
            if(v[i] == -1) minusCnt++;
        }

        if(minusCnt==0)
        {
            cout << 1 << "\n";
        }
        else
        {

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 감소하지 않는 배열 입력받음 n개 원소
// 각 원소는 -1이거나 양수임
// 

// output
// 수열 a의 교대합이 0이되는 경우의 수 출력 % MOD

// 교대합은 a1-a2+a3-b4... 부호 번갈아가면서 더하는 합
// 원소의 값이 같아도 인덱스가 다르면 다른 부분수열
// 길이가 0인 빈 부분수열도 센다

// -1 을 잘 활용해야할듯
// DP?
// 1. -1이 하나도 없다면 무조건 1
// 2. -1, -1 => 0 => -1이 짝수개 있으면 항상 0임
//    -1, n, 1+n => 0 => -1 - b1 + b2 - b3 + b4 = 0
//    -1 - b1 + b2 + b4 = b3 (뒤에서 하나 앞에있는 숫자가 돼야한다 나머지 숫자들 계산한게)
//    -1 3개면 -1 하나 남는다 그럼 똑같이 뒤에는 -1, n, 1+n => 0 
// 3. -1이 여러개면 -1 하나만 들어가는 경우의 수가 모두 가능한거니까
//    -1 하나로 만들 수 있는 경우의 수 * -1의 개수 해줘야됨
// 

// https://codeforces.com/contest/2246/problem/C