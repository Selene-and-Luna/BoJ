#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++)
            std::cout << ' ';
        for(int j = i * 2; j < 2 * n - 1; j++)
            std::cout << '*';
        std::cout << '\n';
    }
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < i; j++)
            std::cout << ' ';
        for(int j = i * 2; j < 2 * n - 1; j++)
            std::cout << '*';
        std::cout << '\n';
    }
}