#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
vector<int> graph[50001]; // node
int depth[50001];
int N, max_level;
int ac[50001][19];

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// LCA
void make_tree(int child, int parent) {
    depth[child] = depth[parent] + 1;
    ac[child][0] = parent;

    for (int i = 1; i <= max_level; i++) {
        int tmp = ac[child][i - 1];
        ac[child][i] = ac[tmp][i - 1];
    }
    int len = graph[child].size();
    for (int i = 0; i < len; i++) {
        int there = graph[child][i];
        if (there != parent)
            make_tree(there, child);
    }
}

int lca(int &a, int &b) {
    if (depth[a] != depth[b]) {
        if (depth[a] > depth[b])
            swap(a, b);

        for (int i = max_level; i >= 0; i--) {
            if (depth[a] <= depth[ac[b][i]])
                b = ac[b][i];
        }
    }
 
    int lca = a;
    if (a != b) {
        for (int i = max_level; i >= 0; i--) {
            if (ac[a][i] != ac[b][i]) {
                a = ac[a][i];
                b = ac[b][i];
            }
            lca = ac[a][i];
        }
    }

    return lca;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M;
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    depth[0] = -1;
    max_level = (int)floor(log2(N));
    make_tree(1, 0);
    cin >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << '\n';
    }
}