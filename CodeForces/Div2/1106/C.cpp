#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph;
ll total_guild;

int dfs(int u)
{
    ll max1 = 0;
    ll max2 = 0;
    for(auto &v:graph[u])
    {
        ll child_guild = dfs(v);
        if(child_guild>=max1)
        {
            max2=max1;
            max1 = child_guild;
        }
        else if(child_guild>max2)
        {
            max2 = child_guild;
        }
    }
    total_guild += max2;
    return max1 + 1;
}

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        total_guild = n;
        graph.assign(n + 1, vector<int>());
        for(int i = 2; i <= n;i++)
        {
            int a;
            cin >> a;
            graph[a].push_back(i);
        }
        dfs(1);
        cout << total_guild << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 임의의 집 v와 그 서브트리. 각 집 v와 음이 아닌 정수 h에 대해 v의 서브트리에 속하면서
// v로부터의 거리가 정확히 h인 집들의 집합. 이러한 집합을 길드라고 부른다
// h=0 이라면 길드는 정점 v 하나로 구성된다

// 한 길드에 속하지만 다른 길드에는 속하지 않는 집이 하나라도 존재한다면 두 길드는 
// 서로 다른 길드로 간주한다
// 이 트리 안에 서로 다른 비어있지 않은 길드가 총 몇개인가

// 1. 초기 길드의 개수는 전체 노드 개수인 n개로 시작(h=0)
// 2. dfs탐색, 각 노드 u는 자기 자식들이 뻗은 깊이들을 보고받는다(리프노드의 깊이는 1)
// 3. 새로운 길드 추가: 자식이 2개 이상이라면 보고받은 깊이 중 2번째로 큰 값(2등 깊이)를 찾아서 정답에 더해준다
// 4. 부모에게 보고: 현재 노드 u는 내 자식들 깊이 중 가장 큰 값(1등 깊이)에 + 1 해서 자신의 부모에게 return 한다

// https://codeforces.com/contest/2238/problem/C