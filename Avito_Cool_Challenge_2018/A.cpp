#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n == 2) cout << 2;
    else
        cout << 1;
    return 0;
}

// n의 약수가 아닌 수 x를 골라서
// n <- n - x 
// 이 게임이 끝났을 때의 n의 값을 최소화
// n = 10
// 1 2 5 제외
// 10 - 4 = 6
// 1 2 3 제외
// 6 - 5 = 1

// n -1 이 가장 큰 약수가 아닌 수 아닌가
// n-1이 n의 약수가 되는 경우
// 2
// n == 2 라면 답은 무조건 2가 돼야한다