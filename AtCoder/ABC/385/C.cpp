#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n+1);

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    int cnt = 1;
    vector<int> ans;
    for(int i = 1; i < n; i++) {
        int idxDiff = 0;
        for(int j = i + 1; j <= n; j++) {
            if(v[i] == v[j]) 
            {
                idxDiff = j - i;
                cnt = 2;
                int temp = v[j];
                for(int k = j+idxDiff; k <= n; k += idxDiff) {
                    if(v[k]==temp)
                    {
                        cnt++;
                        temp = v[k];
                    } else
                        break;
                }
                ans.push_back(cnt);
            }
            else
                ans.push_back(cnt);
        }
    }

    if(!ans.empty())
    {
        auto it=max_element(ans.begin(), ans.end());
        cout << *it;
    }
    else
        cout << 1;

    return 0;
}

// n개의 빌딩이 있고 i번째 빌딩의 높이는 Hi
// 조건
// 1. 선택한 건물의 높이가 모두 같아야 한다
// 2. 선택한 건물들의 간격이 일정해야 한다

// 선택할 수 있는 최대 빌딩의 수
// 만약 하나만 선택한다면 그건 컨디션 만족함


// 입력받을때마다 2차원 벡터로 수랑 인덱스
// 1. 주어진 건물의 높이가 모두 다르다면 답은 항상 1
// 2. 맨 첫 숫자부터 그 다음 같은수 나올때까지 가다가 
//    같은 수 찾으면 인덱스차이 저장하고 break
// 3. 다시 for문 돌면서 그 인덱스차이만큼 ++ 해가면서 같은수 나오면 ++ 하고 
//    다른수 나오면 거기서 break

// https://atcoder.jp/contests/abc385/tasks/abc385_c