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
        int n, x, y, z;
        cin >> n >> x >> y >> z;

        int sumXY = x+y;
        int i = 1;
        int hours = 1;
        int sumWithAI = z * x;

        while(sumXY < n) {
            sumXY += (x * i) + (y * i);
        
            hours++;
        }
        
        int withoutAI = hours;

        hours = 1;
        while(sumWithAI < n) {
            sumWithAI += ((10*y)*i)+(x*i);
            hours++;
        }
        int withAI = z + hours-1;

        cout << min(withAI, withoutAI) << "\n";
    }

    return 0;
}

// 1. AI쓰지않고 시작한다 speed of y lines per hour
// 2. spend z hours 첫 AI 세팅, 그 시간동안 아무것도 안씀, 그리고 
//.   write 10*y lines per hour

// maxim 은 항상 매 시간 x라인을 쓰고
// nikita만 ai쓸지말지 결정 => ai 쓰면 10*y lines per hours

// at least n lines, ai 셋업되기 전에 프로젝트가 끝난다면 그시간에 프로젝트 종료
// 30분에 끝난다면 1시간으로 계산
// nikita 가 ai쓸지말지 정한다
// output => min num of full hours 

// input
// n = num of lines of project
// x = Maxim's speed
// y = Nikit's speed
// z = AI setup time

// 1. 둘이 더한 수 => 한시간동안 둘이 짜는 분량
// 2. 둘이 더한 수 * q >= n 까지 => q는 둘이서 ai없이 짰을 때 시간
// 3. 10 * y * q >= n 까지 => 10 + q는 AI썼을 때 시간
// 4. 1,2번 중 min 출력


// ai 안쓴경우
// x+y더해놓고
// i=2부터 

// ai 쓰는경우
// 막심은 그동안 x*10만큼의 라인 짜놨음 => x*10 미리 저장해두고 => 매시간 x*i
// 그 후부터 니키타는 10*y * i 만큼씩 매시간 짬

// https://codeforces.com/contest/2233/problem/A