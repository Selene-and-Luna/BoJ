#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int> > v; // num, idx
    for(int i = 1; i <= N; i++) {
        int t;
        std::cin >> t;
        v.push_back({t, i});
    }
    int maxnum = -1, idx = 0;
    std::stable_sort(v.begin(), v.end(), compare);
    for(std::pair<int, int> p : v) {
        if(p.second - idx > maxnum)
            maxnum = p.second - idx;
        // std::cout << p.second << ' ';
        idx++;
    }   
    std::cout << maxnum;
}