#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> days(m + 1);
    vector<int> cnt(n + 1);
    int color = 0;

    for(int i = 0; i < n;i++)
    {
        int a, d, b;
        cin >> a >> d >> b;
        if(cnt[a] == 0) color++;
        days[d].push_back({a, b});
        cnt[a]++;
    }

    for(int i = 1; i <= m;i++)
    {
        for(auto &pair:days[i])
        {
            cnt[pair.first]--;
            if(cnt[pair.first] == 0) color--;
            if(cnt[pair.second] == 0) color++;
            cnt[pair.second]++;
        }
        cout << color << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// n마리 새, m Day
// n가지 색 1 to N
// i번째 새는 Di-1 일의 관찰에서는 색 Ai를 가졌고,
// Di일 이상의 관찰에서는 색상 Bi를 가졌다

// 1. 새 i의 정보가 Ai, Di, Bi일 때
// 0일차: 색상 Ai인 새 1마리 증가
// Di일차: 색상 Ai인 새가 1마리 감소
// Di일차: 색상 Bi인 새가 1마리 증가

// https://atcoder.jp/contests/abc464/tasks/abc464_c