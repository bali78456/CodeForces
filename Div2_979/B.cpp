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
        for(int i = 1; i <= n;i++)
        {
            if(i == 1) cout << 0;
            else if(i==2)
                cout << 1;
            else
                cout << 0;
        }
        cout << "\n";
    }
    return 0;
}

// f(t) = t의 비어있지 않은 부분 수열 중 0으로만 이루어진 부분 수열의 개수
// f(t) = t의 비어있지 않은 부분 수열 중 최소한 하나의 1을 포함하는 부분 수열의 개수
// 문자열 내에서 서로 등장하는 위치가 다르면 서로 다른 부분 수열로 취급

// output = oneness = |f(t) - g(t)|

// n이 주어질 때 oneness의 값이 가장 작아지는 길이 n짜리 이진 문자열 s 출력

// n=3
// output = 010
// 0,0,00
// 1,01,10,010

// n = 4 
// 0101
// f(t) = 0, 0, 00 
// g(t) = 1, 1, 01, 01 ,10, 010,101

// 0100
// 0,0, 0, 00 ,00 ,000
// 1, 01, 10, 100, 0100

// https://codeforces.com/contest/2030/problem/B