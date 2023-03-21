#include <bits/stdc++.h>
using namespace std;
set<int> graph[100001];
bool chk[100001];
vector<int> seq, result;
int idx, n;

void DFS(int start) {
    while(idx < n) {
        int tmp = result[++idx];
        if(graph[start].find(tmp) != graph[start].end() && !chk[tmp]) {
            seq.push_back(tmp);
            chk[tmp] = 1;
            DFS(tmp);
        }
        else {
            idx--;
            break;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        result.push_back(t);
    }
    chk[1] = 1;
    seq.push_back(1);
    DFS(1);

    for(int i = 0; i < n; i++) {
        if(seq[i] != result[i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}