#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);

    for(int i = 1; i <= n;i++)
        cin >> a[i];

    for(int i = 1; i <= n;i++)
    {
        cin >> b[i];
        if(a[b[i]]!=i)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}

// n woodcutters have one axe
// i , owned axe Ai (woodcutter says) 나무꾼 i는 내가 소유했던 도끼는 ai다
// i , owned Bi (god knows) 도끼 i를 소유했던 나무꾼이 나무꾼 bi 라는걸 안다

// 3 1 2
// 2 3 1

// https://atcoder.jp/contests/abc461/tasks/abc461_b