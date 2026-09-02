#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
vector<vector<int>>adj;
vector<bool> has_dam;
vector<int> cameras;

int dfs(int u)
{
    int total_dam = has_dam[u] ? 1 : 0;
    vector<int>valid_children;
    for(int v:adj[u])
    {
        int childe_dams=dfs(v);
        if(childe_dams>0)
        {
            valid_children.push_back(v);
            total_dam += childe_dams;
        }
    }

    int X = valid_children.size();
    if(X>0)
    {
        if(has_dam[u])
        {
            for(int i = 0; i < X;i++)
            {
                cameras.push_back(valid_children[i]);
            }
        }
        else
        {
            for(int i = 0; i < X - 1;i++)
            {
                cameras.push_back(valid_children[i]);
            }
        }
    }
    return total_dam;
}

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        adj.assign(n + 1, vector<int>());
        has_dam.assign(n + 1, false);
        cameras.clear();

        for(int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        cin>>m;
        for(int i = 0; i < m;i++)
        {
            int a;
            cin >> a;
            has_dam[a] = true;
        }

        dfs(1);
        cout << cameras.size();
        for(int u:cameras)
        {
            cout << " " << u;
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

// pi는 2...n번 정점까지 부모 정점 번호
// a1...am 은 댐이 있는 정점의 번호
// 간선에 카메라 설치 가능(최소한의 카메라만 설치)

// output
// 설치해야할 최소한의 카메라 k와 어느 간선에 카메라를 달아야 하는지 출력
// 간선은 그 간선과 연결된 자식노드의 번호로 출력

// 트리 상에서 주어진 정보(댐)들로 향하는 모든 경로들을 식별하기 위해 필요한 최소 간선의 집합을 찾는 문제
// 주로 공통 조상(LCA)를 기준으로 트리 탐색해서  카메라를 달아야 하는 분기점을 찾는 알고리즘 설계해야한다

// 1. 비버는 댐이 없는 방향으로는 가지 않는다 
//    자식 노드 방향으로 dfs탐색을 해서 그 아래 트리에 댐이 1개라도 존재하는 자식의 개수를 센다
//    이 유요한 자식의 개수를 x라고 둔다
// 2. 비버가 갈 수 있는 방향은 x개로 좁혀짐
//    현재 내가 서 있는 정점 u에 댐이 없는 경우에는 갈 수 있는 길목이 3개라면 2곳에만 카메라를 달면 3개 다 확인 가능
// 3. 현재 내가 서 있는 정점 u에 댐이 있는 경우에는 비버의 선택지는
//    x개의 밑으로 가는 길 + 여기서 멈추기 = x+1개가 된다
//    x+1가지 경우를 다 구별할면 밑으로 가는 길 x개 전부에 카메라를 달면 된다

// https://codeforces.com/contest/2257/problem/C