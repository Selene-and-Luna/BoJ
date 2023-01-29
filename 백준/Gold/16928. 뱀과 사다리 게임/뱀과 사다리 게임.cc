#include <iostream>
#include <queue>
#include <map>
using namespace std;
bool chk[106];
map<int, int> ls; // start, end

int BFS() {
    int num;
    bool visit[106] = { 0, };
    queue<pair<int, int> > q; // dist, cnt
    q.push({1, 0});
    visit[1] = 1;
    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        for(int i = 1; i <= 6; i++) {
            int k = tmp.first + i;
            if(k > 99) {
                num = tmp.second + 1;
                return num;
            }
            if(!visit[k]) {
                visit[k] = 1;
                if(chk[k]) {
                    map<int, int>::iterator itr = ls.find(k);
                    q.push({(*itr).second, tmp.second + 1});
                }
                else
                    q.push({k, tmp.second + 1});
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        ls.insert({x, y});
        chk[x] = 1;
    }
    cout << BFS();
}