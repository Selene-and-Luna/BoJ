#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int> > dragon; // power, index
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        dragon.push_back({t, i});
    }
    sort(dragon.begin(), dragon.end(), greater<>());
    int idx = -1;
    for(int i = 0; i < dragon.size() - 1; i++) {
        if(dragon[i].first - dragon[i + 1].first > m) {
            idx = i + 1;
            break;
        }
    }
    if((idx != -1 && n < 4) || (idx > -1 && idx < 4 && n > 3)){
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    if(idx == -1) {
        for(auto k : dragon)
            cout << k.second << ' ';
        return 0;
    }
    vector<int> abyss;
    abyss.push_back(dragon[0].second);
    abyss.push_back(dragon[1].second);
    for(int i = idx; i < dragon.size(); i++)
        abyss.push_back(dragon[i].second);
    for(int i = 2; i < idx; i++)
        abyss.push_back(dragon[i].second);
    for(int k : abyss)
        cout << k << ' ';
    return 0;
}