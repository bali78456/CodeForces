#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n+1, vector<int>());
    vector<bool> used(n + 1,false);
    vector<bool> m_girl(n + 1, false);
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k;j++)
        {
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < v[i].size();j++)
        {
            if(!used[v[i][j]])
            {
                used[v[i][j]]=true;
                m_girl[i] = true;
                break;
            }
        }
    }

    bool add_k = false;
    int add_k_idx = 0;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) 
        {
            add_k = true;
            add_k_idx = i;
            break;
        }
    }
    bool no_m_girl = false;
    int no_m_girl_idx = 0;
    for(int i = 1; i <= n; i++) {
        if(!m_girl[i])
        {
            no_m_girl = true;
            no_m_girl_idx = i;
            break;
        }
    }

    if(add_k&&no_m_girl) {
        cout << "IMPROVE\n";
        cout << no_m_girl_idx << " " << add_k_idx << "\n";
    } else {
        cout << "OPTIMAL\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;  cin >> t;
    while(t--)  solve();

    return 0;
}
// n 왕국 1 to n
// n 딸 1 to n
// 1번딸은 리스트에서 가장 번호가 작은 왕국 선택하고 결혼
// 2번째부터는 아직 다른 딸에게 배정되지 않은 왕자 중 가장 작은 번호 선택
// 만약 자신의 목록에 아직 배정되지않은 왕자가 하나도 없다면 결혼하지 못하고 패스
// n번딸까지 진행

// 실제 결혼 과정 시작하기 전에 왕은 딸 한명에게 어떤 왕자 한명을 추가로 결혼 후보로 
// 고려하도록 설득가능하다
// 딸 한명의 목록에 왕국 하나 추가 가능
// 단 그 왕국은 해당 딸의 기존 목록에 존재해서는 안됨
// 왕은 이 한번의 추가를 통해 결혼한 커플의 수를 증가시키고 싶다

// 1. 만약 목록에 왕국 하나를 추가해서 결혼한 커플의 수를 증가시킬 수 있다면 그러한 추가 방법
//    찾아서 출력
// 2. 어떤 방법을 사용해서 커플 수를 못늘린다면 OPTIMAL출력

// https://codeforces.com/contest/1327/problem/B