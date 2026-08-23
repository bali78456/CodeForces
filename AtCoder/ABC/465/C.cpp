#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int c = 0;
    deque<int> dq;

    for(int i = 0; i < n;i++)
    {
        if(c%2==0)
        {
            dq.push_back(i + 1);
            if(s[i] == 'o') c++;
        }
        else if(c%2!=0)
        {
            dq.push_front(i + 1);
            if(s[i] == 'o') c++;
        }
    }
    if(c%2!=0)
    {
        reverse(dq.begin(), dq.end());
    }
    for(auto &a:dq)
        cout << a << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 각 i번째 숫자는 i번째보다 작은 위치의 문자가 o이라면 위치가 바뀌지 않는다
// i번째 위치 문자가 o라면 i번째 숫자는 맨 앞으로 이동함

// 맨 첫번째 문자열이 'o'라면 아무 변화도 없음
// 맨 마지막 문자열이 'o'라면 마지막 숫자는 무조건 맨 앞으로 이동함


// Sk='o' 라면
// Ak, Ak-1,...,A1,Ak+1,Ak+2,...,An 이렇게 변함

// 1. 현재 배열이 뒤집힌 상태인지 아닌지를 체크하는 변수 c를 둔다
// 2. c가 짝수일 때 o를 만났다면 원래는 k를 뒤에 붙이고 뒤집어야 하니까 결국 k는 맨 앞으로 간다
//    이제 배열은 홀수번 뒤집힌 역방향 상태가 됨
// 3. c가 홀수일 때 o를 만난 경우 원래는 k를 뒤에 붙이고 뒤집어야 하는데
//    이미 배열이 뒤집혀 있으므로 실제로는 맨 앞에 붙인 뒤 뒤집는 상황임
//    결과적으로 k가 맨 뒤로 가면 된다. 이제 배열은 다시 정방향 상태가 됨

// https://atcoder.jp/contests/abc465/tasks/abc465_c