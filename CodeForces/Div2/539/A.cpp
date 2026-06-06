#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, v;
    cin >> n >> v;

    int totalFuel = 0;
    int totalCost = 0;
    int leftCountry = 0;

    if(n<v)
    {
        totalFuel = n-1;
        totalCost = n-1;
        leftCountry = totalFuel;
    }
    else
    {
        totalFuel = n - 1;
        totalCost = v;
        leftCountry = totalFuel;
    }

    if(totalFuel == v) {
        cout << totalCost<<"\n";
    }
    else if(n==v)
    {
        cout << v - 1 << "\n";
    } else {
        for(int i = 2; i <= n;i++)
        {
            if(leftCountry == 0 || v>=leftCountry) break;
            else
            {
                totalCost += i;
                leftCountry--;
            }
        }
        cout << totalCost << "\n";
    }

    return 0;
}

// n = cities ( 1 to n ) 인접한 두 도시의 거리는 1
// city x 에서 city y 를 가는게 가능함 (x<y)

// v = 자동차의 기름통 용량 1키로당 1리터 소모
// 1번 도시에서 시작하고 n번 도시로 가고싶다

// 각 도시마다 주유소 있음
// i번째 도시의 기름 가격은 리터당 i달러

// 여행을 위해 필요한 기름의 총 최소가격

// 1. 필요한 총 기름 = n-1
// 2. if totalFuel = n-1 이라면 totlaFuel 출력

// 3. else => 4 2 라면 totlFule = 3, totalCost=2
//    totalFule-v = 1 , i++ => i=2, totalCost+=i

// 5 3
// cost = 3
// 1->2, fuel=2 + 1 = 3, cost = 3 + 2 = 5
// 2->3, fuel=2 , cost = 5

// https://codeforces.com/contest/1113/problem/A