#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    ll temp = 1e10;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        temp = min(temp, abs(v[i]));
    }
    sort(v.begin(), v.end());
    ll idx = 0;    // 처음 시작할 위치
    for(int i = 0; i < n; i++) {
        if(-temp==v[i] && v[i]<0)
        {
            idx = i;
            break;
        }

        if(temp==v[i] && v[i]>0)
        {
            if(v[i] >= 0) idx = i;
            break;
        }
    }
    ll dist = abs(temp);
    ll left=idx-1;
    ll right = idx+1;
    while(left>=0 && right<n)
    {
        if(abs(v[idx]-v[left]) > abs(v[idx]-v[right]))
        {
            dist += abs(v[idx] - v[right]);
            idx=right;
            right++;
        }
        else if(abs(v[idx]-v[left]) <= abs(v[idx]-v[right]))
        {
            dist += abs(v[idx] - v[left]);
            idx=left;
            left--;
        }
    }

    while(left>=0)
    {
        dist += abs(v[idx] - v[left]);
        idx = left;
        left--;
    }
    while(right<n)
    {
        dist+=abs(v[idx]-v[right]);
        idx = right;
        right++;
    }

    cout << dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// n개의 쿠키들이 ai 위치 좌표에 있다
// 좌표 0에서 시작
// 1. 현재 위치에서 가장 가까운 쿠키가 있는 좌표로 이동해서 그 쿠키를 줍는다
//    만약 거리가 같은 쿠키가 여러개라면 그중 좌표가 더 작은 쿠키로 이동
// 모든 쿠키를 주울 때 까지 이동한 총 거리를 구하라

// -1 -4 2 -11
// -1 -> -4 -> 2 -> -11

// 1. 오름차순 정렬
// 2. 전체적으로 한바퀴 돌면서 0에서 가장 가까운 위치 찾고 거기로 이동 후
//    왼쪽 오른쪽 중 더 작은거 찾아서 이동
// 3. 첫 시작 위치 찾고 거기서부터 투포인터로 

// * 두 좌표 사이의 거리 계산식
//   abs(현재위치-다음위치)

// https://atcoder.jp/contests/abc471/tasks/abc471_c