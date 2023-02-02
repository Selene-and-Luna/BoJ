#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > conference; // end_time, start_time
    while(n--) {
        int start, end;
        cin >> start >> end;
        conference.push_back({end, start});
    }
    sort(conference.begin(), conference.end());

    vector<pair<int, int> >::iterator itr = conference.begin();
    int end_start_time = (*itr).first;
    int cnt = 1;
    while(++itr != conference.end())
        if(end_start_time <= (*itr).second) {
            end_start_time = (*itr).first;
            cnt++;
        }
    cout << cnt;
}