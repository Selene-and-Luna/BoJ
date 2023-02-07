#include <iostream>
#include <vector>
int cnt;

std::vector<int> color(200001);
std::vector<std::vector<int> > graph(200001, std::vector<int>());

void DFS(int node, int parent) {
    for (int child : graph[node]) {
		if(child == parent) continue;
		if(color[node] != color[child])
            cnt++;
        DFS(child, node);
	}
}

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int N;
    std::cin >> N;
    for(int i = 1; i <= N; i++)
        std::cin >> color[i];
    
    for(int i = 1; i <= N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1, 0);
    if(color[1])
        cnt++;
    std::cout << cnt;

    return 0;
}