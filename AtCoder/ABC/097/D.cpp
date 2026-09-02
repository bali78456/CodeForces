#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> parent;

int find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x,int y)
{
    int rootX=find(x);
    int rootY = find(y);

    if(rootX == rootY) return;
    parent[rootY] = rootX;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    parent.resize(n + 1);

    for(int i = 0; i < n; i++)
        cin >> p[i];

    for(int i = 1; i <= n;i++)
        parent[i] = i;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    int ans = 0;
    for(int i = 1; i <= n;i++)
    {
        if(find(p[i-1])==find(i))
        {
            ans++;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// pi = i 를 최대화하기위해 연산 수행
// 1 <= j <= m 인 j를 골라 p_xj 와 p_yi의 위치를 서로 바꾼다
// 연산을 마친 후 pi=i를 만족할 수 있는 i의 최대 개수 구해라

// 1. 유니온파인드로 일단 연결요소끼리 연결해놓고
// 2. i번 위치에 숫자 p[i]가 들어있으니까 p[i]는 p[i]위치로 이동해야한다
//    즉 현재 위치 i와 목적지 위치인 p[i]가 같은 집합인지 확인하면 된다

// https://atcoder.jp/contests/abc097/tasks/arc097_b