#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;

        if(n%2!=0)
        {
            for(int i = 0; i < n;i++)
            {
                cout << 1 << " ";
            }
            cout << "\n";
        }
        else if(n%2==0)
        {
            int x = 2, d = 1;
            cout << x - d << " " << x + d << " ";
            long long res = (n * 2) - 4;
            if(res!=0)
                res /= (n - 2);
            for(int i = 0; i < n - 2;i++)
            {
                cout << res << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

// n개의 정수 출력
// a1 xor a2 xor ... xor an == a1+a2+..+an/2 

// xor = ^ 연산 (같으면 0 다르면 1)

// 1. a 배열을 다 더했을 때 n의 배수가 되어야 한다
// 2. 같은 수를 홀수번 연산하면 그 수가 됨

// 3. if n이 홀수라면
// 4. 전부 1로만 출력하면 됨
// 5. n이 짝수라면

// n = 2
// x-d, x+d 두 수의 평균이 x가 되도록
// (x-d)^(x+d)=x 도 만족하도록
// x=2,d=1 라면
// 평균 = 2
// 2-1 ^ 2+1 = 2

// n=4 라면
// x-d x+d x-d x+d / n = x
// x=4 로 두고 => d는 n-2한 값으로 채운다 그렇게 앞 두개를 완성하면 나머지는 다 1로 채워라
// 앞 두개만 저걸로 채운다음 나머지는 다 1로 채운다면(^1 짝수개는 무조건 0이 되니까)

// n = 6
// x=2, d=1;
// 2-1 2+1 
// 1 3 2 2 2 2
// 다 더해서 12가 돼야한다 8 ->4자리 남음

// x=2, d=1 고정이고
// 첫 두자리만 2-1 2+1이다
// 나머지 자리수는 n*2 - 4 = res
// res/n-2 값으로 다 채워라

// https://codeforces.com/contest/1758/problem/B