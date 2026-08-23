#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<pair<string, string>> a;
    vector < pair<string, string>>b;

    for(int i = 0; i < n;i++)
    {
        string name,title;
        cin >> name>>title;
        if(title=="student"||title=="other")
        {
            b.push_back({name, "san"});
        } else {
            a.push_back({name, "sensei"});
        }
    }
    for(auto p:a)
    {
        cout << p.first << " " << p.second << "\n";
    }
    for(auto p:b)
    {
        cout << p.first << " " << p.second << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// https://atcoder.jp/contests/awc0129/tasks/awc0129_a