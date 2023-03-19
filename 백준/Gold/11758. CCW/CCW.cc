#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main(int argc, char **argv) {
    pii p1, p2, p3;
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
    pii v1, v2;
    v1 = {p2.first - p1.first, p2.second - p1.second}, v2 = {p3.first - p2.first, p3.second - p2.second};
    int ccw = v1.first * v2.second - v1.second * v2.first;
    if(!ccw)
        cout << 0;
    else if(ccw > 0)
        cout << 1;
    else
        cout << -1;
}