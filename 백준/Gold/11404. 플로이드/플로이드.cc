#include <iostream>
using namespace std;
int city[101][101]; // city[start][arrive], fee

void Floyd_Warshall(int &n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if(i == k)
                continue;
            for(int j = 1; j <= n; j++) {
                if(i == j)
                    continue;
                if(!city[i][j]) {
                    if(city[i][k] && city[k][j])
                        city[i][j] = city[i][k] + city[k][j];
                }
                else {
                    if(city[i][k] && city[k][j])
                        city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
                }

            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c; // start, arrive, fee
        cin >> a >> b >> c;
        if(!city[a][b])
            city[a][b] = c;
        else
            city[a][b] = min(city[a][b], c);
    }

    Floyd_Warshall(n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << city[i][j] << ' ';
        cout << '\n';
    }
}