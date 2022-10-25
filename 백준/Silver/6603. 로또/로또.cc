#include <iostream>
int t;

void DFS(int idx, int r, int depth[], int arr[]);

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    while(std::cin >> t && t) {
        int arr[14], depth[6] = { 0, };
        for (int i = 0; i < t; i++) std::cin >> arr[i];
        DFS(0, 0, depth, arr);
        std::cout << '\n';
    }
    return 0;
}

void DFS(int idx, int r, int depth[], int arr[]) {
    if (r == 6) {
        for (int i = 0; i < r; i++) std::cout << depth[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int i = idx; i < t; i++) {
        depth[r] = arr[i];
        DFS(i + 1, r + 1, depth, arr);
    }
}