#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int>a(n+1,0);
    vector<int> temp;
    vector<bool> in_temp(n + 1, false);
    int X = 0;

    for(int i = 0; i < q; i++) {
        int num, x;
        cin >> num;
        if(num==1)
        {
            cin >> x;
            int old_val=a[x];
            int new_val = a[x] + 1;
            X ^= old_val ^ new_val;
            a[x] = new_val;
            
            if(!in_temp[x])
            {
                temp.push_back(x);
                in_temp[x] = true;
            }
        } else {
            vector<int> next_temp;
            for(auto& p : temp) {
                int old_val = a[p];
                int new_val = a[p] - 1;
                X ^= old_val ^ new_val;
                a[p] = new_val;

                if(a[p] > 0) next_temp.push_back(p);
                else
                    in_temp[p] = false;
            }
            temp = move(next_temp);
        }
        cout << X << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 쿼리
// 1. 1 x = Ax를 1만큼 더해라
// 2. 2 = i=1 to n까지 1 이상인 원소들에 대해 1을 빼라

// output
// 매 쿼리마다 모든 a1 to an 까지 xor한 수를 출력

// 에디토리얼
// 1. 1 쿼리
//    A[x]의 값을 v라 하고
//    전체 xor합 갱신 => X = X ^ v ^ (v+1)
//    A[x]값을 v+1로 교체
// 2. 2 쿼리
//    A[i]>=1인 인덱스 따로 저장
//    각 i에 대해 v=A[i] 가져옴
//    전체 xor 합 갱신 X = X ^ v ^ (v-1)
//    A[i]의 값을 v-1로 갱신
//    A[i]가 0이 되었다면 양수 인덱스 집합에서 i제거

// https://atcoder.jp/contests/abc470/tasks/abc470_c