#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, s, sum = 0;
    vector<int> v(100003);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
        v[i] = t;
    }

    if(sum < s) {
        cout << 0;
        return 0;
    }

    int begin = 0, end = 0, s_size = 1, min_size = 100003;
    long long partial_sum = v[0];
    while(end < n) {
        if(partial_sum >= s) {
            partial_sum -= v.at(begin++);
            // cout << partial_sum << ' ';
            min_size = min(min_size, s_size--);
        }

        else {
            s_size++;
            partial_sum += v.at(++end);
        }
    }

    cout << min_size;
    return 0;
}