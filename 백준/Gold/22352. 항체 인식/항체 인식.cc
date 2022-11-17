#include <iostream>
#include <queue>
using namespace std;
int n, m;
int before[31][31], after[31][31];

bool safe(int y, int x) {
    return y >= 0 && x >= 0 && y < n && x < m;
}

void BFS(int head, int y, int x) {
    int vy[4] = {1, -1, 0, 0}, vx[4] = {0, 0, 1, -1};
    queue<pair<int, int> > q;
    int area = before[y][x];
    before[y][x]= head;
    bool chk[31][31] = { 0, };
    q.push({y,x});
    while(!q.empty()) {
        for(int i = 0; i < 4; i++) {
            int a = q.front().first + vy[i], b = q.front().second + vx[i];
            if(safe(a,b) && !chk[a][b] && before[a][b] == area) {
                chk[a][b] = 1;
                q.push({a,b});
                before[a][b] = head;
            }
        }
        q.pop();
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(before[i][j] != after[i][j]) {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> before[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> after[i][j];
    int head = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(before[i][j] != after[i][j]) {
                head = after[i][j];
                BFS(head, i, j);
                return 0;
            }
    BFS(before[0][0], 0, 0);
}