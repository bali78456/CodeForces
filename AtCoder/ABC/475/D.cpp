#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX 9999999
vector<bool> is_prime(MAX+1, true);

void Prime(int n)
{
    if(n<2) return;

    is_prime[0] = is_prime[1] = false;

    int limit = sqrt(n);
    for(int i = 2; i <= limit;++i)
    {
        if(is_prime[i])
        {
            is_prime[i] = i;
            for(int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool check_match(const string& S, string p) {
    vector<int> c2d(256, -1);
    vector<char> d2c(10, -1);
    for(int i = 0; i < S.length();i++)
    {
        char c = S[i];
        int d = p[i] - '0';

        // 둘 다 처음 등장한 경우
        if(c2d[c]==-1&&d2c[d]==-1)
        {
            c2d[c] = d;
            d2c[d] = c;
        }
        else if(c2d[c]!=d || d2c[d]!=c)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;

    bool flag = false;
    int ans = 0;
    for(int i = 2; i <= MAX; i++) {
        if(!is_prime[i]) continue;

        string temp = to_string(i);
        if(temp.length()==s.length())
        {
            if(check_match(s, temp))
            {
                flag = true;
                ans = i;
                break;
            }
        }
    }

    if(flag) cout << ans;
    else
        cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Prime(MAX);
    solve();

    return 0;
}
// 1. 전처리로 7자리까지 소수 구해놓고 알파벳이랑 대응되는 숫자 찾아서 출력

// https://atcoder.jp/contests/abc475/tasks/abc475_d