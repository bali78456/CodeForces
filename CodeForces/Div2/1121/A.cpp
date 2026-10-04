#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &a:p)  cin >> a;

    if(n==1)
    {
        cout << "Yes\n";
        return;
    }

    vector<int> indices;
    for(int i = 0; i < n;i++)
    {
        if(p[i] != i + 1) indices.push_back(p[i]);
    }
    vector<int> sorted_indiex(indices);
    sort(sorted_indiex.begin(), sorted_indiex.end());
    reverse(indices.begin(), indices.end());

    if(sorted_indiex==indices)
    {
        cout << "Yes\n";
        return;
    }
    else
    {
        cout << "No\n";
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)  solve();

    return 0;
}
// op 딱 한번 수행가능
// 1. m (1 <= m <= n) 하나 고르고, 인덱스 i1..im 선택
//    선택한 인덱스에 있는 p의 요소들을 뒤집는다 => reverse

// 2 1 5 4
// 4 5 1 2

// 1. 본인 위치가 아닌 값들만 뽑아서 reverse 하고 
// 2. temp 배열에 sort한거 넣어서 reverse랑 같으면 yes 아니면 no

// https://codeforces.com/contest/2264/problem/A