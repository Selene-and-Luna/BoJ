#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    long long k;
    long long sum = 0;
    cin >> k;
    for(int j : v) {
        long long tmp = k;
        while(tmp) {
            tmp /= j;
            sum += tmp;
        }
    }

    cout << sum;
    return 0;
}