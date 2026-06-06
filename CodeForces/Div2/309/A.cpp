#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int sum = 0;
    for(int i = 0; i < s.length()+1;i++)
        sum += 25;
    cout << sum + 1;
    return 0;
}

// 26개 알파벳 중복때문에 + 1 마지막에
// s.len=1 앞 뒤로 한번씩 25 + 25 + 1
// s.len=2 라면 사이사이 총 세번 25+25+25+1

// https://codeforces.com/contest/554/problem/A