#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for(auto &q:a)
        cin >> q;
    vector<bool> is_same(n,false);

    for(int k = 0; k < n;k++)
    {
        for(int i = 0; i < 100; i++) {
            int num = 0;
            vector<int> b;
            for(int j = 0; j < a[k].length(); j++) {
                int temp = (a[k][j]) - '0';
                b.push_back(temp);
            }
            for(int j = 0; j < a[k].length(); j++)
            {
                num += b[j] * b[j];
            }

            a[k] = to_string(num);
        }
    }

    map<string, ll> cnt;
    for(int i = 0; i < n;i++)
    {
        cnt[a[i]]++;
    }
    ll ans = 0;
    for(auto p:cnt)
    {
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}
// n개의 등대
// 어떤 등대가 x를 표시한다면 내일 밤에는 x의 십진수 각 자리 숫자의 제곱의 합 표시
// 0번째 밤에 i번째 등대는 숫자 ai를 표시한다. 그날 밤부터 위 법칙 적용
// 두 등대 i와 j가 조화를 이룬다고 한다. 이는 특정 밤이 지난 후부터 영원히 두 등대가
// 매일 밤 같은 숫자를 표시하게 되는 경우
// i<j를 만족하면서 조화를 이루는 쌍은 몇개인가

// 1. 100번정도 op돌리고 map으로 같은 쌍체크해서 개수 더함

// https://codeforces.com/contest/2269/problem/B