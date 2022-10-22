#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void fibonacci(int n) {
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(0, 1));
    if (n == 0) {
        cout << 1 << ' ' << 0 << '\n';
        return;
    }
    else if (n == 1) {
        cout << 0 << ' ' << 1 << '\n';
        return;
    }
    for (int i = 1; i < n; i++) {
        arr.push_back(make_pair(arr[i - 1].second, arr[i - 1].first + arr[i - 1].second));
    }
    cout << arr[n - 1].first << ' ' << arr[n - 1].second << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        fibonacci(t);
    }
}