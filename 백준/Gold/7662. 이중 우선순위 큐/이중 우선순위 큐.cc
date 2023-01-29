#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        multiset<int, greater<int> > s;
        int k;
        cin >> k;
        while(k--) {
            char c;
            int n;
            cin >> c >> n;
            if(c == 'I')
                s.insert(n);
            else if(c == 'D') {
                if(s.empty())
                    continue;
                else if(n == 1) {
                    multiset<int>::iterator itr = s.find(*(s.begin()));
                    s.erase(itr);
                }
                else if(n == -1) {
                    multiset<int>::iterator itr = s.find((*(--s.end())));
                    s.erase(itr);
                }
            }
        }
        if(!s.empty())
            cout << *(s.begin()) << ' ' << *(--(s.end())) << '\n';
        else
            cout << "EMPTY\n";
    }
}