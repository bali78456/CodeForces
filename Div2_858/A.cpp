#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
 
        int move_y = 0;
        int move_x = 0;
        
        if(b>d)
        {
            cout << -1 << "\n";
        }
        else 
        {
            while(b!=d)
            {
                move_y++;
                b++;
                a++;
            }
            if(a < c) cout << -1 << "\n";
            else
            {
                while(a!=c)
                {
                    a--;
                    move_x++;
                }
                cout << move_x + move_y << "\n";
            }
        }
    }

    return 0;
}
 
// (x, y) 에 있다면 (x+1, y+1) or (x-1, y)로만 이동가능
 
// 초기위치 (a, b)
// (c, d)로 가고싶어함
// 최소이동횟수 출력
// 못간다면 -1
 
// 일단 y를 맞추고
// 그다음 x 빼야됨