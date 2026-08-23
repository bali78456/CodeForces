#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// void solve()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n,m;
//         cin >> n >> m;
//         vector<string>w(n);
//         vector<string> a(m);
//         vector<int> cnt(123,0);
//         for(int i = 0; i < n; i++) {
//             cin >> w[i];
//             cnt[(char)w[i][0]]++;
//         }

//         bool flag = true;
        
//         for(int i = 0; i < m; i++) {
//             cin >> a[i];
//             vector<int> temp(cnt);
    
//             for(int j = 0; j < a[i].length(); j++) {
//                 if(temp[(char)tolower(a[i][j])] > 0) {
//                     temp[(char)tolower(a[i][j])]--;
//                     temp[(char)tolower(a[i][j])]++;
//                 } else {
//                     flag = false;
//                 }
//             }

//             if(flag)
//             {
//                 for(int j = 0; j < a[i].length(); j++) {
//                     cnt[(char)tolower(a[i][j])]++;
//                 }
//             }
//         }
//         if(flag) cout << "Yes\n";
//         else
//             cout << "No\n";
//     }
// }

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<bool>exists(26,false);
    for(int i = 0; i < n;i++)
    {
        string w;
        cin >> w;
        exists[w[0] - 'a'] = true;
    }

    bool flag = true;
    for(int i = 0; i < m;i++)
    {
        string a;
        cin >> a;
        for(char c : a)
        {
            if(!exists[tolower(c)-'a'])
            {
                flag = false;
            }
        }
    }
    if(flag) cout << "Yes\n";
    else 
        cout<<"No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}

// 1. n개 문자열 맨 앞글자만 따서 개수 저장
// 2. a배열에 문자열 하나씩 보면서 소문자로 변환하고 이 개수가 1개이상이면 통과

// https://codeforces.com/contest/2257/problem/A