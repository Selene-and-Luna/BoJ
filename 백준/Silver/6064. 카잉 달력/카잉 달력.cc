#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int xbase = 1, ybase = 1, cnt = y;
        bool chk = 0;
        while(cnt <= m * n) {
            if(!((cnt - x) % m) && !((cnt - y) % n)) {
                cout << cnt << '\n';
                chk = 1;
                break;
            }
            cnt += n;
        }
        if(!chk)
            cout << -1 << '\n';
    }
    return 0;
}