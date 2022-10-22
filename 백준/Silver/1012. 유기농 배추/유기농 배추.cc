#include <iostream>
#include <string.h>
using namespace std;

int arr[51][51], chk[51][51], n, m;

bool safe(int y, int x) {
    return y >= 0 && y < n&& x >= 0 && x < m;
}

void dfs(int y, int x) {
    if (safe(y, x) && arr[y][x] && !chk[y][x]) {
        chk[y][x] = 1;
        dfs(y + 1, x);
        dfs(y - 1, x);
        dfs(y, x + 1);
        dfs(y, x - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(chk, 0, sizeof(chk));

        int k;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1 && !chk[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
}