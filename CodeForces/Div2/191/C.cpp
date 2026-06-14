#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int prefix_open[n+1];
        int suffix_right[n+1];
        fill(prefix_open, prefix_open + n+1, 0);
        fill(suffix_right, suffix_right + n+1, 0);
        int right = 0;
        for(int i = 0; i < n;i++)
        {
            if(s[i] == ')') right++;
        }
    
        for(int i = 0; i < n; i++) {
            if(s[i]=='(')
            {
                prefix_open[i + 1] = prefix_open[i] + 1;
            }
            else
            {
                prefix_open[i + 1] = prefix_open[i];
            }
        }
        
        for(int i = n-1; i >=0 ; i--) {
            if(s[i]==')')
            {
                suffix_right[i] = suffix_right[i+1] + 1;
            }
            else
            {
                suffix_right[i] = suffix_right[i + 1];
            }
        }

        int max_bracket = 100000000;
        int idx = 0;
        for(int i = 0; i <= n; i++) {
            if(max_bracket>suffix_right[i] + prefix_open[i])
            {
                max_bracket = suffix_right[i] + prefix_open[i];
                idx = i;
            }
        }

        bool ans[n];
        fill(ans, ans + n, false);
        for(int i = 0; i < n;i++)
        {
            if(k == 0) break;
            if(i<idx&&s[i]=='(')
            {
                ans[i] = true;
                k--;
            }
            else if(i>=idx&&s[i]==')')
            {
                ans[i] = true;
                k--;
            }
        }
        for(int i = 0; i < n; i++)
            cout << ans[i];
        cout << "\n";
    }

    return 0;
}

// // 주어진 괄호 문자열에서 최대 k개의 문자 제거하여 남은 문자열 비용 최소화
// // output = 길이 n의 이진 문자열
// // i번째 문자열 제거한 경우 1, 유지할 경우 0
// // 1의 개수는 k개 초과하면 안됨
// // 표시된 문자들을 제거하고 남은 문자열의 비용이 최소가 되어야 한다
// // (가장 긴 올바른 괄호 부분 수열의 길이가 최소)

// // 주어진 문자열에서 이미 괄호 성립 안하는건 놔두고
// // 괄호 성립하는 애들중에서 최대 k개 지움

// Editorial
// 기준점 i를 찾아라
// 최대 괄호 쌍의 개수 = min(prefix_open+suffix_close)
// 

// // https://codeforces.com/contest/2233/problem/C