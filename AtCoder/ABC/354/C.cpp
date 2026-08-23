#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Card{
    int a, c, id;
};

bool comp(const Card& x, const Card& y)
{
    return x.a < y.a;
}

void solve()
{
    int n;
    cin >> n;
    vector<Card>card(n);
    for(int i = 0; i < n;i++)
    {
        cin >> card[i].a >> card[i].c;
        card[i].id = i + 1;
    }
    sort(card.begin(), card.end(), comp);

    vector<int> ans;
    int min_cost = 2e9;
    for(int i = n - 1; i >= 0; i--) {
        if(card[i].c < min_cost) {
            min_cost = card[i].c;
            ans.push_back(card[i].id);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto &a:ans)
        cout << a << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// Ai = strength
// Ci = cost

// 연산
// 1. Ax > Ay 이고 Cx < Cy 인 두 카드 x,y 선택하고 카드 y를 버린다
// 2. 더이상 작업을 수행하지 못할때까지 지우고 남은 카드들의 집합 구해라

// 힘은 더 약하고 코스트는 더 높은 카드를 구해라
// 1. struct 만들어서 a,c,id 세 개 한번에 받고 오름차순 정렬
// 2. 뒤에서부터 보면서 최소비용 갱신하면서 탐색
// 3. 현재 카드 비용이 min_cost보다 크다면 
//    나보다 공격력이 높은 카드 중에 나보다 비용이 싸거나 같은 카드가 존재한다는거니까 지움
//    현재 카드 비용이 min_cost보다 작다면 살아남고 min_cost 갱신

// output 
// 입력받은 기준으로 남은 카드의 번호 와 개수 출력해야됨

// https://atcoder.jp/contests/abc354/tasks/abc354_c