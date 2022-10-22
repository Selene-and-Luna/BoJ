#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int main()
{
    vector<vector<int>> pp;
    vector<int> tn;
    int n, m, t, num = 0;
    cin >> n >> m >> t;
    if (t != 0){
        for (int i = 0; i < t; i++) {
            int u;
            cin >> u;
            tn.pb(u);
        }
    }
    for (int i = 0; i < m; i++) {
        int r;
        cin >> r;
        vector<int> k;
        for (int j = 0; j < r; j++) {
            int u;
            cin >> u;
            k.pb(u);
        }
        pp.pb(k);
    }
    if (!tn.empty()) {
        for (int i = 0; i < m; i++) {
            for (auto h : pp) {
                bool l = 1;
                for (auto& u : h) {
                    for (auto& k : tn) {
                        if (u == k) {
                            l = 0;
                            break;
                        }
                    }
                    if (!l) {
                        for (auto& p : h)   tn.pb(p);
                        break;
                    }
                }
            }
        }
        for (auto h : pp) {
            bool l = 1;
            for (auto& u : h) {
                for (auto& k : tn) {
                    if (u == k) {
                        l = 0;
                        break;
                    }
                }
                if (!l)    break;
            }
            if (l)   num++;
        }
        cout << num;
    }
    else    cout << pp.size();
}