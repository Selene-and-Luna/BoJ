#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n, m;
vector<vector<pair<bool, pair<int, int> > > > v; // 0/1, areanum, cnt

bool safe(int y, int x) {
    return y > -1 && x > -1 && y < n && x < m && !v[y][x].first;
}

void BFS() {
    bool chk[1001][1001] = { 0, };
    int areanum = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(safe(i, j) && !chk[i][j]) { // 지랄났노
                queue<pair<int, int> > q;
                vector<pair<int, int> > tmp; // y, x (= i, j)
                q.push({i, j});
                tmp.push_back({i, j});
                int cnt = 1;
                chk[i][j] = 1;
                while(!q.empty()) { // 눈아파
                    int y = q.front().first, x = q.front().second;
                    q.pop();
                    int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };
                    for(int i = 0; i < 4; i++) {
                        int yy = y + dy[i], xx = x + dx[i];
                        if(safe(yy, xx) && !chk[yy][xx]) {
                            cnt++;
                            chk[yy][xx] = 1;
                            q.push({yy, xx});
                            tmp.push_back({yy, xx});
                        }
                    }
                }
                for(int k = 0; k < tmp.size(); k++)
                    v[tmp[k].first][tmp[k].second].second = {areanum, cnt};
                areanum++;
            }
        }
}

int result(int y, int x) {
    if(!v[y][x].first)
        return 0;
    int dy[] = { 1, -1, 0, 0 }, dx[] = { 0, 0, 1, -1 };
    int cnt = 1;
    set<int> s;
    for(int i = 0; i < 4; i++) {
        int yy = y + dy[i], xx = x + dx[i];
        if(safe(yy, xx) && s.find(v[yy][xx].second.first) == s.end()) {
            cnt += v[yy][xx].second.second;
            s.insert(v[yy][xx].second.first);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        vector<pair<bool, pair<int, int> > > tmp;
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            tmp.push_back({s[j] - '0', {0, 0}});
        v.push_back(tmp);
    }

    BFS();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << result(i, j) % 10;
        cout << '\n';
    }
}