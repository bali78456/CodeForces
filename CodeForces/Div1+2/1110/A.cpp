#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k,n;
        cin >> n >> k;
        string s;
        cin >> s;

        if(k>n/2)
        {
            cout << -1 << "\n";
        } else {
            int ans = 0;
            int cnt = 0;
            if(s[0] == 'L') {
                s[0] = 'R';
                ans++;
            }

            if(s[n-1]=='R')
            {
                s[n - 1] = 'L';
                ans++;
            }

            bool t = true;
            for(int i = 0; i < n; i++) {
                cnt = 0;
                if(s[i] == 'L') {
                    for(int j = 0; j < i;j++)
                    {
                        if(s[j] == 'R') cnt++;
                        if(cnt >= k) break;
                    }
                    if(cnt < k)
                    {
                        t = false;
                        break;
                    }
                }
                else
                {
                    for(int j = i - 1; j >= 0;j--)
                    {
                        if(s[j] == 'L') cnt++;
                        if(cnt >= k) break;
                    }
                    if(cnt<k)
                    {
                        t = false;
                        break;
                    }
                }
            }

            if(t)
            {
                cout << ans << "\n";
            }
            else
            {
                for(int i = n - 1; i >= 0; i--) {
                    if(s[i] == 'L')
                        cnt++;
                    else if(s[i] == 'R') {
                        s[i] = 'L';
                        cnt++;
                        ans++;
                    }

                    if(cnt == k) break;
                }
            
                for(int i = 0; i < n; i++) {
                    cnt = 0;
                    if(s[i] == 'L') {
                        for(int j = 0; j < i;j++)
                        {
                            if(s[j] == 'R') cnt++;
                            if(cnt >= k) break;
                        }
                        if(cnt<k)
                        {
                            s[i] = 'R';
                            ans++;
                        }
                    }
                }
                cout << ans << "\n";
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

// k개 속해야 안전하다
// x<y 라면 x는 right, y는 left
// 모든 돼지 안전하게 하기위해 방향바꿔야되는 최소 돼지 수 출력
// 불가능하면 -1

// RLLRRL
// RRLRLL

// LRLLRRLRLRLR
// RRRRRRLRLLLL

// 5 3
// RRRRR
// RRRRL
// RRRLL

// 6 2
// R = 3, L = 3
// RLLRRL
// RRLRLL
// R=3, L=3

// 12 4
// LRLLRRLRLRLR
// RRRRRRLRLLLL

// 6 2
// RLLRRL
// RRLRLL

// 4 1
// RRRRL

// 8 3
// RRLLRLRL
// RRRLRLLL

// 3 2
// RLL

// n/2 < k 면 안된다?

// 1. k=n-1 이면 -1
// 2. 1번돼지가 L면 무조건 R로 바꿔야됨
// 3. 마지막 돼지가 R이면 L로 바꿔야됨
// 4. 오른쪽 끝에서 L로 채우고 k개만큼 
// 5. 왼쪽부터 R부족한만큼만 R로채우면


// https://codeforces.com/contest/2245/problem/A