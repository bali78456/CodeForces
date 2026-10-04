#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = -1;
    int y = -1;
    int z = -1;
    if((a + b - c) / 2 >= 0 && (a+b-c)%2==0)
    {
        x = (a + b - c) / 2;
    }

    if((a + c - b) / 2 >= 0 && (a+c-b)%2==0)
    {
        z = (a + c - b) / 2;
    }

    if((c + b - a) / 2 >= 0 && (c+b-a)%2==0)
    {
        y = (c + b - a) / 2;
    }

    if(x==-1 || y==-1 ||z==-1)
    {
        cout << "Impossible";
    }
    else
    {
        cout << x << " " << y << " " << z;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// 1-2, 2-3, 3-1
// 세 원자의 원자가가 주어질 때
// 이 세 원자로 분자를 만들 수 있다면 가능한 조합 출력

// 1. 1번원자의 경우 1-2, 1-3 번 합쳐서 원자가랑 같아야되고
//    2번원자는 2-1, 2-3 번 합쳐서
//    3번원자는 3-1, 3-2 번 합쳐서

// x = 1-2 사이 결합 수
// y = 2-3 사이 결합 수
// z = 3-1 사이 결합 수

// 1번원자: x + z = a
// 2번원자: x + y = b
// 3번원자 y + z = c

// 2x + y + z = a + b
// 2x + c = a + b
// 2x = a + b - c
// x= (a + b - c) / 2 <=

// 2y + x + z = b + c
// 2y = b + c - a
// y = (b + c - a) / 2 <=

// z = (a + c - b) / 2 <=

// https://codeforces.com/contest/344/problem/B