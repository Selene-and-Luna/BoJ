#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i+1);
    }
    q.pop();
    while (q.size() > 1) {
        q.push(q.front());
        q.pop();
        q.pop();
    }
    cout << q.back();
}