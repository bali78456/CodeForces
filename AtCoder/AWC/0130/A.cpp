#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> r(m);
    for(int i = 0; i < m;i++)
        cin >> r[i];
    
    int takahashi=0;
    int aoki = 0;
    for(int i = 0; i < s.length();i++)
    {
        if(s[i] == 'T') takahashi++;
        else
            aoki++;
    }

    for(int i = 0; i < m;i++)
    {
        if(s[r[i]-1]=='T')
        {
            takahashi--;
            aoki++;
            s[r[i] - 1] = 'A';
        } else {
            takahashi++;
            aoki--;
            s[r[i] - 1] = 'T';
        }

        if(takahashi==0 || aoki==0)
        {
            cout<<i+1;
            return;
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// Si = T 면 학생 i가 타카하시 지지
// A 면 아오키 지지
// i번째 연설에서 Ri학생 설득되어 지지후보가 반대로 변한다
// 각 연설이 끝나고 한 후보의 지지자가 0이 되면 다른 후보의 승리 확정
// M번의 연설이 끝나기 전에 승리가 확정된다면 승리가 확정된 연설의 번호 출력
// M번의 연설이 완료된 후에도 두 후보 모두 지지자가 남아있다면 -1 출력

// https://atcoder.jp/contests/awc0130/tasks/awc0130_a