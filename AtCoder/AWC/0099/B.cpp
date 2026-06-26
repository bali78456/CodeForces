#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(m);
    vector<ll> t(n);

    for(int i = 0; i < m; i++) {
        ll s, r;
        cin >> s >> r;
        v[i] = {r, s};
    }
    sort(v.begin(), v.end());

    vector<ll> prefix(m);
    prefix[0] = v[0].second;
    for(int i = 1; i < m; i++) {
        prefix[i] = max(prefix[i - 1], v[i].second);
    }

    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        auto it = upper_bound(v.begin(), v.end(), make_pair(t[i],LLONG_MAX));
        int idx = it - v.begin();
        idx--;
        if(idx>=0) {
            sum += prefix[idx];
        }
    }
    cout << sum;

    return 0;
}

// n명의 학생, m종류의 책
// s = 재미, r = 난이도
// tj = j번째 학생의 독해력


// 1. 자신의 독해력 이하의 난이도 가진 책만 읽을 수 있다
// 2. 타카하시는 각 학생에게 그 학생이 읽을 수 있는 책 중 재미도가 가장 높은 책 골라 빌려줌
// 3. 없다면 책을 빌려주지 않음 = 0

// output = 각 학생에게 책을 빌려줄 때 대출된 책들의 재미도의 총합


// https://atcoder.jp/contests/awc0099/tasks/awc0099_b