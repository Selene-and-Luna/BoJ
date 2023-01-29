#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
int n, m, b;

pair<int, int> bruteforce(int minh, int maxh) {
    int mintime = 2147483647, maxheight = -1;
    for(int i = minh; i <= maxh; i++) {
        int time = 0, block = b;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                int tmp = abs(v[j][k] - i);
                if(v[j][k] > i) {
                    block += tmp;
                    time += tmp * 2;
                }
                else if(v[j][k] < i) {
                    block -= tmp;
                    time += tmp;
                }
            }
        }

        if(block < 0)
            continue;
        else if(time == mintime) {
            maxheight = max(i, maxheight);
        }
        else if(time < mintime) {
            mintime = time;
            maxheight = i;
        }
    }

    return {mintime, maxheight};
}

int main() {
    cin >> n >> m >> b;
    int minh = 64000001, maxh = -1;
    for(int i = 0; i < n; i++) {
        vector<int> tmp;
        for(int j = 0; j < m; j++) {
            int t;
            cin >> t;
            tmp.push_back(t);
            minh = min(t, minh);
            maxh = max(t, maxh);
        }
        v.push_back(tmp);
    }

    pair<int, int> a = bruteforce(minh, maxh);
    cout << a.first << ' ' << a.second;
}