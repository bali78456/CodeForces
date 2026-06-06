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
        string s;
        cin >> s;

        int left = -1, right = -1;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]=='B')
            {
                left = i + 1;
                break;
            }
        }
        for(int i = s.length() - 1; i >= 0;i--)
        {
            if(s[i]=='B')
            {
                right = i + 1;
                break;
            }
        }
        if(left==right && left!=-1 && right != -1)
        {
            cout << 1 << "\n";
        }
        else if(left==-1 && right ==-1)
        {
            cout << 0 << "\n";
        } else {
            cout << right - left + 1<<"\n";
        }
    }
    return 0;
}

// 연속된 구간을 선택하여 모든 칸을 하얗게 만들기 위한 구간의 최소 길이

// left==right = 1
// right-left+1;

// 만약 전부 다 w이라면 결국 left == right == -1 일텐데

// https://codeforces.com/contest/1927/problem/A