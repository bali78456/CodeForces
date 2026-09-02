#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> parent;
vector<int> group_size;

int find(int x)
{
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x,int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if(rootX!=rootY)
    {
        parent[rootY]=rootX;
        group_size[rootX] += group_size[rootY];
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;
    parent.resize(n + 1);
    group_size.assign(n + 1, 1);

    for(int i = 1; i <= n;i++)
        parent[i] = i;
    
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    int max_group_size = 0;
    for(int i = 1; i <= n;i++)
    {
        if(parent[i]==i)
        {
            max_group_size = max(max_group_size, group_size[i]);
        }
    }
    cout << max_group_size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// x y 가 친구고 y z 가 친구라면 x z 도 친구다
// n명의 사람을 모두 친구가 없는 그룹으로 나누고싶다
// 그러기 위해서 필요한 최소 그룹 수 출력

// 1. 유니온파인드로 각 그룹 인원수 찾아서 최대 인원수 출력하면됨

// https://atcoder.jp/contests/abc177/tasks/abc177_d?utm_source=chatgpt.com