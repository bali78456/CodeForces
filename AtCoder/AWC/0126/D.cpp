#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int strToBit(const string &s)
{
    int mask=0;
    for(int i = 0; i < s.length();i++)
    {
        if(s[i]=='B')
        {
            mask |= (1 << (s.length() - 1 - i));
        }
    }
    return mask;
}

int rotateLeft(int state,int n)
{
    int msb = (state >> (n - 1)) & 1;
    int next_state = ((state << 1) & (1 << n) - 1) | msb;
    return next_state;
}

int rotateRight(int state,int n)
{
    int lsb = state & 1;
    int next_state = (state >> 1) | (lsb << (n - 1));
    return next_state;
}

int duplicatePattern(int state,int n,int d)
{
    int pattern = (state >> (n - d)) & ((1 << d) - 1);
    int next_state = 0;
    for(int i = 0; i < n / d;i++)
    {
        next_state = (next_state << d) | pattern;
    }
    return next_state;
}

int bfs(int start,int target,int n,const vector<int>&divisors)
{
    if(start==target) return 0;

    vector<int> dist(1 << n, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur==target)
        {
            return dist[cur];
        }

        int nxt_l = rotateLeft(cur, n);
        if(dist[nxt_l]==-1)
        {
            dist[nxt_l] = dist[cur] + 1;
            q.push(nxt_l);
        }

        int nxt_r = rotateRight(cur, n);
        if(dist[nxt_r]==-1)
        {
            dist[nxt_r] = dist[cur] + 1;
            q.push(nxt_r);
        }

        for(int d:divisors)
        {
            int nxt_dup=duplicatePattern(cur,n,d);
            if(dist[nxt_dup]==-1)
            {
                dist[nxt_dup] = dist[cur] + 1;
                q.push(nxt_dup);
            }
        }
    }
    return -1;
}

void solve()
{
    int n;
    cin >> n;
    string s,t;
    cin >> s;
    cin >> t;

    int bitS = strToBit(s);
    int bitT = strToBit(t);

    vector<int> divisors;
    for(int d = 1; d < n;d++)
    {
        if(n % d == 0) divisors.push_back(d);
    }

    cout << bfs(bitS, bitT, n, divisors);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// s => 초기 상태
// 연산
// 1. 왼쪽 회전: 구슬 수열을 왼쪽으로 순환 시프트(첫번째 문자 제거하고 맨 뒤에 붙임)
// 2. 오른쪽 회전: 마지막 문자 제거하고 맨 앞에 붙임
// 3. 패턴 복제: n의 양의 약수 d(d<n) 하나 선택, 현재 구슬 수열의 첫 d개 문자를 p라고 할 때
//             전체 구슬 수열 p를 정확히 n/d번 반복하여 이어 붙인 문자열로 교체
// s를 t와 일치하도록 위한 최소 조작 횟수, 이미 같다면 0, 못만든다면 -1

// https://atcoder.jp/contests/awc0126/tasks/awc0126_d