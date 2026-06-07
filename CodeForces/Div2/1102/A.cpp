#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n + 1);
        for(int i = 1; i <= n;i++)
            cin >> v[i];
        sort(v.begin() + 1, v.end(), greater<long long>());

        if(n==2)
        {
            cout << v[1] << " " << v[2] << "\n";
        }
        else
        {
            bool ans = false;
            long long num1, num2;
            num1 = v[1];
            num2 = v[2];
            for(int i = 1; i <= n - 2; i++) {
                if(v[i]%v[i+1]==v[i+2])
                {
                    ans = true;
                } else if(v[i] % v[i + 1] != v[i + 2]) {
                    ans = false;
                    break;
                }
            }

            if(ans)
            {
                cout << num1 << " " << num2<<"\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        
    }

    return 0;
}