#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> diff(n + 2,0);
    vector<int> prefix_sum(n + 1,0);
    vector<vector<pair<int,int>>> idx(q + 1,vector<pair<int,int>>());

    for(int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        idx[x].push_back({l,r});
    }

    for(int i = 1; i <= q; i++) {
        if(idx[i].empty()) continue;

        sort(idx[i].begin(), idx[i].end());
        int cur_l = idx[i][0].first;
        int cur_r = idx[i][0].second;

        for(int j = 1; j < idx[i].size();j++)
        {
            int next_l = idx[i][j].first;
            int next_r = idx[i][j].second;

            if(next_l<=cur_r)
            {
                cur_r = max(cur_r, next_r);
            }
            else
            {
                diff[cur_l] += 1;
                diff[cur_r + 1] -= 1;

                cur_l = next_l;
                cur_r = next_r;
            }
        }
        diff[cur_l] += 1;
        diff[cur_r+1] -= 1;
    }

    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + diff[i];
    }
    for(int i = 1; i <= n;i++)
        cout << prefix_sum[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// L R X가 주어지면
// X를 S_Li, S_Li+1,,, S_Ri까지 추가해라

// 1. x값 기준으로 l,r 입력받고 정렬
// 2. 같은 x갑들의 l,r을 구간병합
// 3. 차분배열로 각 구간 원소개수 세면 됨

// https://atcoder.jp/contests/abc478/tasks/abc478_d