#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a;
        cin >> b;

        if(a==b)
        {
            cout << "Yes\n";
        }
        else
        {
            if(n<=2)
            {
                cout << "No\n";
            }
            else
            {
                int oddA1 = 0;
                int oddB1 = 0;
                int evenA1 = 0;
                int evenB1 = 0;

                for(int i = 0; i < n;i+=2)
                {
                    if(a[i] == '1') evenA1++;
                    if(b[i] == '1') evenB1++;
                }

                for(int i = 1; i < n;i+=2)
                {
                    if(a[i] == '1') oddA1++;
                    if(b[i] == '1') oddB1++;
                }

                cout << (oddA1 == oddB1 && evenA1 == evenB1 ? "Yes\n" : "No\n");
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// a == b 만들수있으면 yes, 아니면 no
// 연산
// 1. a의 서브스트링 001 골라서 100 으로 만들수있다
//    100 => 001 도 가능
// 2. 110 => 011, 011 => 110

// 1. 처음부터 같으면 yes
// 2. 둘이 다른데 2자리 이하면 no
// 3. 가지고있는 1의 개수가 달라도 no

// 에디토리얼
// 1. 두 연산 다 가운데 값은 건드리지 않고 서로 인접하지 않은 ai, ai+2의 값을 스왑한다
// 2. 위치가 i인 문자는 i+2, i-2 와 바꿀수있다
//    인덱스 홀짝성 유지 (홀수인덱스는 홀수로만 짝수는 짝수로만 이동가능)
// 3. 따라서 홀수 인덱스만 모은 문자열과 짝수 인덱스만 모은 문자열 두 그룹으로 나누어 본다
// 4. 홀수나 짝수 그룹끼리는 순서를 마음대로 제배치가 가능하다
// 5. 홀수번째 1 개수와, b 홀수번째 1 개수가 같아야한다 (짝수도)
//    다 같다면 yes 다르다면 no

// https://codeforces.com/contest/2254/problem/C1