#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0;
    vector<pair<int, bool>> v(n + 1);
    for(int i = 1; i <= n;i++)
    {
        int num;
        cin >> num;
        v[i].first = num;
        v[i].second = false;
    }
    v[1].second = true;
    cnt++;

    // for(int i = 1; i < n;i++)
    int i = 1;
    while(true) {
        int next = v[i].first;

        if(v[next].second == false) {
            v[next].second = true;
            cnt++;
            i = next;
        } 
        else
            break;
    }
    cout << cnt;

    return 0;
}

// 처음에는 1번 회원이 메시지 가지고있음
// 메세지 받은 사람은 수신완료로 표시

// 조건
// 1. 현재 메시지를 들고 있는 회원을 i라고 한다
// 2. 회원 i의 전송 대상인 pi가 이미 메시지를 받은적이 있는지 확인
// 3. 만약 pi가 메시지 받은 적 없다면 pi에게 전송
//    pi는 수신완료 후 1번을 돌아감
// 4. 만약 pi가 수신완료인 상태라면 그대로 종료
// output = 실험이 끝날 때 까지 수신완료로 기록된 총 회원 수 (1번포함)

// https://atcoder.jp/contests/awc0093/tasks/awc0093_b