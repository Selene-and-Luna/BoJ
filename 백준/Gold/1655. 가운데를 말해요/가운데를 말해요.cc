#include <iostream>
#include <queue>
#define pq std::priority_queue
using namespace std;

void set_num1(pq<int> &q1, pq<int, vector<int>, greater<int> > &q2, int &num) { // push q, pop q, mid
    q1.push(num);
    num = q2.top();
    q2.pop();
    return;
}

void set_num2(pq<int, vector<int>, greater<int> > &q1, pq<int> &q2, int &num) { // push q, pop q, mid
    q1.push(num);

    num = q2.top();
    q2.pop();
    return;
}

void bool_judg(int &i, int &t, int &mid, pq<int> &min_heap, pq<int, vector<int>, greater<int> > &max_heap) {
    if(i % 2) {
        if(mid <= t) {
            max_heap.push(t);
        }
        else { // mid > t
            if(min_heap.empty()) {
                max_heap.push(mid);
                mid = t;
            }
            else {
                max_heap.push(mid);
                min_heap.push(t);
                mid = min_heap.top();
                min_heap.pop();
            }
        }   
        // cout << min_heap.size() << ' ' << max_heap.size() << '\n';
    }
    else {
        if(mid > t)
            min_heap.push(t);
        else // mid <= t
            max_heap.push(t);
        
        // cout << min_heap.size() << 'n' << max_heap.size() << '\n';
        if(min_heap.size() > max_heap.size()) 
            set_num2(max_heap, min_heap, mid);
        else if(min_heap.size() < max_heap.size())
            set_num1(min_heap, max_heap, mid);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pq<int> min_heap; // 작은거
    pq<int, vector<int>, greater<int> > max_heap; // 큰거
    int mid;
    cin >> mid;
    cout << mid << '\n';
    for(int i = 1; i < n; i++){ 
        int t;
        cin >> t;
        bool_judg(i, t, mid, min_heap, max_heap);
        cout << mid << '\n';
    }
}