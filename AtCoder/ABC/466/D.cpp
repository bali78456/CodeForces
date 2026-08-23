#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> Ri(m + 1);
    vector<int> Ci(m + 1);
    
    for(int i = 1; i <= m; i++) {
        int r, c;
        cin >> r >> c;
        Ri[i] = r;
        Ci[i] = c;
    }

    int cnt=0;
    vector<bool>visited_row(n+1,false);
    vector<bool>visited_col(n+1,false);

    for(int i = m; i >= 1; i--) {
        if(!visited_row[Ri[i]]&&!visited_col[Ci[i]])
        {
            cnt++;
            visited_row[Ri[i]] = true;
            visited_col[Ci[i]] = true;
        }
        visited_row[Ri[i]] = true;
        visited_col[Ci[i]] = true;
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// n행 n열 크기 격자판 처음에는 비어있다
// m번의 조작을 한다
// i번째 조작에서
// 1. 위에서부터 Ri번째 행의 모든 칸에 있는 말을 전부 제거
// 2. 그다음 왼쪽에서부터 Ci번째 열의 모든 칸에 있는 말을 전부 제거
// 3. 위에서부터 Ri번째 행, 왼쪽에서부터 Ci번째 열이 만나는 칸에 새로운 말을 하나 놓는다

// output => 모든 조작을 마친 후 격자판 위에 남아있는 말의 총개수

// 1. 맨 뒤에서부터 본다
// 2. 제일 마지막 녀석은 무조건 살아남으니까 저장해놓음
// 3. 그다음 앞으로 가면서 Ri,Ci하나라도 같으면 패스함
// 4. 이런식으로 둘 다 위배되지 않는 것만 추가하면서 카운트하면 됨

// https://atcoder.jp/contests/abc466/tasks/abc466_d