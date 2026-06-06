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
        vector<int> v(n + 1);
        vector<int> odd;
        vector<int> even;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            if(v[i] % 2 == 0) even.push_back(v[i]);
            else if(v[i]%2!=0)
                odd.push_back(v[i]);
        }

        for(auto &a:odd)
            cout << a << " ";
        for(auto &a:even)
            cout << a << " ";
        cout << "\n";
    }

    return 0;
}
// n 멤버가 있고
// i번째 멤버는 ai height을 가지고 있다
// pair를 짜야함 pair의 height = au+av / 2 = 정수라면 photogenic하다

// ouput = 이 pair 의 수를 maximize 해야됨
// 그냥 홀 홀 붙이고 마지막에 짝수 밀어넣으면 됨

// https://codeforces.com/contest/1509/problem/A