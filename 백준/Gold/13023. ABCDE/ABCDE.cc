#include <iostream>
#include <vector>
#include <cstring>
std::vector<int> v[2001];
bool chk[2001];
bool result;

void DFS(int start, int cnt) {
    chk[start] = 1;
    if(cnt == 5) {
        result = 1;
        return;
    }
    for(int k : v[start])
        if(!result && !chk[k])
            DFS(k, cnt + 1);
    chk[start] = 0;
}

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int N, M;
    std::cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < N; i++) {
        if(result) {
            std::cout << result;
            return 0;
        }
        DFS(i, 1);
        memset(chk, 0, 2001);
    }
    std::cout << result;
    return 0;
}