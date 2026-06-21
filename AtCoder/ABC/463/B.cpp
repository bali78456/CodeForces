#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    char x;
    cin >> n >> x;
    int num;

    if(x=='A')
        num = 0;
    else if(x == 'B')
        num = 1;
    else if(x == 'C')
        num = 2;
    else if(x == 'D')
        num = 3;
    else if(x == 'E')
        num = 4;
    
    string s[n];
    for(int i = 0; i < n;i++)
    {
        cin >> s[i];
    }

    bool ans = false;
    for(int i = 0; i < n; i++) {
        if(s[i][num]=='o')
        {
            ans = true;
        }
    }
    if(ans) cout << "Yes";
    else
        cout << "No";

    return 0;
}

// https://atcoder.jp/contests/abc463/tasks/abc463_b