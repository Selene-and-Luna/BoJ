#include <iostream>
#include <set>
#include <vector>
using namespace std;
int k;
char ineq[10];

string min_num() {
    string num = "";
    set<int> s = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int idx = 0;
    char head = ineq[0];
    while(idx < k) {
        if(head == '<') {
            num += (char)(*s.begin() + 48);
            s.erase(*s.begin());
            head = ineq[++idx];
        }
        else {
            int cnt = 1;
            while(ineq[++idx] == '>')
                cnt++;
            head = ineq[idx];
            set<int>::iterator itr = s.begin();
            for(int i = 0; i < cnt; i++)
                itr++;
            vector<int> v;
            for(int i = 0; i < cnt; i++) {
                num += (char)(*itr + 48);
                v.push_back(*itr);
                itr--;
            }
            for(int t : v)
                s.erase(t);
        }
    }
    num += (char)(*s.begin() + 48);
    return num;
}

string max_num() {
    string num = "";
    set<int, greater<int> > s = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int idx = 0;
    char head = ineq[0];
    while(idx < k) {
        if(head == '>') {
            num += (char)(*s.begin() + 48);
            s.erase(*s.begin());
            head = ineq[++idx];
        }
        else {
            int cnt = 1;
            while(ineq[++idx] == '<')
                cnt++;
            head = ineq[idx];
            set<int>::iterator itr = s.begin();
            for(int i = 0; i < cnt; i++)
                itr++;
            vector<int> v;
            for(int i = 0; i < cnt; i++) {
                num += (char)(*itr + 48);
                v.push_back(*itr);
                itr--;
            }
            for(int t : v)
                s.erase(t);
        }
    }
    num += (char)(*s.begin() + 48);
    return num;
}

int main() {
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> ineq[i];
    cout << max_num() << '\n' << min_num();
}