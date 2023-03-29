#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;
priority_queue<int, vector<int>, greater<int> > pq;

bool compare(pii a, pii b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int h, o;
        cin >> h >> o;
        if(o < h)
            swap(o, h);
        v.push_back({h, o});
    }
    int d;
    cin >> d;
    int maxsize = 0;

    sort(v.begin(), v.end(), compare);

    for(pii p : v) {
        if(p.first + d >= p.second)
            pq.push(p.first);

        while(!pq.empty()) {
            if(pq.top() + d >= p.second)
                break;
            pq.pop();
        }

        // cout << maxsize << ' ';
        maxsize = max(maxsize, (int)pq.size());
    }

    cout << maxsize;

    return 0;
}