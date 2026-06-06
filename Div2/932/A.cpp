#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;

        if(s[0]<s[s.length()-1])
        {
            cout << s << "\n";
        }
        else if(s[0]>s[s.length()-1])
        {
            string reversed=s;
            reverse(reversed.begin(), reversed.end());
            reversed += s;
            cout << reversed << "\n";
        }
        else 
        {
            string reversed=s;
            reverse(reversed.begin(), reversed.end());
            reversed += s;
            if(reversed > s) cout << s << "\n";
            else
                cout << reversed << "\n";
        }
    }

    return 0;
}

// operation
// 1. reversed string을 기존 문자열 뒤에 붙이기
// 2. 현재 string을 reverse

// 정확히 n번 연산해야하고 사전순으로 가장 작은 문자열 출력 (n은 항상 짝수)

// 1. 주어진 문자열의 맨 앞과 맨 뒤를 비교
// 2. s[0] < s[s.length()-1] 이라면 
//    입력받은 문자열 그대로 출력
// 3. s[0] > s[s.length()-1] 이라면
//    입력받은 문자열을 한번 뒤집음(2번연산) 그 다음
//    현재 상태의 reverse 문자열 뒤에 붙임 (1번연산)
//    string 출력
// 4. s[0]==s[s.length()-1] 이라면
//    기존 문자열 s랑 3번 연산해서 뒤집은 reversed랑 비교해서 더 작은거 출력

// https://codeforces.com/contest/1935/problem/A