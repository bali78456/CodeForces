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
        vector<int> v(n);
        for(int i = 0; i < n;i++)
            cin >> v[i];

        int temp = v[0];
        int cnt = 1;
        vector<pair<int, int>> block;
        for(int i = 1; i < n; i++) {
            if(v[i]==temp)
            {
                cnt++;
            }
            else
            {
                block.push_back({temp, cnt});
                temp = v[i];
                cnt = 1;
            }
        }
        block.push_back({temp,cnt});
        

        int m = block.size();
        
        bool ans = false;
        for(int i = 0; i < block.size() - 1; i++) {
            if(block[i].second>=2 && block[i+1].second>=2)
            {
                ans = true;
                m += 2;
                break;
            }
        }
        if(ans)
        {
            cout << m << "\n";
        }
        else
        {
            bool flag = false;
            for(int i = 0; i < block.size(); i++) {
                if(block[i].second>=2)
                {
                    if(block[i-1].second==1&&i-1>=0)
                    {
                        if(i-2>=0)
                        {
                            if(block[i-2].first!=block[i].first)
                            {
                                m += 1;
                                flag = true;
                                break;
                            }
                        }
                        else
                        {
                            m+=1;
                            flag = true;
                            break;
                        }
                    }
                    
                    if(block[i+1].second==1&&i+1<=block.size()-1)
                    {
                        if(i+2<=block.size()-1)
                        {
                            if(block[i+2].first!=block[i].first)
                            {
                                m+=1;
                                flag = true;
                                break;
                            }
                        }
                        else
                        {
                            m += 1;
                            flag = true;
                            break;
                        }
                    }
                }
            }
            cout << m << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 인접한 숫자가 같으면 안되고 원하는만큼 모듈 제거 가능
// 마지막으로 남아있는 인접한 두 모듈의 위치를 한 번 스왑 가능

// 1. 블록수 세서 == n이면 n 출력
// 2. 나머지 경우
//    각 블럭당 개수 가지고 맨 앞 or 맨 뒤 블록이 2이상이면 걔네들은 버려야됨
//    나머지 내부에 있는 애들은 스왑 한번으로 붙어있는 애들은 커버 가능
// 3. 각 블록에서 1개씩만 남겨놨을 때가 최소 길이
//    기존 블럭 수가 3이상인 경우는 최소 2까지는 줄여놔야됨
// 4. 지울거 다 지워놓고 스왑한번으로 원소를 살려야됨 2 2 붙어있는곳
//    

// 1 2 2 3 3 1
// 1 2 3 2 3 1

// 1 1 2 3 3 2 2 1
// 1 2 3 3 2 2 1
// 2 1 2 2 1
// 1 1 1 1 1 => -3

// 1. 블록수가 기본적으로 얻을 수 있는 최대 모듈 수 = m
// 2. 스왑을 통해서 m+1 or m+2 까지 가능
//    AAB 라면 ABA로 m+1, AABB라면 ABAB로 m+2
// 3. i = 2 고 i-1 or i+1이 1이라면 스왑이 가능한데 서로 떨어져있는게
//    다른 모듈이어야 가능 i-1이 1이라면 i-2랑 i랑 확인
//    i+1이 1이라면 i+2랑 i랑 확인

// 1 1 2 1 1 3
// 1 2
// 2 1
// 1 2
// 3 1
// m=4

// https://codeforces.com/contest/2253/problem/B