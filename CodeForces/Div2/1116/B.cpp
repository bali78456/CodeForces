#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = 0;
        // 홀수번째 값이 0 1 0 1 or 1 0 1 0 
        // 짝수번째 값이 0 1 0 1 or 1 0 1 0 
        // 총 경우의 수는 최대 4개
        for(int even = 0; even < 2; even++) {
            for(int odd = 0; odd < 2;odd++)
            {
                int cur=even;
                bool ans = true;
                // 홀수번째 문자열이 0 1 0 1 처럼 반대로 나오는지 확인
                for(int i = 0; i < n; i += 2) {
                    if(s[i]!='?' && s[i]-'0'!=cur)
                    {
                        ans = false;
                        break;
                    }
                    // cur이 1이었다면 0으로 0이었다면 1로 바꿔줌
                    cur = 1 - cur;
                }

                cur=odd;
                // 짝수번째 문자열이 서로 반대로 나오는지 확인
                for(int i = 1; i < n;i+=2)
                {
                    if(s[i]!='?' && s[i]-'0'!=cur)
                    {
                        ans = false;
                        break;
                    }
                    cur = 1 - cur;
                }
                if(ans) cnt++;
            }
        }
        cout << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 인접한 두 문자열의 가중치가 같으면 안된다
// 0 0 1 1 0 이라면 가중치는
//  0 1 2 1  4개가 나옴, 인접한 두 가중치가 모두 다르니까 유효한 문자열

// 1. dp ?인 자리마다 0또는 1을 선택했을 때 나올수있는 경우의 수 저장?

// 1. 연속된 두 도미노의 가중치가 달라야 하니까
//    si + si+1 != si+1 + si+2 이어야 한다
//    즉 가운데 si+1은 무시하고 si != si+2 
// 3. 어떤 문자열이 주어지고 사이에 있는 ? 앞뒤로 똑같은 문자가 들어있다면 그 문자열은 
//    항상 0
// 5. 이전 타일의 값이 1이고 지금까지 1이 1번 반복됐으면 1이 한번 더 나갈수있음
//    이전 타일의 값이 1이고 지금까지 1이 2번 반복됐으면 0이 나가야됨
//    이전 타일의 값이 0이고 지금까지 0이 1번 반복됐으면 0 한번 더 가능
//    이전 타일의 값이 0이고 지금까지 0이 2번 반복됐으면 1 나가야됨

// 0 ? 1 ? ?
// 1. 주어진 0과 1이 서로 다르니까 사이 ?에는 0,1 둘 다 가능
// 2. 0 0 1 로 들어왔다면 다음 ?는 1이 돼야함
//    0 0 1 1 그럼 마지막 물음표는 0이 돼야함
//    0 0 1 1 0
// 3. 0 1 1 로 들어왔다면 다음 ?는 0
//    0 1 1 0 마지막 물음표는 0
//    0 1 1 0 0

// https://codeforces.com/contest/2256/problem/B