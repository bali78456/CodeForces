#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        string originalStrig[n+n-1];
        string ans = "";
        vector<int> alphabet(123);

        for(int i = 0; i < n + n - 1; i++) {
            cin >> originalStrig[i];
        }

        for(int i = 0; i < m;i++)
        {
            fill(alphabet.begin(), alphabet.end(), 0);
            for(int j = 0; j < n + n - 1; j++) {
                alphabet[originalStrig[j][i]]++;
            }
            for(int j = 0; j < 123;j++)
            {
                if(j!=0 && alphabet[j]%2!=0)
                {
                    ans += j;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

// 각 열에서 홀수번 등장하는 문자출력

// https://codeforces.com/contest/1546/problem/B