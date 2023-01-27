#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> r;

int bin_search(int start, int end, int f) {
    int mid = (start + end) / 2;
    if(r[mid] == f)    return mid;
    else if(r[mid] > f)
        return bin_search(start, mid, f);
    else
        return bin_search(mid + 1, end, f);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v;
    set<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
        s.insert(t);
    }
    for(int k : s)
        r.push_back(k);
    for(int k : v)
        cout << bin_search(0, r.size() - 1, k) << ' ';
}