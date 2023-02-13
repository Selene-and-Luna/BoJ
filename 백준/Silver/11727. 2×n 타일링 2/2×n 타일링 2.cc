#include <iostream>
using namespace std;
long long square[1001];

int main() {
    int n;
    cin >> n;
    square[1] = 1;
    square[2] = 3;
    for(int i = 3; i<=n; i++){
        square[i] = (square[i - 1] + 2 * square[i - 2]) % 10007;
    }
    cout << square[n];
}