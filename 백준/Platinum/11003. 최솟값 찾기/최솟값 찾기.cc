#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l;
    vector<int> v;
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare > q;
    for(int i = 0; i < n; i++) {
        int idx = i - l + 1;
        q.push({v[i], i});
        while(q.top().second < idx)
            q.pop();
        cout << q.top().first << ' ';
    }
}