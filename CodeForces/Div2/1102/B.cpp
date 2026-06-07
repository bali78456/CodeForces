#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        uint64_t n;
        cin >> n;

        if(n==10)
        {
            cout << -1 << "\n";
        }
        else if(1<=n && n<=9)
        {
            cout << n << " " << 0 << "\n";
        } else {
            uint64_t a =(n % 12);
            uint64_t b = (n - (n % 12));


            uint64_t left = a;
            string as = to_string(left);
            string reverseA = as;
            reverse(reverseA.begin(), reverseA.end());

            if(a-12==0)
            {
                cout << a << " " << b << "\n";
            }
            else
            {
                while(true)
                {
                    if(as==reverseA)
                    {
                        cout << a << " " << b << "\n";
                        break;
                    } else {
                        a += 12;
                        b -= 12;
                        left = a;
                        as = to_string(left);
                        reverseA = as;
                        reverse(reverseA.begin(), reverseA.end());
                    }
                }
            }
        }
    }

    return 0;
}

// n을 두 숫자로 나눠야하는데
// a = 펠린드롬이어야하고
// b % 12 = 0 이어야 한다
// 만약 그런 두 수가 존재하지 않는다면 -1 출력

// 111111111111111 
// 6111111111111111
// 12로 나눠지려면 12의 배수 즉 12이상 짝수거나 0이거나