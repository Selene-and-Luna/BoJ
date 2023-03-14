#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
vector<pair<int, int> > graph[40001]; // node, dist
bool chk[40001];
int depth[40001], dist[40001][17], parent[40001][17];
int N;

void make_tree(int start, int level) {
    chk[start] = 1;
    depth[start] = level;

    for(pair<int ,int> p : graph[start]) {
        if(!chk[p.first]) {
            parent[p.first][0] = start;
            dist[p.first][0] = p.second;
            make_tree(p.first, level + 1);
        }
    }
}

void control() {
    for(int i = 1; i < 17; i++) {
        for(int node = 1; node <= N; node++) {
            int p = parent[node][i - 1]; // parent
            parent[node][i] = parent[p][i - 1];

            if(parent[p][i - 1]) 
                dist[node][i] = dist[node][i - 1] + dist[p][i - 1];
        }
    }
}

int lca(int &a, int &b) {
    if(depth[a] > depth[b])
        swap(a, b);

    int sum = 0;
    for(int i = 16; i >= 0; i--) {
        int tmp = pow(2, i);
        if(depth[b] - depth[a] >= tmp){
			sum += dist[b][i];
			b = parent[b][i];
		}
    }

    if(a == b)
        return sum;

    for(int i = 16; i >= 0; i--) {
        if(parent[a][i] != parent[b][i]) {
            sum += dist[a][i] + dist[b][i];
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return sum + dist[a][0] + dist[b][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M;
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int u, v, e;
        cin >> u >> v >> e;
        graph[u].push_back({v, e});
        graph[v].push_back({u, e});
    }
    
    make_tree(1, 0);
    control();

    cin >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}