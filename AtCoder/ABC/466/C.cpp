#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    int left = 1;
    int right = 2;
    int cnt = 0;
    while(right<=n)
    {
        cout << "?" << " " << left << " " << right << endl;
        string res;
        cin >> res;
        if(res=="Yes")
        {
            cnt += right - left;
            right++;
        }
        else
        {
            if(right - left != 1) left++;
            else
                right++;
        }
    }
    cout << "!" << " " << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 질문은 최대 2N만큼 가능
// left를 1에 고정시켜놓고 No가 나올때까지 right++시킴, 그럼
// left 부터 right 까지 점들이 전부 Yes라는 뜻

// 1 2 3 4 5
// 1.  3 4

// https://atcoder.jp/contests/abc466/tasks/abc466_c