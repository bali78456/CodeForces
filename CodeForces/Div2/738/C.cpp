#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 2);
        for(int i = 1; i < n;i++) {
            graph[i].push_back(i+1);
        }

        // 연산할 수열 입력받음
        int arr[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            if(arr[i]==0)
            {
                graph[i].push_back(n + 1);
            }
            else if(arr[i]==1)
            {
                graph[n + 1].push_back(i);
            }
        }

        bool exsist = false;
        int i = n;
        for(auto &a:graph[i])
        {
            if(a==n+1)
            {
                for(int i = 1; i <= n + 1;i++)
                    cout << i << " ";
                cout << "\n";
                exsist = true;
                break;
            }
        }

        if(!exsist)
        {
            i = n + 1;
            for(auto &a:graph[i])
            {
                if(a==1)
                {
                    cout << n + 1 << " ";
                    for(int i = 1; i <= n;i++)
                    {
                        cout << i << " ";
                    }
                    cout << "\n";
                    exsist = true;
                    break;
                }
            }
        }

        if(!exsist)
        {
            int num1, num2, num3;
            for(int i = 1; i <= n; i++) {
                for(auto &a:graph[i])
                {
                    if(a==n+1)
                    {
                        for(auto &c:graph[n+1])
                        {
                            if(c==i+1)
                            {
                                num1 = i;
                                num2 = n + 1;
                                num3 = i + 1;

                                exsist = true;
                                break;
                            }
                        }
                    }
                }
            }
            if(exsist)
            {
                for(int i = 1; i <= num1;i++)
                {
                    cout << i << " ";
                }
                cout << num2 << " " << num3 << " ";
                for(int i = num1+ 1; i <= n + 1;i++)
                {
                    if(i == num1 || i == num2 || i == num3) continue;
                    else
                        cout << i << " ";
                }
                cout << "\n";
            }
        }
        

        if(!exsist)
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}

// 정점 n+1 개
// 간선 2n-1 개 (단방향)
// n-1개 간선 도시 i부터 i+1까지
// 간선 n개는 a1..an까지 나타냄

// ai == 0 이라면 i번째 간선은 i에서 n+1로 향함 (n+1은 마지막 마을)
// ai == 1 이라면 정점 n+1에서 정점 i로 향함

// 모든 정점을 한번씩만 방문하려고 할 때
// 방문한 정점 순서 출력 (n+1개)
// 가능하지 않다면 -1 출력

// 일단 1 to n-1 까지는 단방향으로 연결되어있으니까
// 입력으로 주어진 수열대로 간선그림다음에 n => n+1 간선 존재하면 1부터 n+1까지 순서대로 출력

// 1. n => n+1 간선이 존재하거나
// 2. n+1 => 1로 가는 간선이 존재하거나 
// 3. i, i+1이 있고, i -> n+1 로 갈 수 있고, n+1 -> i+1로 갈 수 있다면
//    (1 -> i -> n+1 -> i+1 -> .. n )


// https://codeforces.com/contest/1559/problem/C