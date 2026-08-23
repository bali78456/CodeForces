#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        
        if(n-1==k)
        {
            cout << "-1\n";
        }
        else
        {
            int r = n - k;
            // 전체 문자열에서 필요햔 0,1 총 개수
            int c0 = (n + 1) / 2;
            int c1 = n / 2;
            // 0,1 블록의 개수
            int r0 = (r + 1) / 2;
            int r1 = r / 2;

            // string(3,'a') => "aaa" 생성
            // 즉 기본 블럭 (1) + 아직 배정하지 못하고 남은 0의 개수(c0-r0)
            // 만큼 0 또는 1을 반복해서 생성해라
            string result;
            result += string(1 + (c0 - r0), '0');
            result += string(1 + (c1 - r1), '1');

            // 남은 블록에 0,1 번갈아가며 생성
            for(int i = 2; i < r;i++)
            {
                result += (i % 2 == 0) ? '0' : '1';
            }
            cout << result << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 길이 n인 문자열 s 생성하라
// 1. 0의 개수와 1의 개수의 절댓값 차이는 최대 1이어야 한다
// 2. 인접한 두 문자가 서로 같은 쌍의 개수가 정확히 k개

// 1. n-1==k 이라면 no
// 2. k개의 문자가 붙어있으면 k-1개의 쌍이 생김
// 3. n-k개 만큼의 부분배열 생김
//      각 부분배열에 0,1 하나씩 넣어놓고 여기에 0,1 채워넣는방식
// 4. r=n-k
//      0으로 시작하는 블록 개수 r0 = ceil(r/2)
//      1로 시작하는 블록 개수 r1 = floor(r/2)
// 5. 전체 문자열에서 0과 1의 개수는
//      c0 = ceil(n/2)
//      c1 = floor(n/2)

// https://codeforces.com/contest/2250/problem/B