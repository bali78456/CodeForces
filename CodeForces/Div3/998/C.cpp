#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<long long> v(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v.begin() + 1, v.end());
        int score = 0;
        long long right = n;
        long long left = 1;
        if(k == 1) cout << 0 << "\n";
        else
        {
            while(left < right) {
                if(v[left]+v[right]==k)
                {
                    score++;
                    left++;
                    right--;
                }
                else if(v[left]+v[right]<k)
                {
                    left++;
                }
                else if(v[left]+v[right]>k)
                {
                    right--;
                }
            }
            cout << score << "\n";
        }
    }
    return 0;
}

// 게임은 n/2 턴동안 진행
// alice가 배열에서 숫자 하나 고르고 지울 수 있다 => a
// bob도 숫자 하나 골라서 지울 수 있다  => b
// if(a+b)=k라면 score++

// alice는 minimize
// bob은 maximize

// 4 4
// 1 2 3 2 => 2턴 진행, k=4
// 1 2 2 3 => sort
// 엘리스가 뭘골라도 밥이 하나 맞출수있음 
// 1 3 => 1턴
// 2 2 => 2턴 
// 총 스코어 2

// * k==1 이면 무조건 0

// 1. sort하고 left=0, right=n을 둠
// 2. while 돌면서
// 3. v[left]+v[right]== k 라면 score++;
// 4. else v[left] + v[right] < k 라면 left++
// 5. else v[left] + v[right] > k 라면 right++
// 6. left==right 까지

// https://codeforces.com/contest/2060/problem/C