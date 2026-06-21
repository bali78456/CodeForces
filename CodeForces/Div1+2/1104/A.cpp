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
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for(int i = 1; i <= n;i++)
            cin >> v[i];
        for(int i = 1; i < n;i++)
        {
            if(v[i]<v[i+1])
            {
                v[i + 1] = v[i];
            }
        }
        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += v[i];
        cout << sum << "\n";
    }

    return 0;
}

// i번째 타워 높이는 ai
// 각 타워마다 한번씩만 연산 수행 가능
// 1. i번째 타워에서 오른쪽으로 레이저 쏴서 i번째 타워와 높이가 더 높은 애들은 높이가 같도록
//    자신의 바로 오른쪽 건물만 해당
// 2. j가 가장 작은 인덱스 j>i and aj>ai일 때 j가 존재하면 aj는 ai로 교체함

// 높이들의 최소 합 찾아라
// 주어진 배열이 내림차순으로 주어지면 그냥 다 더한게 답
// 오름차순이면 맨 앞 원소들로 다 만들면 됨

// 3 2 5 1
// 3 2 2 1

// https://codeforces.com/contest/2237/problem/A