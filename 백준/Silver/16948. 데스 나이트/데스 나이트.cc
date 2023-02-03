#include <iostream>
#include <queue>
using namespace std;
int n;
bool chk[201][201];

bool safe(int r, int c) {
    return c < n && r < n && c > -1 && r > -1;
}

// (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)
void moveto(queue<pair<int, pair<int, int> > > &q, int &r, int &c, int &cnt) {
    if(safe(r - 2, c - 1) && !chk[r - 2][c - 1]) {
        q.push({cnt + 1, {r - 2, c -1}});
        chk[r - 2][c - 1] = 1;
    }
    if(safe(r - 2, c + 1) && !chk[r - 2][c + 1]) {
        q.push({cnt + 1, {r - 2, c + 1}});
        chk[r - 2][c + 1] = 1;
    }
    if(safe(r, c - 2) && !chk[r][c - 2]) {
        q.push({cnt + 1, {r, c - 2}});
        chk[r][c - 2] = 1;
    }
    if(safe(r, c + 2) && !chk[r][c + 2]) {
        q.push({cnt + 1, {r, c + 2}});
        chk[r][c + 2] = 1;
    }
    if(safe(r + 2, c - 1) && !chk[r + 2][c - 1]) {
        q.push({cnt + 1, {r + 2, c - 1}});
        chk[r + 2][c - 1] = 1;
    }
    if(safe(r + 2, c + 1) && !chk[r + 2][c + 1]) {
        q.push({cnt + 1, {r + 2, c + 1}});
        chk[r + 2][c + 1] = 1;
    }
}


int BFS(int &r1, int &c1, int &r2, int &c2) {
    queue<pair<int, pair<int, int> > > q; // cnt, {r, c}
    q.push({0, {r1, c1}});
    chk[r1][c1] = 1;
    while(!q.empty()) {
        pair<int, pair<int, int> > p = q.front();
        q.pop();
        if(p.second.first == r2 && p.second.second == c2)
            return p.first;
        moveto(q, p.second.first, p.second.second, p.first);
    }
    return -1;
}

int main() {
    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << BFS(r1, c1, r2, c2);
}