#include <iostream>
#include <vector>
using namespace std;
long long input[100001];

class segTree {
private:
    int segsize;
    long long *tree;
public:
    segTree(int n) {
        this->segsize = n * 4;
        tree = new long long[n * 4];
    }

    long long init(long long arr[], int start, int end, int node);
    void update(long long val, int node, int start, int end, int idx);
    long long min(int node, int start, int end, int left, int right);
};

long long segTree::init(long long arr[], int start, int end, int node) {
    if(start == end)
        return tree[node] = arr[start];

    long long left, right;
    left = init(arr, start, (start + end) / 2, node * 2);
    right = init(arr, (start + end) / 2 + 1, end, node * 2 + 1);
    return tree[node] = std::min(left, right);
}

void segTree::update(long long val, int node, int start, int end, int idx) {
    if(idx < start || idx > end)
        return;

    tree[node] = std::min(tree[node], val);

    if(start != end) {
        update(val, node*2, start, (start+end)/2, idx);
        update(val, node*2+1, (start+end)/2+1, end, idx);
    }
}

long long segTree::min(int node, int start, int end, int left, int right) {
    if(left > end || right < start)
        return 0x7fffffff;

    if(left <= start && end <= right)
        return tree[node];

    long long leftmin = this->min(node*2, start, (start+end)/2, left, right);
    long long rightmin = this->min(node*2+1, (start+end)/2+1, end, left, right);
    return std::min(leftmin, rightmin);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    segTree seg(n);
    for (int i = 1; i <= n; i++)
        cin >> input[i];

    seg.init(input, 1, n, 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << seg.min(1, 1, n, a, b) << '\n';
    }
}