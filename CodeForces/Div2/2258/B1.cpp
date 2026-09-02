#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int>cnt(m+1,0);
        vector<int> prefixSum(m + 1, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        prefixSum[1] = cnt[1];
        for(int i = 2; i <= m; i++) {
            prefixSum[i] = prefixSum[i - 1] + cnt[i];
        }

        int ans = 0;
        for(int l = 1; l <= m; l++) {
            int count_2l = (2 * l <= m) ? cnt[2 * l] : 0;
            int temp = cnt[l] + count_2l + (prefixSum[m] - prefixSum[l]);
            ans = max(ans, temp);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
// k==1일 때만 생각
// 당근 하나를 x,l-x 로 나눌수있다 k번만큼 연산가능
// 같은 길이를 가지는 당근 최대개수 출력

// 양의정수 x를 하나 고르고 당근 집합 고른다
// 선택한 모든 당근에 대해 당근의 길이를 l이라고할때
// l<=x 라면 당근은 유지
// l>x 라면 당근은 길이가 x인 당근과 l-x인 당근 두개로 나눠진다

// 1. 빈도수 세는 카운트 배열 만든다
// 2. 길이가 l 이상인 당근이 총 몇개있는지를 구하기 위해 카운트 배열의 누적합 배열 만든다
//    prefix[i]=길이가 1부터 i까지인 당근 개수의 합
//    길이가 정확히 l 초과인 당근의 개수 = prefix[m]-prefix[l]로 계산 가능
// 3. 1부터 m까지 for문을 돌면서 x=l로 정했을 때 길이가 l인 당근이 총 몇개가 만들어지는가 확인
//    - 원래부터 길이가 l이었던 당근은 cnt[l] 만큼 더해줌
//    - 원래 길이가 정확히 2*l 이었던 당근은 cnt[2l]*2 만큼 더해줌(2*l<=m 일때만)
//    - 원래 길이가 l보다 크면서 2l은 아닌 당근은
//      prefix[m]-prefix[l]-cnt[2l]
// 4. 공식을 정리하면 총 l = cnt[l]+cnt[2*l]+(prefix[m]-prefix[l])
// 5. 이렇게 가장 큰 값을 max로 갱신해주면 됨

// https://codeforces.com/contest/2258/problem/B1