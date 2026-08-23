#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int>p(n+1);
    vector<int> p_invers(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        p_invers[p[i]] = i;
    }
    bool inverted = false;
    for(int i = 0; i < q; i++) {
        int num,x,y;
        cin >> num;
        if(num==1)
        {
            cin >> x >> y;
            if(!inverted)
            {
                swap(p[x], p[y]);
                swap(p_invers[p[x]], p_invers[p[y]]);
            }
            else
            {
                swap(p_invers[x], p_invers[y]);
                swap(p[p_invers[x]], p[p_invers[y]]);
            }
        }
        else 
        {
            inverted = !inverted;
        }
    }
    if(inverted)
    {
        for(int i = 1; i <= n;i++)
        {
            cout << p_invers[i] << " ";
        }
    }
    else
    {
        for(int i = 1; i <= n;i++)
        {
            cout << p[i] << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 쿼리
// 1. 1 x y = Px Py 스왑
// 2. 모든 1 to n 에 대해 Pp'i=i 를 만족하는 순열 P' 구하고 교체

// 에디토리얼
// 1. P^-1 를 구하고
// 2. 1번연산 들어오면 P,P-1 둘 다 스왑
// 3. 2번연산이면 P-1를 P로 보고 서로 뒤집어준다

// https://atcoder.jp/contests/abc470/tasks/abc470_d