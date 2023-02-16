#include <iostream>
#define INF 0x7fffffff
using namespace std;

bool black[2001][2001], white[2001][2001]; // chess board
int DP_black[2001][2001], DP_white[2001][2001]; // DP용

int main() {
    int n, m, k, minimum = INF;
    cin >> n >> m >> k;

    // i = 0 : segfault -> i = 1 start
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if(!((i + j) % 2)) {
                if(c == 'B')
                    white[i][j] = 1;
                else if(c == 'W')
                    black[i][j] = 1;
            }
            else {
                if(c == 'B')
                    black[i][j] = 1;
                else if(c == 'W')
                    white[i][j] = 1;
            }
            DP_black[i][j] = DP_black[i - 1][j] + DP_black[i][j - 1] - DP_black[i - 1][j - 1] + black[i][j]; // 가로세로대각선 확인, bw따라 +1
            DP_white[i][j] = DP_white[i - 1][j] + DP_white[i][j - 1] - DP_white[i - 1][j - 1] + white[i][j];
        }
    }
    for(int i = 0; i <= n - k; i++) {
        for(int j = 0; j <= m - k; j++) {
            minimum = min(minimum, DP_black[i][j] + DP_black[i + k][j + k] - DP_black[i + k][j] - DP_black[i][j + k]);
            minimum = min(minimum, DP_white[i][j] + DP_white[i + k][j + k] - DP_white[i + k][j] - DP_white[i][j + k]);
        }
    }
    cout << minimum;
}