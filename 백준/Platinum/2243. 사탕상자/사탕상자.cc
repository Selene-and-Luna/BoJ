#include <bits/stdc++.h>
using namespace std;
long long arr[1000004];

// 숫자용; 문자용 사용금지
template <typename T>
class segTree {
private:
    std::vector<T> tree;
    int segsize;
public:
    segTree(int n) {
        this->segsize = (n + 1) * 4;
        tree.resize(segsize);
    }

    // T init(T arr[], int start, int end, int node);
    void update(T val, int node, int start, int end, int idx);
    T query(int node, int start, int end, int val);
};

template <typename T>
void segTree<T>::update(T val, int node, int start, int end, int idx) {
    if(idx < start || idx > end)
        return;

    tree[node] += val;

    if(start != end) {
        update(val, node * 2, start, (start + end) / 2, idx);
        update(val, node * 2 + 1, (start + end) / 2 + 1, end, idx);
    }
}

template <typename T>
T segTree<T>::query(int node, int start, int end, int val) {
    if(start == end)
        return start;

    if(tree[node * 2] < val)
        return query(node * 2 + 1, (start + end) / 2 + 1, end, val - tree[node * 2]);
    else
        return query(node * 2, start, (start + end) / 2, val);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int MAX = 1'000'001;
    int n;
    cin >> n;
    segTree<long long> seg(MAX);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            cin >> b;
            int idx = seg.query(1, 1, MAX - 1, b);
            cout << idx << '\n';
            arr[idx]--;
            seg.update(-1, 1, 1, MAX - 1, idx);
        }
        else {
            long long b, c;
            cin >> b >> c;
            arr[b] += c;
            seg.update(c, 1, 1, MAX - 1, b);
        }
    }
}