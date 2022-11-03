#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > quad_tree;

void comp(int ystart, int yend, int xstart, int xend) {
    int val = quad_tree[ystart][xstart];
    int ymid = (ystart + yend) / 2 + 1;
    int xmid = (xstart + xend) / 2 + 1;
    for(int i = ystart; i <= yend; i++) {
        for(int j = xstart; j <= xend; j++) {
            if (quad_tree[i][j] != val) {
                cout << '(';
                comp(ystart, ymid - 1, xstart, xmid - 1);
                comp(ystart, ymid - 1, xmid, xend);
                comp(ymid, yend, xstart, xmid - 1);
                comp(ymid, yend, xmid, xend);
                cout << ')';
                return;
            }
        }
    }
    cout << val;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> tmp;
        string s;
        cin >> s;
        for(int j = 0; j < N; j++) {
            int t = (int)s[j] - '0';
            tmp.push_back(t);
        }
        quad_tree.push_back(tmp);
    }
    comp(0, N - 1, 0, N - 1);
}