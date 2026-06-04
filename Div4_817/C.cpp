#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        map<string, int> m;
        vector<vector<string>> v(3, vector<string>(n));
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < n;j++)
            {
                string s;
                cin >> s;
                v[i][j] = s;
                auto it = m.find(s);
                if(it!=m.end())
                    m[s]++;
                else
                    m.insert({s, 0});
            }
        }

        int firstP = 0;
        int secondP = 0;
        int thirdP = 0;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < n;j++)
            {
                if(m[v[i][j]]==0 && i==0)
                {
                    firstP += 3;
                }
                else if(m[v[i][j]]==1&&i==0)
                {
                    firstP += 1;
                }
                
                if(m[v[i][j]]==0 && i==1)
                {
                    secondP += 3;
                }
                else if(m[v[i][j]]==1&&i==1)
                {
                    secondP += 1;
                }

                if(m[v[i][j]]==0 && i==2)
                {
                    thirdP += 3;
                }
                else if(m[v[i][j]]==1&&i==2)
                {
                    thirdP += 1;
                }
            }
        }
        cout << firstP << " " << secondP << " " << thirdP << "\n";
    }
    return 0;
}

// 길이가 3인 서로 다른 단어 n개 적는다

// 어떤 단어를 오직 한 사람만 적었다면 그 사람 3점 획득
// 두 사람이 적었다면 각각 1점 획득
// 모든 사람이 적었다면 0점

// ouput = 각 플레이어가 최종적으로 획득한 점수

// https://codeforces.com/contest/1722/problem/C