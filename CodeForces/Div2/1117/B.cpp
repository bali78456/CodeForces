#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// void solve()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n,m;
//         cin >> n >> m;
//         vector<ll> a(n);
//         vector<ll> b(m);
//         for(int i = 0; i < n;i++)
//             cin >> a[i];
//         for(int i = 0; i <m;i++)
//             cin >> b[i];

//         vector<ll> a_temp;
//         vector<ll> b_temp;
//         for(int i = 0; i < n;i++)
//         {
//             if(i==n-1)
//             {
//                 a_temp.push_back(a[i]);
//             }
//             else
//             {
//                 if(a[i+1]!=1 || a[i]!=1)
//                 {
//                     if(a[i]-a[i+1]>=0)
//                     {
//                         a_temp.push_back(a[i] - a[i + 1] + 1);
//                     }
//                 }
//                 else
//                 {
//                     a_temp.push_back(a[i]);
//                 }
//             }
//         }

//         for(int i = 0; i < m;i++)
//         {
//             if(i==m-1)
//             {
//                 b_temp.push_back(b[i]);
//             }
//             else
//             {
//                 if(b[i+1]!=1 || b[i]!=1)
//                 {
//                     if(b[i]-b[i+1]>=0)
//                     {
//                         b_temp.push_back(b[i] - b[i + 1] + 1);
//                     }
//                 }
//                 else
//                 {
//                     b_temp.push_back(b[i]);
//                 }
//             }
//         }

//         ll a_sum=0;
//         ll b_sum = 0;
//         for(int i = 0; i < n;i++)
//             a_sum += a_temp[i];
//         for(int i = 0; i < m;i++)
//             b_sum += b_temp[i];

//         // cout << a_sum << " " << b_sum;
//         if(a_sum==b_sum)
//         {
//             cout << 1 << "\n";
//         }
//         else if(a_sum>b_sum)
//         {
//             cout << 1 << "\n";
//         }
//         else
//         {
//             cout << 2 << "\n";
//         }
//     }
// }

void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<ll> a(n), b(m);
        for(int i = 0; i < n;i++)
            cin >> a[i];
        for(int i = 0; i < m;i++)
            cin >> b[i];
        ll bea_turns = a[0] + n - 1;
        ll ver_turns = b[0] + m - 1;

        if(bea_turns >= ver_turns) cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// 1. 자기 차례에 상대방이 서 있는 산의 높이 - 1
// 2. 만약 자신이 현재 서 있는 산보다 바로 앞의 산이 더 높다면 그곳으로 이동한다
// 3. 자신이 현재 높이가 0인 곳에 있고 앞에 더이상 산이 없다면 패배 인정
// 순서는 비가 먼저 시작
// a가 이기면 1, b가 이기면 2 출력

// 1. 각 a,b 배열이 자기 바로 앞에 수를 뺀 숫자로 해야됨 (빼도 -가 아닐때만, 1 제외)
//    a[i] - a[i+1] + 1 을 새로운 벡터에 넣는다
//    단 a[i] or a[i+1] == 1 이라면 그냥 넣는다
// 2. 그다음 수의 총합이 더 큰쪽이 이김

// 4 3 2 1
// 2 2 2 1 => 7
// 10 1 => 11
// 6 5
// 2 5 => 7
// 3 5 8

// https://codeforces.com/contest/2257/problem/B