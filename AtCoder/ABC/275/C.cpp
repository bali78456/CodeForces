#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> s(9);
    for(int i = 0; i < 9;i++)
    {
        cin >> s[i];
    }

    // 폰 좌표 저장
    vector<pair<int, int>> v;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9;j++)
        {
            if(s[i][j]=='#')
            {
                v.push_back({i, j});
            }
        }
    }

    int ans = 0;
    int len = v.size();
    for(int i = 0; i < len;i++)
    {
        for(int j = 0; j < len;j++)
        {
            if(i == j) continue;
            auto A = v[i];
            auto B = v[j];

            int dr = B.first - A.first;
            int dc = B.second - A.second;

            int r3 = B.first - dc;
            int c3 = B.second + dr;

            if(r3 < 0 || r3 >= 9 || c3 < 0 || c3 >= 9) continue;
            if(s[r3][c3] == '.') continue;

            int r4 = r3 - dr;
            int c4 = c3 - dc;
            if(r4 < 0 || r4 >= 9 || c4 < 0 || c4 >= 9) continue;
            if(s[r4][c4] == '.') continue;

            ans++;
        }
    }

    cout << ans / 4;

    return 0;
}

// 두 점 A(r1,c1) , B(r2,c2) 을 골라서 이 점을 기준으로 90도 회전하면서 정사각형 탐색
// 행의 변화량 dr = r2-r1
// 열의 변화량 dc = c2-c1
// 한 변의 벡터 (dr,dc) 일 때
// 반시계방향으로 90도 회전하면 다음변의 벡텨는 (-dc,dr)
// 이렇게 B -> C -> D 순으로 탐색

// B -> C
// B에서 출발하므로 (-dc, dr)
// r3 = r2 - dc
// c3 = c2 + dr

// C -> D
// r4 = r3 - dr Or (r1 - dc)
// c4 = c3 - dc Or (c1 + dr)



// https://atcoder.jp/contests/abc275/tasks/abc275_c