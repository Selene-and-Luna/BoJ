#include <iostream>
using namespace std;

bool automata(string &s, int &idx, int status) {
    if(idx == s.size()) {
        if(!status || status == 5 || status == 6)
            return 1;
        else
            return 0;
    }

    switch(status) {
        case 0:
            if(s[idx] == '0')
                return automata(s, ++idx, 1);
            else
                return automata(s, ++idx, 2);
            break;
        case 1:
            if(s[idx] == '0')
                return 0;
            else
                return automata(s, ++idx, 0);
            break;
        case 2:
            if(s[idx] == '0')
                return automata(s, ++idx, 3);
            else
                return 0;
            break;
        case 3:
            if(s[idx] == '0')
                return automata(s, ++idx, 4);
            else
                return 0;
            break;
        case 4:
            if(s[idx] == '0')
                return automata(s, ++idx, 4);
            else
                return automata(s, ++idx, 5);
            break;
        case 5:
            if(s[idx] == '0')
                return automata(s, idx, 0);
            else
                return automata(s, ++idx, 6);
            break;
        case 6:
            if(s[idx] == '0') {
                if(idx + 1 < s.size() && s[idx + 1] == '0')
                    return automata(s, --idx, 0);
                else
                    return automata(s, idx, 0);
            }
            else
                return automata(s, ++idx, 6);
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int idx = 0;
        if(automata(s, idx, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}