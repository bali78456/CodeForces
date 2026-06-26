#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    for(int i = 1; i <= h;i++)
    {
        for(int j = 1; j <= w;j++)
        {
            if(i>1 && j>1 && j<w && i<h)
            {
                cout << ".";
            }
            else
                cout << "#";
        }
        cout << "\n";
    }
        return 0;
}

// https://atcoder.jp/contests/abc452/tasks/abc452_b