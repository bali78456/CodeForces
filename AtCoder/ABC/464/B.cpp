#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> Map(h);
    for(int i = 0; i < h; i++) {
        cin >> Map[i];
    }

    // 맨 위
    int topIdx = 0;
    bool isTop = true;
    while(isTop) {
        for(int i = 0; i < w;i++)
        {
            if(Map[topIdx][i] == '#') isTop = false;
        }
        if(isTop)
            topIdx++;
    }

    // 맨 아래
    bool isBottom = true;
    int bottomIdx = h-1;
    while(isBottom) {
        for(int i = 0; i < w;i++)
        {
            if(Map[bottomIdx][i] == '#') isBottom = false;
        }
        if(isBottom)
            bottomIdx--;
    }

    // 맨 왼쪽
    bool isLeft = true;
    int leftIdx = 0;
    while(isLeft)
    {
        for(int i = 0; i < h;i++)
        {
            if(Map[i][leftIdx] == '#') isLeft = false;
        }
        if(isLeft)
            leftIdx++;
    }

    // 맨 오른쪽
    bool isRight = true;
    int rightIdx = w-1;
    while(isRight)
    {
        for(int i = 0; i < h;i++)
        {
            if(Map[i][rightIdx] == '#') isRight = false;
        }
        if(isRight)
            rightIdx--;
    }

    for(int i = topIdx; i <= bottomIdx;i++)
    {
        for(int j = leftIdx; j <= rightIdx;j++)
        {
            cout << Map[i][j];
        }
        cout << "\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 가장 위 아래 왼쪽 오른쪽 순으로 모두 흰색이면 제거

// https://atcoder.jp/contests/abc464/tasks/abc464_b