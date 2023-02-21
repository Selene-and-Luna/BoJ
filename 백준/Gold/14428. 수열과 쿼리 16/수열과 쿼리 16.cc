#include <iostream>
using namespace std;
long long arr[100002];
long long tree[4 * 100001]; // value, idx

long long set_tree(int start, int end, int node) {
    if(start == end)
        return tree[node] = start;

    int mid = (start + end) / 2;

	long long left = set_tree(start, mid, node * 2);
	long long right = set_tree(mid + 1, end, node * 2 + 1);
	if (arr[left] == arr[right]) {
		if (left < right)
			return tree[node] = left;
		else
			return tree[node] = right;
    }
	if (arr[left] < arr[right]) 
		return tree[node] = left;
	else
		return tree[node] = right;
}

long long query(int start, int end, int right, int left, int node) {
    if(left > end || right < start)
        return -1;
    else if(right >= end && left <= start)
        return tree[node];

    int mid = (start + end) / 2;
    long long left_ = query(start, mid, right, left, node * 2);
    long long right_ = query(mid + 1, end, right, left, node * 2 + 1);

    if(left_ == -1)
        return right_;
    else if(right_ == -1)
        return left_;
    
	if (arr[left_] == arr[right_]) {
		if (left_ < right_)
			return left_;
		else
			return right_;
    }
    
	if (arr[left_] < arr[right_]) 
		return left_;
	else
		return right_;
}

long long update(int start, int end, int idx, int node) {
    if(start > idx || end < idx)
        return tree[node];

    if(start == end)
        return tree[node];

    int mid = (start + end) / 2;
    long long left = update(start, mid, idx, node * 2);
    long long right = update(mid + 1, end, idx, node * 2 + 1);

    if(left == -1)
        return tree[node] = right;
    else if(right == -1)
        return tree[node] = left;
    
	if (arr[left] == arr[right]) {
		if (left < right)
			return tree[node] = left;
		// else
		// 	return tree[node] = right;
    }
    
	if (arr[left] < arr[right]) 
		return tree[node] = left;
	else
		return tree[node] = right;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> m;
    set_tree(1, n, 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(a == 1) {
            arr[b] = c;
            update(1, n, b, 1);
        }
        else if(a == 2) 
            cout << query(1, n, c, b, 1) << '\n';
    }
}