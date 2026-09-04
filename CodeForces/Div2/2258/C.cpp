#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int U = 1;
        int max_d = 0;

        int respond;

        for(int i = 2; i <= n; i++) {
            while(true)
            {
                cout << "? " << 1 << " " << i << " " << max_d + 1 << "\n";
                cout.flush();
                cin >> respond;

                if(respond == -1) exit(0);

                if(respond==1)
                {
                    U = i;
                    max_d++;
                }
                else
                {
                    break;
                }
            }
        }

        // 찾은 리프노드 v를 u로 두고 나머지 리프노드까지의 최대거리 찾고
        // u,v,d 저장
        int V = 1;
        for(int i = 1; i <= n; i++) {
            if(i == U) continue;

            while(true)
            {
                cout << "? " << U << " " << i << " " << max_d+1 << "\n";
                cout.flush();
                cin >> respond;

                if(respond == -1) exit(0);

                if(respond==1)
                {
                    V = i;
                    max_d++;
                }
                else
                {
                    break;
                }
            }
        }

        // u,v,d 출력
        cout << "! " << U << " " << V << " " << max_d << "\n";
        cout.flush();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 트리의 지름의 길이와 그 거리만큼 떨어져있는 임의의 두 노드 쌍을 알아내야한다
// 최대 3*n번의 쿼리 가능
// 지름의 길이는 두 정점 사이의 가장 큰 거리
// n은 정점수
// 쿼리: u, v는 확인할 두 노드 쌍, d = 비교할 거리
// d가 dist(u,v) 이상이라면 1, 아니라면 0

// 1. d를 1씩 늘려가면서 최대거리 체크해야된다
// 2. 정점 하나 잡고 최대거리를 뽑으면 그 v가 리프노드다
//    그 v를 u로 잡고 v를 1부터 v제외 찾으면서 d를 1부터 ++ 하면서 max d 찾는다
// 3. 찾은 max u v d 출력

// https://codeforces.com/contest/2258/problem/C