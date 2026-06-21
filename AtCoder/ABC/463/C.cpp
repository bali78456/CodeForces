#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n;i++)
    {
        int h, l;
        cin >> h >> l;
        
        // 새로 입력받은 h보다 작거나 같은 애들은 모두 삭제
        while(!v.empty() && v.back().first<=h)
        {
            v.pop_back();
        }
        v.push_back({h, l});
    }

    cin >> q;
    vector<int> Q(q);
    for(int i = 0; i < q;i++)
    {
        cin >> Q[i];
        int idx = upper_bound(v.begin(), v.end(), make_pair(0, Q[i]),
                              [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }) -
                  v.begin();
        cout << v[idx].first << "\n";
    }
    return 0;
}

// i 번째 다카하시의 키는 hi, li 분 후에 회의실을 떠남
// q 개의 쿼리가 주어짐
// 지금부터ti + 1/2 분 후에 회의실에 남아있는 다카하시 중 가장 키가 큰 사람의 키 구해라

// 1. Ha >= Hb
//    La >= Lb 라면
// 2. b는 최댓값 계산에 영향을 주지 못한다

// https://atcoder.jp/contests/abc463/tasks/abc463_c