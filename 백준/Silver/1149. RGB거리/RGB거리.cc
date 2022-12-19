#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int> > v;
//Red-Green-Blue

int DP();

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> tmp;
        int r, g, b;
        cin >> r >> g >> b;
        tmp.push_back(r);
        tmp.push_back(g);
        tmp.push_back(b);
        v.push_back(tmp);
    }

    cout << DP();
}

int DP() {
    int arr[1001][3];
    int idx = 1;
    arr[0][0] = v[0][0], arr[0][1] = v[0][1], arr[0][2] = v[0][2];
    while(idx < v.size()) {
        arr[idx][0] = min(arr[idx - 1][1], arr[idx - 1][2]) + v[idx][0];
        arr[idx][1] = min(arr[idx - 1][0], arr[idx - 1][2]) + v[idx][1];
        arr[idx][2] = min(arr[idx - 1][0], arr[idx - 1][1]) + v[idx][2];
        idx++;
    }
    idx--;
    return min(arr[idx][0], min(arr[idx][1], arr[idx][2]));
    // if(price == 0)
    //     return min(DP(idx + 1, 1), DP(idx + 1, 2)) + v[idx][price];
    // else if(price == 1)
    //     return min(DP(idx + 1, 0), DP(idx + 1, 2)) + v[idx][price];
    // else
    //     return min(DP(idx + 1, 0), DP(idx + 1, 1)) + v[idx][price];
}